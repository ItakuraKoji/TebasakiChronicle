#include "Enemy.h"

//�R���X�g���N�^
Enemy::Enemy(EnemyType* cpyet, const K_Math::Vector3& setPos, const Status::Direction& direction) :
	nowMoveOrder(0),
	nowPatternOrder(0),
	beforeMoveOrder(0),
	beforePatternOrder(0)
{
	SetEnemyType(cpyet, setPos, direction);
}

//�f�X�g���N�^
Enemy::~Enemy()
{
	delete eController;
}

//-----------------------------------------------------------------------------
//�G����ݒ�
void Enemy::SetEnemyType(EnemyType* cpyet, const K_Math::Vector3& setPos, const Status::Direction& direction)
{
	eController = new EnemyController(cpyet->GetEnemyMoveSet());
	gameObject.GetStatus().SetStatusData(	Status::State::Active,
											setPos,
											K_Math::Vector3(0, 0, 0),
											K_Math::Vector3(1, 1, 1),
											direction,
											cpyet->GetHitDamage(),
											cpyet->GetMaxLife());

	gameObject.GetMove().SetAddVec(cpyet->GetMoveSpeed());

	//�A�j���[�V�����ƕ\���摜�̐ݒ�
	gameObject.SetImage(cpyet->GetTextureName(), cpyet->GetTexture(), false);
	gameObject.GetImage().ChangeAnimationPattern(nowMoveOrder);
	gameObject.GetImage().ChangeCharaChip(eController->GetNowCharaChip(nowPatternOrder));

	//�R���W�����̐ݒ�
	collisionManager.SetBaseCollisionData(cpyet->GetBaseCollisionData(), setPos);	//�x�[�X�R���W����
	collisionManager.SetSubCollisionData(cpyet->GetRecieveDamageCollisionData());	//0 ��_���[�W�p�R���W����
	collisionManager.SetSubCollisionData(cpyet->GetFieldofviewCollisionData());		//1 ���E�p�R���W����
	collisionManager.SetSubCollisionData(cpyet->GetAttackAreaCollisionData());		//2 �U������J�ڗp�R���W����
	collisionManager.SetSubCollisionData(cpyet->GetCheckFootCollisionData());		//3 ��������p�R���W����
	collisionManager.SetSubCollisionData(cpyet->GetCheckHeadCollisionData());		//4 ���㔻��p�R���W����
	collisionManager.SetSubCollisionData(cpyet->GetRecieveCameraCollisionData());	//5 ��J�����K���p�R���W����

	//�^�O�̐ݒ�
	skillAndChip.pos = &gameObject.GetStatus().GetPos();
	skillAndChip.textureName = &gameObject.GetImage().GetTextureName();
	skillAndChip.skillId = &eController->GetSkillId();
	for (int i = 0; i < 5; ++i)
	{
		collisionManager.SetSubCollisionTug(i, &gameObject.GetStatus());
	}
	SetTugData();
}

//-----------------------------------------------------------------------------
//�X�V
bool Enemy::Update()
{
	gameObject.GetMove().GetMoveVec() = K_Math::Vector3(0, 0, 0);
	eController->EMove(nowMoveOrder, nowPatternOrder, collisionManager, gameObject.GetStatus(), gameObject.GetMove());

	AnimationUpdate();

	//�R���W�����𓮂���
	collisionManager.MoveBaseCollision(gameObject.GetMove().GetMoveVec(), gameObject.GetStatus().GetDirection(), true);
	gameObject.GetPos() = collisionManager.GetBaseCollisionObjectPosition();

	SetTugData();

	return false;
}

//-----------------------------------------------------------------------------
//�^�O�����i�[
void Enemy::SetTugData()
{
	skillAndChip.nowCharaChip = gameObject.GetImage().GetNowAnimationCharaChip();
	collisionManager.SetSubCollisionTug(5, &skillAndChip);
}

//-----------------------------------------------------------------------------
//�`��A�A�j���[�V�����̍X�V
void Enemy::AnimationUpdate()
{
	gameObject.GetImage().Animation();

	//���݂̓���ƑO�̓��삪�قȂ�ꍇ�A�j���[�V�����p�^�[����ύX����
	if (beforeMoveOrder != nowMoveOrder)
	{
		gameObject.GetImage().ChangeAnimationPattern(nowMoveOrder);
	}
	beforeMoveOrder = nowMoveOrder;

	//���݂̓���p�^�[���ƑO�̃p�^�[�����قȂ�ꍇ�L�����`�b�v��ύX����
	if (beforePatternOrder != nowPatternOrder)
	{
		gameObject.GetImage().ChangeCharaChip(eController->GetNowCharaChip(nowPatternOrder));
	}
	beforePatternOrder = nowPatternOrder;
}

//-----------------------------------------------------------------------------
//�`��
void Enemy::Draw()
{
	gameObject.GetImage().ImageDraw3D(	gameObject.GetStatus().GetPos(),
										gameObject.GetStatus().GetAngle(),
										gameObject.GetStatus().GetScale(),
										gameObject.GetStatus().GetDirection());
}