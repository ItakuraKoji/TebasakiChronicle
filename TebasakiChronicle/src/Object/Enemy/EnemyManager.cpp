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
void EnemyManager::CreateEnemy(EnemyType* cpyet, const K_Math::Vector3& setPos, const Status::Direction& direction)
{
	enemy.emplace_back(new Enemy(cpyet, setPos, direction));
}

//-----------------------------------------------------------------------------
//�S�Ă̓G���X�V����
void EnemyManager::UpdateAllEnemy()
{
	for (auto it = enemy.begin(); it != enemy.end();)
	{
		if ((*it)->Update())	//���S������폜
		{
			delete *(it);
			it = enemy.erase(it);
		}
		else
		{
			++it;
		}
	}
	enemy.shrink_to_fit();
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

//-----------------------------------------------------------------------------
//�S�Ă̓G���폜(���)����
void EnemyManager::DeleteAllEnemy()
{
	for (auto it : enemy)
		delete it;

	enemy.clear();
	enemy.shrink_to_fit();
}