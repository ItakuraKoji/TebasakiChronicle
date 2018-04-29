#include "EnemyTypeManager.h"

//�R���X�g���N�^
EnemyTypeManager::EnemyTypeManager() {}

//�f�X�g���N�^
EnemyTypeManager::~EnemyTypeManager()
{
	for (auto it : eType)
		delete it;
}

//-----------------------------------------------------------------------------
//�t�@�C����ǂݍ���œG�̃f�[�^�����
//�����F�ǂݍ��ރt�@�C���ւ̃p�X(string)
void EnemyTypeManager::LoadEnemyData(const std::string& filePath)
{
	//�{���Ȃ炱���Ńt�@�C����ǂݍ���(���͉�)
	//Prototype�ɏo�Ă��錕�̎q

	//�R���W�����̍쐬
	int shapeType = 1;
	float shapeSize[3] = { 16.f, 32.f, 0.f };
	K_Physics::CollisionShape* cs = nullptr;
	switch (shapeType)
	{
	case 0:
		cs = CM::CreateSphereShape(shapeSize[0]);
		break;

	case 1:
		cs = CM::CreateCapsuleShape(shapeSize[0], shapeSize[1]);
		break;

	case 2:
		cs = CM::CreateBoxShape(shapeSize[0], shapeSize[1], shapeSize[2]);
		break;
	}
	eType.emplace_back(new EnemyType("resource2", cs, 1, 1));

	//����ƃA�j���[�V�����̐ݒ�
	int totalMoveNum = 4;
	int* moveNum = new int[totalMoveNum] {0, 0, 0, 0};
	int* skillId = new int[totalMoveNum] {0, 0, 0, 0};
	int* durationTime = new int[totalMoveNum] {30, 30, 60, 30};
	K_Math::Box2D* src = new K_Math::Box2D[totalMoveNum]{
		{   0, 240, 32, 48 },
		{ 400, 240, 32, 48 },
		{  96, 240, 40, 48 },
		{ 336, 240, 32, 48 }
	};
	int* sheet = new int[totalMoveNum] {3, -3, 2, 3};
	float* animSpd = new float[totalMoveNum] {7.f, 5.f, 5.f, 9.f};
	bool* ir = new bool[totalMoveNum] {true, false, false, false};

	int transitionNum = 0;
	eType.back()->emSet->CreateMotionPattern(moveNum, skillId, durationTime, src, sheet, animSpd, ir, totalMoveNum, transitionNum);

	delete moveNum;
	delete skillId;
	delete durationTime;
	delete src;
	delete sheet;
	delete animSpd;
	delete ir;
}

//-----------------------------------------------------------------------------
//�w��ԍ��̓G�f�[�^�̃A�h���X�l��Ԃ�
//���� �����Ŏ擾�����f�[�^�����Ă͂����Ȃ�(����)
EnemyType* EnemyTypeManager::GetEnemyTypeData(int enemyNum)
{
	if (enemyNum < (int)eType.size())
	{
		return eType[enemyNum];
	}
	return nullptr;
}