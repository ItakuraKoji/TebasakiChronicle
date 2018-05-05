#include "Enemy.h"

//�R���X�g���N�^
Enemy::Enemy(EnemyType* cpyet, const K_Math::Vector3& setPos) :
	nowMoveOrder(0),
	nowPatternOrder(0),
	beforeMoveOrder(0),
	beforePatternOrder(0)
{
	SetEnemyType(cpyet, setPos);
}

//�f�X�g���N�^
Enemy::~Enemy()
{
	delete eController;
}

//-----------------------------------------------------------------------------
//�G����ݒ�
void Enemy::SetEnemyType(EnemyType* cpyet, const K_Math::Vector3& setPos)
{
	eController = new EnemyController(cpyet->GetEnemyMoveSet());
	//gameObject.GetStatus()->GetLife() = cpyet->GetMaxLife();
	gameObject.GetStatus()->SetStatusData(	Status::State::Walk,
											setPos,
											K_Math::Vector3(0, 0, 0),
											K_Math::Vector3(1, 1, 1),
											Status::Direction::Right,
											cpyet->GetHitDamage());

	//�A�j���[�V�����ƕ\���摜�̐ݒ�
	ImageManager* im = gameObject.GetImage();
	im = new ImageManager(cpyet->GetTextureName(), cpyet->GetTexture(), false);
	im->ChangeAnimationPattern(nowMoveOrder);
	im->ChangeCharaChip(eController->GetNowCharaChip(nowPatternOrder));

	//�R���W�����̐ݒ�
	collisionManager.SetBaseCollisionData(cpyet->GetBaseCollisionData());			//�x�[�X�R���W����
	collisionManager.SetSubCollisionData(cpyet->GetRecieveDamageCollisionData());	//��_���[�W�p�R���W����
	collisionManager.SetSubCollisionData(cpyet->GetFieldofviewCollisionData());		//���E�p�R���W����
	collisionManager.SetSubCollisionData(cpyet->GetAttackAreaCollisionData());		//�U������J�ڗp�R���W����
	collisionManager.SetSubCollisionData(cpyet->GetCheckFootCollisionData());		//��������p�R���W����
	collisionManager.SetSubCollisionData(cpyet->GetCheckHeadCollisionData());		//���㔻��p�R���W����
	collisionManager.SetSubCollisionData(cpyet->GetRecieveCameraCollisionData());	//��J�����K���p�R���W����

	//�^�O�̐ݒ�
	skillAndChip.pos = &gameObject.GetStatus()->GetPos();
	skillAndChip.textureName = &gameObject.GetImage()->GetTextureName();
	skillAndChip.skillId = &eController->GetSkillId();
	SetTugData();
}

//-----------------------------------------------------------------------------
//�X�V
void Enemy::Update()
{
	K_Math::Vector3 moveVec = { 0, 0, 0 };	//��moveVec��Status�N���X�̃����o�ϐ�

	//eController->Move(nowMoveOrder, nowPatternOrder, moveVec);

	AnimationUpdate();

	collisionManager.MoveBaseCollision(moveVec, gameObject.GetStatus()->GetDirection(), true);

	SetTugData();
}

//-----------------------------------------------------------------------------
//�^�O�����i�[
void Enemy::SetTugData()
{
	skillAndChip.nowCharaChip = gameObject.GetImage()->GetNowAnimationCharaChip();

	for (int i = 0; i < 5; ++i)
	{
		collisionManager.SetSubCollisionTug(i, gameObject.GetStatus());
	}
	collisionManager.SetSubCollisionTug(5, &skillAndChip);
}

//-----------------------------------------------------------------------------
//�`��A�A�j���[�V�����̍X�V
void Enemy::AnimationUpdate()
{
	gameObject.GetImage()->Animation();

	//���݂̓���ƑO�̓��삪�قȂ�ꍇ�A�j���[�V�����p�^�[����ύX����
	if (beforeMoveOrder != nowMoveOrder)
	{
		gameObject.GetImage()->ChangeAnimationPattern(nowMoveOrder);
	}
	beforeMoveOrder = nowMoveOrder;

	//���݂̓���p�^�[���ƑO�̃p�^�[�����قȂ�ꍇ�L�����`�b�v��ύX����
	if (beforePatternOrder != nowPatternOrder)
	{
		gameObject.GetImage()->ChangeCharaChip(eController->GetNowCharaChip(nowPatternOrder));
	}
	beforePatternOrder = nowPatternOrder;
}

//-----------------------------------------------------------------------------
//�`��
void Enemy::Draw()
{
	gameObject.GetImage()->ImageDraw3D(	gameObject.GetStatus()->GetPos(),
										gameObject.GetStatus()->GetAngle(),
										gameObject.GetStatus()->GetScale());
}