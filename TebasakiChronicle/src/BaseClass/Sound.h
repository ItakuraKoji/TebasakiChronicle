#pragma warning( disable : 4251 4099 )	//lib�̃����N�֌W
#include "K_Audio\SoundSource.h"
#include "SoundClass.h"
#include <string>
#define STREAMING K_Audio::SoundSource::LoadMode::Streaming
#define ALLREAD K_Audio::SoundSource::LoadMode::AllRead

//�q���C�u�����T�E���h�N���X���b�s���O

//�T�E���h�N���X�̏������B�����΂����̂łŃV���O���g��
//�f�X�g���N�^���f�X�g���C�Ŏ��ɂ܂�

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
	//�T�E���h�����[�h����
	//1,���O 2,�p�X 3,�ǂݍ��݂̃^�C�v
	//void
	void LoadSound(const char* soundName,const char* path, K_Audio::SoundSource::LoadMode mode = STREAMING);
	
	//�T�E���h�����[�h����
	//1,���[�v�t���O(�f�t�H���g��ON) 2,����(0~1.0f,�f�t�H���g��1.0f)
	//void
	void Play(bool isLoop = true, float gain = 1.0f);

	//�T�E���h�̒�~�A�ĊJ����ꍇ�͍ŏ�����
	//�Ȃ�
	//void
	void Stop();

	//�T�E���h�̈ꎞ��~
	//�Ȃ�
	//void
	void Pause();

	//�T�E���h���Đ������ǂ���
	//�Ȃ�
	//bool
	bool IsPlay();
	
	

};


class SoundEngine final
{
private:
	static K_Audio::SoundClass* soundEngine;
	SoundEngine();

public:
	SoundEngine(const SoundEngine&) = delete;		//�R�s�[�֎~
	~SoundEngine();

	void Create();
	K_Audio::SoundSource* GetSource(const char*  sourceName)
	{
		return soundEngine->GetSource(sourceName);
	}
	static SoundEngine* GetInstance();

	void AddSource(Sound&);
	//�����Ŏw�肵���T�E���h�\�[�X��j��
	//1,�T�E���h�\�[�X��
	//void
	void DeleteSound(const char*  sourceName);
	//�T�E���h�G���W���̔j��
	//�Ȃ�
	//void
	void DestroyEngine();
};