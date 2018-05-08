#include "CSTList.h"
#include "BaseClass/Collision/CollisionCreator.h"
#include "MeshModel.h"
#include "SystemClass.h"

#include "BaseClass/ImageManager/ImageManager.h"
#include "Object/Enemy/EnemyType/EnemyTypeManager.h"
#include "Object/Enemy/EnemyManager.h"

#include "Object/Player/Player.h"

int main()
{
	//ウィンドウ
	K_System::SystemClass* sc = new K_System::SystemClass("TebasakiChronicle", 720, 540, false);

	//CollisionManagerを初期化
	CC::Initialize();

	//カメラリスト
	K_Math::Vector3 position = K_Math::Vector3(0, 0, -150);
	K_Math::Vector3 target = K_Math::Vector3(0, 0, 0);
	int screenWidth = 720;
	int screenHeight = 540;
	float clipNear = 0.1f;
	float clipFar = 1500.f;
	float fieldOfView = 45.f;
	CST::CreatePerspectiveCamera(position, target, screenWidth, screenHeight, clipNear, clipFar, fieldOfView);
	CST::CreateOrthoCamera(position, target, screenWidth, screenHeight, clipNear, clipFar);

	//シェーダーリスト
	CST::CreateShader("data/shader/SpriteShader.vs", "data/shader/SpriteShader.ps");

	//敵の種類を作成
	EnemyTypeManager* etm = new EnemyTypeManager();
	etm->LoadEnemyData("");
	//敵1体に上記で作成した種類を割り当てる
	EnemyManager* emanager = new EnemyManager();
	emanager->CreateEnemy(etm->GetEnemyTypeData(0), K_Math::Vector3(0, 0, 0), Status::Direction::Right);

	//プレイヤー
	/*Player player;
	player.Initliaze();*/

	while (sc->IsSystemEnd() == false)
	{
		sc->ProcessSystem();

		emanager->UpdateAllEnemy();

		//player.UpDate();


		CST::FrameBufferBeginDraw(720, 540, 0.f, 0.f, 1.f);
		CST::GetPerspectiveCamera()->Draw();
		CST::GetOrthoCamera()->Draw();

		emanager->DrawAllEnemy();
		CC::DebugDraw(CST::GetShaderClass(), CST::GetPerspectiveCamera());

		//player.Render();

		sc->SwapBuffer();
	}

	delete sc;
	delete etm;
	delete emanager;

	CC::Delete();
}