#pragma once
#include "EnemyType.h"

class EnemyTypeManager
{
public:
	std::vector<EnemyType*> eType;

	//�R���X�g���N�^
	EnemyTypeManager();
	//�f�X�g���N�^
	~EnemyTypeManager();

	//�t�@�C����ǂݍ���œG�̃f�[�^�����
	//�����F�ǂݍ��ރt�@�C���ւ̃p�X(string)
	void LoadEnemyData(const std::string& filePath, int hoge);

	//�w��ԍ��̓G�f�[�^�̃A�h���X�l��Ԃ�
	EnemyType* GetEnemyTypeData(int enemyNum);
};