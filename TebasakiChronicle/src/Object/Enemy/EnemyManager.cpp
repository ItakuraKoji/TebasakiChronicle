#include "EnemyManager.h"

//�R���X�g���N�^
EnemyManager::EnemyManager() {}

//�f�X�g���N�^
EnemyManager::~EnemyManager()
{
	for (auto it : enemy)
		delete it;
}

//-----------------------------------------------------------------------------
//�G����̍쐬����
void EnemyManager::CreateEnemy(EnemyType* cpyet, const K_Math::Vector3& setPos)
{
	enemy.emplace_back(new Enemy(cpyet, setPos));
}

//-----------------------------------------------------------------------------
//�S�Ă̓G���X�V����
void EnemyManager::UpdateAllEnemy()
{
	for (auto it : enemy)
	{
		it->Update();
	}
}

//-----------------------------------------------------------------------------
//�S�Ă̓G��`�悷��
void EnemyManager::DrawAllEnemy()
{
	for (auto it : enemy)
	{
		it->Draw();
	}
}