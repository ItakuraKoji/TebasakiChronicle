#include "SystemClass.h"
#include "MeshModel.h"
#include "FrameBufferList.h"
#include "K_Graphics\CameraList.h"
#include "K_Graphics\ShaderList.h"
#include "K_Graphics\TextureList.h"
#include "./BaseClass/Sound.h"
int main()
{
	K_System::SystemClass* sc = new K_System::SystemClass(720, 540, false);

	K_Graphics::CameraList* cList = new K_Graphics::CameraList;
	cList->AddPerspectiveCamera("Camera",
		K_Math::Vector3(0, 0, -100), K_Math::Vector3(0, 0, 0), 720, 540, 0.1f, 1500.f, 45.f);

	K_Graphics::ShaderList* sList = new K_Graphics::ShaderList;

	sList->LoadVertexShader("data/shader/SpriteShader.vs");
	sList->LoadFragmentShader("data/shader/SpriteShader.ps");
	sList->CreateShaderProgram("shader", "data/shader/SpriteShader.vs", "data/shader/SpriteShader.ps");

	K_Graphics::TextureList* tList = new K_Graphics::TextureList;

	tList->LoadTexture("Tekitou", "./data/image/Tekitou.tga");
	K_Graphics::SpriteObject* spobj = new K_Graphics::SpriteObject(
		tList->GetTexture("Tekitou"));
	spobj->controlPoint = K_Math::Vector2(64.f, 64.f);

	K_Graphics::FrameBufferList* frame = new K_Graphics::FrameBufferList(tList);

	//サウンドエンジンの初期化
	SoundEngine* soundEngine = soundEngine->GetInstance();
	soundEngine->Create();
	//音源のロード
	Sound source;
	source.LoadSound("bgm","a.ogg");
	Sound source1;
	source1.LoadSound("se", "slashing01.ogg",ALLREAD);
	//Engineにサウンドを登録(追加しないとアクセス違反)
	soundEngine->AddSource(source);
	soundEngine->AddSource(source1);
	K_Audio::SoundSource* bgm = soundEngine->GetInstance()->GetSource("bgm");
	K_Audio::SoundSource* se = soundEngine->GetInstance()->GetSource("se");
	//再生
	bgm->Play(true);

	int c = 0;
	while (sc->IsSystemEnd() == false)
	{
		sc->ProcessSystem();

		frame->BeginDraw(720, 540, 0.0f, 0.0f, 1.0f);

		cList->GetCamera("Camera")->Draw();

		
		if (GetKeyState(VK_RETURN) & 0x8000)
		{
			++c;
		}
		else
		{
			c = 0;
		}
		if (c == 1)
		{
			//se->Play(false);
			se->PlayCopy();
		}
		if (GetKeyState(VK_SPACE) & 0x8000)
		{
			soundEngine->GetInstance()->DeleteSound("bgm");
		}
		spobj->Draw3D(cList->GetCamera("Camera"),
			sList->GetShader("shader"),
			K_Math::Box2D(0, 0, 128, 128),
			K_Math::Vector3(-64, 64, 100),
			K_Math::Vector3(0, 0, 0),
			K_Math::Vector3(1, 1, 1));

		sc->SwapBuffer();
	}

	/*delete spobj;*/
	delete sc;
	delete cList;
	delete sList;
	delete tList;
	delete frame;
}