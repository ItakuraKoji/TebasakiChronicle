#include "EnemyMove.h"

//-----------------------------------------------
//�������Ȃ�
void EMove_NoMotion::Move(K_Math::Vector3& moveVec)
{
	//�����Ɂu�������Ȃ��v����������
}

//-----------------------------------------------
//�E�ɕ���
void EMove_WalkRight::Move(K_Math::Vector3& moveVec)
{
	++moveVec.x();
}

//-----------------------------------------------
//��Ɉړ�����
void EMove_Up::Move(K_Math::Vector3& moveVec)
{
	--moveVec.y();
}

//-----------------------------------------------
//���Ɉړ�����
void EMove_Down::Move(K_Math::Vector3& moveVec)
{
	++moveVec.y();
}