#pragma once
#include "Enemy.h"

class EnemyManager
{
private:
	std::vector<Enemy*> enemy;

public:
	EnemyManager();
	~EnemyManager();

	//敵を一体作成する
	void CreateEnemy(EnemyType* cpyet, const K_Math::Vector3& setPos, const Status::Direction& direction);
	//作成した全ての敵を更新する
	void UpdateAllEnemy();
	//全ての敵を描画する
	void RenderAllEnemy();

	//全ての敵を削除(解放)する
	void DeleteAllEnemy();
};