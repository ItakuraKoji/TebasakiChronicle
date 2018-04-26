#include "MeshModel.h"
#include "CSTList.h"
#include "SystemClass.h"
#include "FrameBufferList.h"

#include "BaseClass\ImageManager\ImageManager.h"
#include "Object\Enemy\EnemyTypeManager.h"
#include "Object\Enemy\Enemy.h"

int main()
{
	//�E�B���h�E
	K_System::SystemClass* sc = new K_System::SystemClass(720, 540, false);

	//�J�����ƃV�F�[�_�[�ƃe�N�X�`���������Ă���
	CSTList* cst = CSTList::GetInstance();

	//�J�������X�g
	cst->CreatePerspectiveCamera(
		K_Math::Vector3(0, 0, -150), K_Math::Vector3(0, 0, 0), 720, 540, 0.1f, 1500.f, 45.f);

	//�V�F�[�_�[���X�g
	cst->CreateShader("data/shader/SpriteShader.vs", "data/shader/SpriteShader.ps");

	//�e�N�X�`�����X�g
	K_Graphics::FrameBufferList* frame = new K_Graphics::FrameBufferList(cst->GetTextureList());

	//�G������
	EnemyTypeManager etm;
	etm.LoadEnemyData("");

	Enemy e1(etm.GetEnemyTypeData(0), K_Math::Vector3(0, 0, 0));


	while (sc->IsSystemEnd() == false)
	{
		sc->ProcessSystem();

		e1.Update();

		frame->BeginDraw(720, 540, 0.f, 0.f, 1.f);
		cst->GetPerspectoveCamera()->Draw();

		e1.Render();

		sc->SwapBuffer();
	}
}