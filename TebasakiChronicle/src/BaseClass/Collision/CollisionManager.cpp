#include "CollisionManager.h"

//�R���X�g���N�^
CollisionManager::CollisionManager() :
	baseCollision(nullptr),
	basePosition(K_Math::Vector3(0, 0, 0)){}

//�f�X�g���N�^
CollisionManager::~CollisionManager()
{
	for (auto it : subCollision)
	{
		CC::RemoveCollision(&it->collision);
		delete it;
	}
	CC::RemoveCollision(&baseCollision);
}

//-----------------------------------------------------------------------------
//�x�[�X�R���W�������쐬����
void CollisionManager::CreateBaseCollisionData(K_Physics::CollisionShape* cs, const K_Math::Vector3& pos, const K_Math::Vector3& rot, bool isJudge)
{
	if (baseCollision != nullptr)
		return;

	if (isJudge == true)
	{
		//�n�`�Ƃ̂߂荞�ݏ������s��
		baseCollision = CC::CreateCollisionObject(cs, false, 1, 0, pos, rot);
	}
	else
	{
		//�������s��Ȃ�
		baseCollision = CC::CreateCollisionObject(cs, false, 1, 0, pos, rot);
	}
}
//-----------------------------------------------------------------------------
//�x�[�X�R���W������ݒ肷��
void CollisionManager::SetBaseCollisionData(K_Physics::CollisionData* cd, const K_Math::Vector3& pos)
{
	if (baseCollision != nullptr)
		return;

	baseCollision = cd;
	baseCollision->SetCollisionPosition(pos);
}

//-----------------------------------------------------------------------------
//�T�u�R���W�������쐬����
void CollisionManager::CreateSubCollisionData(K_Physics::CollisionShape* cs, int myselfMask, int giveMask, K_Math::Vector3& pos)
{
	if (baseCollision == nullptr)
		return;

	subCollision.emplace_back(new Sub(CC::CreateCollisionObject(cs, true, myselfMask, giveMask, pos + baseCollision->GetCollisionPosition()), pos));
}
//-----------------------------------------------------------------------------
//�T�u�R���W������ݒ肷��
void CollisionManager::SetSubCollisionData(K_Physics::CollisionData* cd)
{
	if (baseCollision == nullptr)
		return;

	K_Math::Vector3* ccd = &cd->GetCollisionPosition();
	subCollision.emplace_back(new Sub(cd, *ccd));
	subCollision.back()->collision->SetCollisionPosition(*ccd + baseCollision->GetCollisionPosition());
}

//-----------------------------------------------------------------------------
//�T�u�R���W�����̃^�O��ݒ肷��
void CollisionManager::SetSubCollisionTug(int subNum, void* tug)
{
	subCollision[subNum]->collision->tag.userData = tug;
}

//-----------------------------------------------------------------------------
//�x�[�X�R���W�����𓮂����A�t�����ăT�u�̍��W��ݒ肷��
void CollisionManager::MoveBaseCollision(K_Math::Vector3& moveVec, int direction, bool isLightness)
{
	if (isLightness == true)
	{
		//�y��&��G�c
		CC::MoveCharacterDiscrete(baseCollision, moveVec);
	}
	else
	{
		//�d��&���m
		CC::MoveCharacter(baseCollision, moveVec);
	}

	//���W���擾
	basePosition = baseCollision->GetCollisionPosition();

	//�x�[�X�R���W��������Ɋe�T�u�R���W�����̈ʒu��ݒ�
	SetSubCollisionPos(direction);
}

//-----------------------------------------------------------------------------
//�x�[�X�R���W�����̍��W����ɃT�u�R���W�����̈ʒu��ݒ肷��
void CollisionManager::SetSubCollisionPos(int angle)
{
	for (auto it : subCollision)
	{
		K_Math::Vector3 setPos = it->relativePos;

		if (angle == 180)	//���������������ꍇ�ʒu�𔽓]
			setPos.x() *= -1.f;

		it->collision->SetCollisionPosition(setPos + baseCollision->GetCollisionPosition());
	}
}

//-----------------------------------------------------------------------------
//�w�肵���T�u�R���W�����̎󂯎�����^�O�̓��AuserData�݂̂𒊏o���ĕԂ�
std::vector<void*> CollisionManager::GetConflictionObjectsUserData(int subNum)
{
	std::vector<void*> userData;
	std::vector<K_Physics::CollisionTag*> fco = CC::FindConfrictionObjects(subCollision[subNum]->collision);
	for (auto it : fco)
	{
		//tagIndex�����̃R���W�����Ɠ���
		if (it->tagIndex == subCollision[subNum]->collision->tag.tagIndex)
		{
			continue;
		}
		userData.emplace_back(it->userData);
	}
	return userData;
}

//-----------------------------------------------------------------------------
//�x�[�X�R���W�����̍��W��Ԃ�
K_Math::Vector3& CollisionManager::GetBaseCollisionObjectPosition()
{
	return basePosition;
}