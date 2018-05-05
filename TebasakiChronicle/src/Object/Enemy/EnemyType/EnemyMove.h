#pragma once
#include <vector>
#include "SystemClass.h"

//����̊��N���X
class EnemyMove
{
public:
	EnemyMove(){}
	virtual ~EnemyMove() {}
	virtual void Move(K_Math::Vector3& moveVec) = 0;
};

//-----------------------------------------------
//�������Ȃ�
class EMove_NoMotion : public EnemyMove
{
public:
	void Move(K_Math::Vector3& moveVec);
};

//-----------------------------------------------
//�E�Ɉړ�����
class EMove_WalkRight : public EnemyMove
{
public:
	void Move(K_Math::Vector3& moveVec);
};

//-----------------------------------------------
//��Ɉړ�����
class EMove_Up : public EnemyMove
{
public:
	void Move(K_Math::Vector3& moveVec);
};

//-----------------------------------------------
//���Ɉړ�����
class EMove_Down : public EnemyMove
{
public:
	void Move(K_Math::Vector3& moveVec);
};