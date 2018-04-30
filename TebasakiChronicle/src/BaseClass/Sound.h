#pragma warning( disable : 4251 4099 )	//libのリンク関係
#include "K_Audio\SoundSource.h"
#include "SoundClass.h"
#include <string>
#define STREAMING K_Audio::SoundSource::LoadMode::Streaming
#define ALLREAD K_Audio::SoundSource::LoadMode::AllRead

//板倉ライブラリサウンドクラスラッピング

//サウンドクラスの初期化。一つあればいいのででシングルトン
//デストラクタかデストロイで死にます

class Sound
{
private:

	K_Audio::SoundSource* soundSource;
	std::string name;
	std::string path;
	K_Audio::SoundSource::LoadMode mode;
	
public:
	Sound();
	~Sound();

	std::string GetName()
	{
		return name;
	}
	std::string GetPath()
	{
		return path;
	}
	K_Audio::SoundSource::LoadMode GetMode()
	{
		return mode;
	}
	//サウンドをロードする
	//1,名前 2,パス 3,読み込みのタイプ
	//void
	void LoadSound(const char* soundName,const char* path, K_Audio::SoundSource::LoadMode mode = STREAMING);
	
	//サウンドをロードする
	//1,ループフラグ(デフォルトでON) 2,音量(0~1.0f,デフォルトで1.0f)
	//void
	void Play(bool isLoop = true, float gain = 1.0f);

	//サウンドの停止、再開する場合は最初から
	//なし
	//void
	void Stop();

	//サウンドの一時停止
	//なし
	//void
	void Pause();

	//サウンドが再生中かどうか
	//なし
	//bool
	bool IsPlay();
	
	

};


class SoundEngine final
{
private:
	static K_Audio::SoundClass* soundEngine;
	SoundEngine();

public:
	SoundEngine(const SoundEngine&) = delete;		//コピー禁止
	~SoundEngine();

	void Create();
	K_Audio::SoundSource* GetSource(const char*  sourceName)
	{
		return soundEngine->GetSource(sourceName);
	}
	static SoundEngine* GetInstance();

	void AddSource(Sound&);
	//引数で指定したサウンドソースを破棄
	//1,サウンドソース名
	//void
	void DeleteSound(const char*  sourceName);
	//サウンドエンジンの破棄
	//なし
	//void
	void DestroyEngine();
};