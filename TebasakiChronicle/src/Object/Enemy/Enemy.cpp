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
	delete imgManager;
}

//-----------------------------------------------------------------------------
//�G����ݒ�
void Enemy::SetEnemyType(EnemyType* cpyet, const K_Math::Vector3& setPos)
{
	eController = new EnemyController(cpyet->emSet);
	life = cpyet->maxLife;
	pos = setPos;
	angle = { 0, 0, 0 };
	scale = { 1, 1, 1 };
	moveVec = { 0, 0, 0 };
	cData = CM::CreateCollisionObject(cpyet->cShape, true, 1, pos, angle);
	imgManager = new ImageManager(cpyet->texture, false);
	imgManager->ChangeAnimationPattern(nowMoveOrder);
	imgManager->ChangeCharaChip(eController->GetNowCharaChip(nowPatternOrder));
}

//-----------------------------------------------------------------------------
//�X�V
void Enemy::Update()
{
	moveVec = { 0, 0, 0 };	//���̏����̓R���W�����ōs��

	eController->Move(nowMoveOrder, nowPatternOrder, moveVec);
	imgManager->Animation();

	//���݂̓���ƑO�̓��삪�قȂ�ꍇ�A�j���[�V�����p�^�[����ύX����
	if (beforeMoveOrder != nowMoveOrder)
	{
		imgManager->ChangeAnimationPattern(nowMoveOrder);
	}
	beforeMoveOrder = nowMoveOrder;

	//���݂̓���p�^�[���ƑO�̃p�^�[�����قȂ�ꍇ�L�����`�b�v��ύX����
	if (beforePatternOrder != nowPatternOrder)
	{
		imgManager->ChangeCharaChip(eController->GetNowCharaChip(nowPatternOrder));
	}
	beforePatternOrder = nowPatternOrder;

	pos += moveVec; //���̏����̓R���W�����ōs��
}

//-----------------------------------------------------------------------------
//�`��
void Enemy::Draw()
{
	imgManager->ImageDraw3D(pos, angle, scale);
}