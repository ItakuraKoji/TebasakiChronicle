#include "K_Audio\SoundSource.h"
#include "SoundClass.h"
#include <vector>
#define STREAMING K_Audio::SoundSource::LoadMode::Streaming
#define ALLREAD K_Audio::SoundSource::LoadMode::AllRead

//�q���C�u�����T�E���h�N���X���b�s���O
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

	//�T�E���h�����[�h����
	//1,���O 2,�p�X 3,�ǂݍ��݂̃^�C�v
	//void
	void LoadSound(const char* soundName,const char* path, K_Audio::SoundSource::LoadMode mode = STREAMING);

	//�ǂݍ��񂾃T�E���h���Đ�����
	//1,ID 2,���[�v�t���O 3,���̃T�E���h�̃{�����[��(0~1.0f)
	//void
	void Play(Id id,bool isloop = true, float gain = 1.0f);

	//ID�Ŏw�肵���T�E���h���Đ������ǂ����A�Đ����Ȃ�true
	//1,ID
	//bool
	bool IsPlay(Id id);

	//�ǂݍ��񂾃T�E���h�S�̂̃}�X�^�[�{�����[��
	//1,����(0~1.0f)
	//void
	void MasterGain(float gain = 1.0f);

};