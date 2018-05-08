#include "TemporaryCollisionManager.h"

//�R���W�����̌`������Ǘ������Ȃ�
TemporaryCollisionManager::TemporaryCollisionManager() : cShape(nullptr) {}

//�R���W�����̌`������Ǘ�������
TemporaryCollisionManager::TemporaryCollisionManager(K_Physics::CollisionShape* shape) : cShape(shape) {}

//�f�X�g���N�^
TemporaryCollisionManager::~TemporaryCollisionManager()
{
	if (cShape != nullptr)
	{
		CC::RemoveCollisionShape(&cShape);
	}
	for (auto it : tempCollision)
	{
		delete it;
	}
}

//-----------------------------------------------------------------------------
//�R���W�����𐶐�����
void TemporaryCollisionManager::CreateTemporaryCollision(
	K_Physics::CollisionShape*	shape,
	CollisionMask&				mmask,
	CollisionMask&				gmask,
	K_Math::Vector3&			setpos,
	K_Math::Vector3&			movevec,
	Status::Direction&			dir,
	int							damage,
	int							deletetime,
	bool						ishitground,
	bool						doground)
{
	tempCollision.emplace_back(new TemporaryCollision(shape, mmask, gmask, setpos, movevec, dir, damage, deletetime, ishitground, doground));
}

//-----------------------------------------------------------------------------
//�}�l�[�W���ۗ̕L����R���W�����`���񂩂�R���W�����𐶐�����
void TemporaryCollisionManager::CreateTempCollisionUseSelfShape(
	CollisionMask&				mmask,
	CollisionMask&				gmask,
	K_Math::Vector3&			setpos,
	K_Math::Vector3&			movevec,
	Status::Direction&			dir,
	int							damage,
	int							deletetime,
	bool						ishitground,
	bool						doground)
{
	K_Physics::CollisionData* basecd;
	if (doground == true)
	{
		basecd = CC::CreateCollisionObject(cShape, false, CollisionMask::Non, CollisionMask::Ground);
	}
	else
	{
		basecd = CC::CreateCollisionObject(cShape, true, CollisionMask::Ground, CollisionMask::Non);
	}
	tempCollision.emplace_back(new TemporaryCollision(	basecd,
														CC::CreateCollisionObject(cShape, true, mmask, gmask),
														setpos,
														movevec,
														dir,
														damage,
														deletetime,
														ishitground));
}

//-----------------------------------------------------------------------------
//���������R���W�����Ƀe�N�X�`����ݒ肷��
void TemporaryCollisionManager::SetAnimationCharaChip(
	std::string&			texName,
	K_Graphics::Texture*	texture,
	K_Math::Box2D&			src,
	int						sheet,
	float					spd,
	bool					isroop)
{
	tempCollision.back()->SetImageManagerAndCharaChip(texName, texture, src, sheet, spd, isroop);
}

//-----------------------------------------------------------------------------
//�R���W�����̍X�V���s��
//�R���W����������ŗv�����������ꍇ���ł�����
void TemporaryCollisionManager::Update()
{
	for (auto it = tempCollision.begin(); it != tempCollision.end();)
	{
		if ((*it)->Update())
		{
			delete (*it);
			tempCollision.erase(it);
		}
		else
		{
			++it;
		}
	}
}

//-----------------------------------------------------------------------------
//�R���W�����̕`����s��
void TemporaryCollisionManager::Render()
{
	for (auto it : tempCollision)
	{
		it->Render();
	}
}