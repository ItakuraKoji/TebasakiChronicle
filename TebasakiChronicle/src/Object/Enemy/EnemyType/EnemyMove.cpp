#include "EnemyMove.h"

//-----------------------------------------------
//�������Ȃ�
void EMove_NoMotion::EMove(CollisionManager& cmanager, Status& status, Move& move)
{
	//�����Ɂu�������Ȃ��v����������
}

//-----------------------------------------------
//�����Ă�������Ɉړ�����
void EMove_Movement::EMove(CollisionManager& cmanager, Status& status, Move& move)
{
	if (status.GetDirection() == status.Right)
	{
		move.GetMoveVec().x() += move.GetAddVec();
	}
	else
	{
		move.GetMoveVec().x() -= move.GetAddVec();
	}
}

//-----------------------------------------------
//�n�ʂɂ��Ă���Ƃ��̂݃W�����v
void EMove_Jump::EMove(CollisionManager& cmanager, Status& status, Move& move)
{
	if (int a = cmanager.GetConflictionObjectsUserData(3).size() > 0)
	{
		move.JumpOperation();
	}
}