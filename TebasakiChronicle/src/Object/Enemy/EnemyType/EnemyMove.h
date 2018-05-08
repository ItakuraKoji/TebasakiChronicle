#pragma once
#include <vector>
#include "SystemClass.h"
#include "../../../BaseClass/Status/Status.h"
#include "../../../BaseClass/Move.h"

//����̊��N���X
class EnemyMove
{
public:
	EnemyMove(){}
	virtual ~EnemyMove() {}
	virtual void EMove(Status& status, Move& move) = 0;
};

//-----------------------------------------------
//�������Ȃ�
class EMove_NoMotion : public EnemyMove
{
public:
	void EMove(Status& status, Move& move);
};

//-----------------------------------------------
//�����Ă�������Ɉړ�����
class EMove_Movement : public EnemyMove
{
public:
	void EMove(Status& status, Move& move);
};

//-----------------------------------------------
//�W�����v����
class EMove_Jump : public EnemyMove
{
public:
	void EMove(Status& status, Move& move);
};