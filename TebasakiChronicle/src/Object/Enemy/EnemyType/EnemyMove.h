#pragma once
#include <vector>
#include "SystemClass.h"
#include "../../../BaseClass/Status/Status.h"
#include "../../../BaseClass/Move.h"
#include "../../../BaseClass/Collision/CollisionManager.h"
#include "../../TemporaryCollision/TemporaryCollisionManager.h"

//����̊��N���X
class EnemyMove
{
public:
	EnemyMove(){}
	virtual ~EnemyMove() {}
	virtual void FirstMove(CollisionManager& cmanager, TemporaryCollisionManager& tempmanager, Status& status, Move& move) = 0;
	virtual void EMove(CollisionManager& cmanager, TemporaryCollisionManager& tempmanager, Status& status, Move& move) = 0;
};

//-----------------------------------------------
//�������Ȃ�
class EMove_NoMotion : public EnemyMove
{
public:
	void FirstMove(CollisionManager& cmanager, TemporaryCollisionManager& tempmanager, Status& status, Move& move);
	void EMove(CollisionManager& cmanager, TemporaryCollisionManager& tempmanager, Status& status, Move& move);
};

//-----------------------------------------------
//�����Ă�������Ɉړ�����
class EMove_Movement : public EnemyMove
{
public:
	void FirstMove(CollisionManager& cmanager, TemporaryCollisionManager& tempmanager, Status& status, Move& move);
	void EMove(CollisionManager& cmanager, TemporaryCollisionManager& tempmanager, Status& status, Move& move);
};

//-----------------------------------------------
//�W�����v����
class EMove_Jump : public EnemyMove
{
public:
	void FirstMove(CollisionManager& cmanager, TemporaryCollisionManager& tempmanager, Status& status, Move& move);
	void EMove(CollisionManager& cmanager, TemporaryCollisionManager& tempmanager, Status& status, Move& move);
};

//-----------------------------------------------
//�O���ɍU������
class EMove_FrontAttack : public EnemyMove
{
private:
	void CreateAttackCollision();

public:
	void FirstMove(CollisionManager& cmanager, TemporaryCollisionManager& tempmanager, Status& status, Move& move);
	void EMove(CollisionManager& cmanager, TemporaryCollisionManager& tempmanager, Status& status, Move& move);
};