#include "EnemyMove.h"

//-----------------------------------------------
//�������Ȃ�
void EMove_NoMotion::EMove(Status& status, Move& move)
{
	//�����Ɂu�������Ȃ��v����������
}

//-----------------------------------------------
//�����Ă�������Ɉړ�����
void EMove_Movement::EMove(Status& status, Move& move)
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
//�W�����v
void EMove_Jump::EMove(Status& status, Move& move)
{
	move.JumpOperation();
}