#pragma once
#include "../../../BaseClass/Collision/CollisionManager.h"

//����p�^�[���J�ڂ̊��N���X
class EnemyMoveTransition
{
public:
	EnemyMoveTransition();
	virtual ~EnemyMoveTransition();

	virtual bool Transition(CollisionManager& cm, Status& status) = 0;
};

//�������d������ꍇ�A�p�^�[���ԍ��̎Ⴂ�ق����D�悳���

//-----------------------------------------------
//0�F�J�ڂ��Ȃ�
class ETransition_NotTrans : public EnemyMoveTransition
{
public:
	bool Transition(CollisionManager& cm, Status& status);
};

//-----------------------------------------------
//1�F���E���Ƀv���C���[�������Ă���Ƃ�
class ETransition_PIntoView : public EnemyMoveTransition
{
public:
	bool Transition(CollisionManager& cm, Status& status);
};

//-----------------------------------------------
//2�F���E���ɓ����Ă���v���C���[�����g�̔��Ε����Ɉړ������Ƃ�
class ETransition_PMoveOtherSide : public EnemyMoveTransition
{
public:
	bool Transition(CollisionManager& cm, Status& status);
};