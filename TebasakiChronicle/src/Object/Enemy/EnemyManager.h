#pragma once
#include "Enemy.h"

class EnemyManager
{
private:
	std::vector<Enemy*> enemy;

public:
	EnemyManager();
	~EnemyManager();

	//�G����̍쐬����
	void CreateEnemy(EnemyType* cpyet, const K_Math::Vector3& setPos);
	//�쐬�����S�Ă̓G���X�V����
	void UpdateAllEnemy();
	//�S�Ă̓G��`�悷��
	void DrawAllEnemy();
};