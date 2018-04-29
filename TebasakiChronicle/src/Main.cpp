#include "CSTList.h"
#include "CollisionManager.h"
#include "MeshModel.h"
#include "SystemClass.h"

#include "BaseClass\ImageManager\ImageManager.h"
#include "Object\Enemy\EnemyTypeManager.h"
#include "Object\Enemy\Enemy.h"

int main()
{
	//�E�B���h�E
	K_System::SystemClass* sc = new K_System::SystemClass(720, 540, false);

	//CollisionManager��������
	CM::Initialize();

	//�J�������X�g
	K_Math::Vector3 position = K_Math::Vector3(0, 0, -150);
	K_Math::Vector3 target = K_Math::Vector3(0, 0, 0);
	int screenWidth = 720;
	int screenHeight = 540;
	float clipNear = 0.1f;
	float clipFar = 1500.f;
	float fieldOfView = 45.f;
	CST::CreatePerspectiveCamera(position, target, screenWidth, screenHeight, clipNear, clipFar, fieldOfView);
	CST::CreateOrthoCamera(position, target, screenWidth, screenHeight, clipNear, clipFar);

	//�V�F�[�_�[���X�g
	CST::CreateShader("data/shader/SpriteShader.vs", "data/shader/SpriteShader.ps");

	//�G�̎�ނ��쐬
	EnemyTypeManager* etm = new EnemyTypeManager();
	etm->LoadEnemyData("");
	//�G1�̂ɏ�L�ō쐬������ނ����蓖�Ă�
	Enemy e1(etm->GetEnemyTypeData(0), K_Math::Vector3(0, 0, 0));


	while (sc->IsSystemEnd() == false)
	{
		sc->ProcessSystem();

		e1.Update();

		CST::FrameBufferBeginDraw(720, 540, 0.f, 0.f, 1.f);
		CST::GetPerspectiveCamera()->Draw();
		CST::GetOrthoCamera()->Draw();

		e1.Draw();
		CM::DebugDraw(CST::GetShaderClass(), CST::GetPerspectiveCamera());

		sc->SwapBuffer();
	}

	delete sc;
	delete etm;

	CST::Delete();
	CM::Delete();
}