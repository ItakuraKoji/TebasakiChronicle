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

	imgManager = new ImageManager(cpyet->textureName, cpyet->texture, false);
	imgManager->ChangeAnimationPattern(nowMoveOrder);
	imgManager->ChangeCharaChip(eController->GetNowCharaChip(nowPatternOrder));

	cData = CC::CreateCollisionObject(cpyet->cShape, true, 1, 0, pos, angle);

	skillAndChip.skillId = eController->GetSkillId();
	skillAndChip.textureName = &imgManager->textureName;
	skillAndChip.nowCharaChip = imgManager->charaChip[nowPatternOrder];
}

//-----------------------------------------------------------------------------
//�X�V
void Enemy::Update()
{
	moveVec = { 0, 0, 0 };	//�����̏����̓R���W�����ōs��

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

	pos += moveVec; //�����̏����̓R���W�����ōs��

	SetSkillData();
}

//-----------------------------------------------------------------------------
//�X�L�������i�[
void Enemy::SetSkillData()
{
	skillAndChip.skillId = eController->GetSkillId();
	skillAndChip.nowCharaChip = imgManager->charaChip[nowPatternOrder];
}


//-----------------------------------------------------------------------------
//�`��
void Enemy::Draw()
{
	imgManager->ImageDraw3D(pos, angle, scale);
}