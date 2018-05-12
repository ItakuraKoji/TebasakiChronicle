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

	//�e�N�X�`���̃p�X
	std::string texpath("data/image/resource2.png");

	//�g�p����摜��
	std::string texName("resource2");
	//�ő�̗�
	int maxLife = 1;
	//�t�^�_���[�W
	int hitDamage = 1;
	//�ړ����x
	float moveSpeed = 1;
	//�W�����v��
	float jumpPower = 5;
	//�܂Ƃ߂���I
	EnemyType::ParameterData param(texName, maxLife, hitDamage, moveSpeed, jumpPower);

	//�x�[�X�R���W����
	float shapeSize[3];
	shapeSize[0] = 16.f; shapeSize[1] = 24.f; shapeSize[2] = 1.f;
	K_Physics::CollisionShape* bs = CC::CreateBoxShape(shapeSize[0], shapeSize[1], shapeSize[2]);
	//�����A���㔻��p�R���W����
	K_Math::Vector3 cfp = { 0.f, -shapeSize[1], 0.f };
	K_Math::Vector3 chp = { 0.f, shapeSize[1], 0.f };
	K_Physics::CollisionShape* cs = CC::CreateBoxShape(shapeSize[0] - 1.f, 1.f, 1.f);
	//��_���A�J�����󂯗p�R���W����
	K_Math::Vector3 rp = { 0.f, 0.f, 0.f };
	shapeSize[0] = 16.f; shapeSize[1] = 24.f; shapeSize[2] = 1.f;
	K_Physics::CollisionShape* rs = CC::CreateBoxShape(shapeSize[0], shapeSize[1], shapeSize[2]);
	//���E�p�R���W����
	K_Math::Vector3 vp = { 64.f, 32.f, 0.f };
	shapeSize[0] = 64.f; shapeSize[1] = 64.f; shapeSize[2] = 1.f;
	K_Physics::CollisionShape* vs = CC::CreateBoxShape(shapeSize[0], shapeSize[1], shapeSize[2]);
	//�U������J�ڗp�R���W����
	K_Math::Vector3 aap = { 24.f, 0.f, 0.f };
	shapeSize[0] = 24.f; shapeSize[1] = 24.f; shapeSize[2] = 1.f;
	K_Physics::CollisionShape* aas = CC::CreateBoxShape(shapeSize[0], shapeSize[1], shapeSize[2]);
	//�ق�܂Ƃ߂���ق�I����ł����񂾂�I���I
	EnemyType::CollisionData col(bs, rs, vs, aas, cs, rp, vp, aap, cfp, chp);

	eType.emplace_back(new EnemyType(texpath, param, col));	//�R���W�����Ƃ��̃R���W�����̔z�u��ݒ�


	int patternNum = 1;		//����p�^�[���̑���
	for (int i = 0; i < patternNum; ++i)
	{
		//����ƃA�j���[�V�����̐ݒ�
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

		K_Math::Box2D* srcArr = new K_Math::Box2D[totalMoveNum]{
			{ 0,   240, 32, 48 },
			{ 400, 240, 32, 48 },
			{ 96,  240, 40, 48 },
			{ 336, 240, 32, 48 }
		};
		int* sheetArr = new int[totalMoveNum] {3, -3, 2, 3};
		float* spdArr = new float[totalMoveNum] {7.f, 5.f, 5.f, 9.f};
		bool* irArr = new bool[totalMoveNum] {true, false, false, false};

		int* transitionIdArr = new int[patternNum] {0};

		EnemyMovePattern::MoveSetUpData msud(moveIdArr, skillIdArr, durationTimeArr, srcArr, sheetArr, spdArr, irArr, transitionIdArr, patternNum, totalMoveNum);

		eType.back()->GetEnemyMoveSet()->CreateMotionPattern(msud);	//����p�^�[������ݒ�
		
		delete moveIdArr;
		delete skillIdArr;
		delete durationTimeArr;
		delete srcArr;
		delete sheetArr;
		delete spdArr;
		delete irArr;
		delete transitionIdArr;
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