#include "K_Audio\SoundSource.h"
#include "SoundClass.h"
#include <vector>
#define STREAMING K_Audio::SoundSource::LoadMode::Streaming
#define ALLREAD K_Audio::SoundSource::LoadMode::AllRead

//板倉ライブラリサウンドクラスラッピング
class Sound
{
private:
	float masterGain;
	K_Audio::SoundClass* source;
	std::vector<K_Audio::SoundSource*> sound;
public:
	enum class Id
	{
		BGM01
	};
	Sound();
	~Sound();

	//サウンドをロードする
	//1,名前 2,パス 3,読み込みのタイプ
	//void
	void LoadSound(const char* soundName,const char* path, K_Audio::SoundSource::LoadMode mode = STREAMING);

	//読み込んだサウンドを再生する
	//1,ID 2,ループフラグ 3,このサウンドのボリューム(0~1.0f)
	//void
	void Play(Id id,bool isloop = true, float gain = 1.0f);

	//IDで指定したサウンドが再生中かどうか、再生中ならtrue
	//1,ID
	//bool
	bool IsPlay(Id id);

	//読み込んだサウンド全体のマスターボリューム
	//1,音量(0~1.0f)
	//void
	void MasterGain(float gain = 1.0f);

};