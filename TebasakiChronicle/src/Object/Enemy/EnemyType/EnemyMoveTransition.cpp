#include "EnemyMoveTransition.h"

EnemyMoveTransition::EnemyMoveTransition(){}
EnemyMoveTransition::~EnemyMoveTransition(){}

//-----------------------------------------------------------------------------
//0�F���false��Ԃ�
bool ETransition_NotTrans::Transition(CollisionManager& cm, Status& status)
{
	return false;
}

//-----------------------------------------------------------------------------
//1�F���E���Ƀv���C���[�������Ă���Ƃ�
bool ETransition_PIntoView::Transition(CollisionManager& cm, Status& status)
{
	if (cm.CheckHitSubCollisionObejct(1))
		return true;

	return false;
}

//-----------------------------------------------------------------------------
//2�F���E���ɓ����Ă���v���C���[�����g�̔��Ε����Ɉړ������Ƃ�
bool ETransition_PMoveOtherSide::Transition(CollisionManager& cm, Status& status)
{
	//���E�p�R���W��������v���C���[�̍��W���󂯎��
	for (auto it : cm.GetConflictionObjectsTag(1))
	{
		Status* pst = (Status*)it->userData;
		if (status.GetState() == Status::Right)
		{
			if ((status.GetPos().x() - pst->GetPos().x()) > 0.f)
				return true;
		}
		else
		{
			if ((status.GetPos().x() - pst->GetPos().x()) < 0.f)
				return true;
		}
	}
	return false;
}