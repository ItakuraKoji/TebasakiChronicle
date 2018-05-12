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
void EnemyTypeManager::LoadEnemyData(const std::string& filePath, int hoge)
{
	//�{���Ȃ炱���Ńt�@�C����ǂݍ���(���͉�)
	//Prototype�ɏo�Ă��錕�̎q

	//�ő�̗�
	int maxLife = 1;
	//�t�^�_���[�W
	int hitDamage = 1;
	//�ړ����x
	float moveSpeed = 1;
	//�W�����v��
	float jumpPower = 5;

	//�x�[�X�R���W����
	float shapeSize[3];
	shapeSize[0] = 16.f; shapeSize[1] = 24.f; shapeSize[2] = 1.f;
	K_Physics::CollisionShape* bs = CC::CreateBoxShape(shapeSize[0], shapeSize[1], shapeSize[2]);
	//�����A���㔻��p�R���W����
	K_Math::Vector3 cfpos = { 0.f, -shapeSize[1], 0.f };
	K_Math::Vector3 chpos = { 0.f, shapeSize[1], 0.f };
	K_Physics::CollisionShape* cs = CC::CreateBoxShape(shapeSize[0] - 1.f, 1.f, 1.f);
	//��_���A�J�����󂯗p�R���W����
	K_Math::Vector3 rpos = { 0.f, 0.f, 0.f };
	shapeSize[0] = 16.f; shapeSize[1] = 24.f; shapeSize[2] = 1.f;
	K_Physics::CollisionShape* rs = CC::CreateBoxShape(shapeSize[0], shapeSize[1], shapeSize[2]);
	//���E�p�R���W����
	K_Math::Vector3 fovpos = { 64.f, 32.f, 0.f };
	shapeSize[0] = 64.f; shapeSize[1] = 64.f; shapeSize[2] = 1.f;
	K_Physics::CollisionShape* fovs = CC::CreateBoxShape(shapeSize[0], shapeSize[1], shapeSize[2]);
	//�U������J�ڗp�R���W����
	K_Math::Vector3 aapos = { 24.f, 0.f, 0.f };
	shapeSize[0] = 24.f; shapeSize[1] = 24.f; shapeSize[2] = 1.f;
	K_Physics::CollisionShape* aas = CC::CreateBoxShape(shapeSize[0], shapeSize[1], shapeSize[2]);
	
	eType.emplace_back(new EnemyType("resource2", "data/image/resource2.png", maxLife, hitDamage, moveSpeed, jumpPower, bs, rs, fovs, aas, cs, rpos, fovpos, aapos, cfpos, chpos));


	int patternNum = 1;		//����p�^�[���̑���
	for (int i = 0; i < patternNum; ++i)
	{
		//����ƃA�j���[�V�����̐ݒ�
		int* transitionIdArr = new int[patternNum] {0};

		int totalMoveNum = 4;
		int* moveIdArr =		new int[totalMoveNum] { 2,  0,  3,  0};
		int* skillIdArr =		new int[totalMoveNum] { 0,  0,  0,  0};

		int* durationTimeArr;
		if (hoge == 0)
		{
			durationTimeArr = new int[totalMoveNum] {30, 30, 60, 30};
		}
		else
		{
			durationTimeArr = new int[totalMoveNum] {60, 60, 120, 60};
		}

		K_Math::Box2D* src = new K_Math::Box2D[totalMoveNum]{
			{ 0,   240, 32, 48 },
			{ 400, 240, 32, 48 },
			{ 96,  240, 40, 48 },
			{ 336, 240, 32, 48 }
		};
		int* sheet = new int[totalMoveNum] {3, -3, 2, 3};
		float* animSpd = new float[totalMoveNum] {7.f, 5.f, 5.f, 9.f};
		bool* ir = new bool[totalMoveNum] {true, false, false, false};

		eType.back()->GetEnemyMoveSet()->CreateMotionPattern(moveIdArr, skillIdArr, durationTimeArr, src, sheet, animSpd, ir, transitionIdArr, patternNum, totalMoveNum);
		
		delete transitionIdArr;
		delete moveIdArr;
		delete skillIdArr;
		delete durationTimeArr;
		delete src;
		delete sheet;
		delete animSpd;
		delete ir;
	}
}

//-----------------------------------------------------------------------------
//�w��ԍ��̓G�f�[�^�̃A�h���X�l��Ԃ�
EnemyType* EnemyTypeManager::GetEnemyTypeData(int enemyNum)
{
	if (enemyNum < (int)eType.size())
	{
		return eType[enemyNum];
	}
	return nullptr;
}