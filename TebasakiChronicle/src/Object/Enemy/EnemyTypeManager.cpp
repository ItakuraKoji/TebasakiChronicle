#include "EnemyTypeManager.h"

//コンストラクタ
EnemyTypeManager::EnemyTypeManager() {}

//デストラクタ
EnemyTypeManager::~EnemyTypeManager()
{
	for (auto it : eType)
		delete it;
}

//-----------------------------------------------------------------------------
//ファイルを読み込んで敵のデータを作る
//引数：読み込むファイルへのパス(string)
void EnemyTypeManager::LoadEnemyData(const std::string& filePath)
{
	//本来ならここでファイルを読み込む(今は仮)
	//Prototypeに出てくる剣の子

	//コリジョンの作成
	int shapeType = 1;
	float shapeSize[3] = { 16.f, 32.f, 0.f };
	K_Physics::CollisionShape* cs = nullptr;
	switch (shapeType)
	{
	case 0:
		cs = CC::CreateSphereShape(shapeSize[0]);
		break;

	case 1:
		cs = CC::CreateCapsuleShape(shapeSize[0], shapeSize[1]);
		break;

	case 2:
		cs = CC::CreateBoxShape(shapeSize[0], shapeSize[1], shapeSize[2]);
		break;
	}
	eType.emplace_back(new EnemyType("resource2", cs, 1, 1));

	//動作とアニメーションの設定
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
//指定番号の敵データのアドレス値を返す
//※注 ここで取得したデータをしてはいけない(戒め)
EnemyType* EnemyTypeManager::GetEnemyTypeData(int enemyNum)
{
	if (enemyNum < (int)eType.size())
	{
		return eType[enemyNum];
	}
	return nullptr;
}