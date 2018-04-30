#include "Sound.h"

//static---------------------------
K_Audio::SoundClass* SoundEngine::soundEngine = nullptr;
//---------------------------------
SoundEngine::SoundEngine()
{
	
}

void SoundEngine::Create()
{
	soundEngine = new K_Audio::SoundClass;
}

SoundEngine::~SoundEngine()
{
	if (soundEngine != nullptr)
	{
		delete soundEngine;
		soundEngine = nullptr;
	}
}

void SoundEngine::AddSource(Sound& source)
{
	soundEngine->CreateSource(source.GetName().c_str(), source.GetPath().c_str(), source.GetMode());
}
SoundEngine* SoundEngine::GetInstance()
{
	static SoundEngine inst;
	return &inst;
}

void SoundEngine::DeleteSound(const char*  sourceName)
{
	soundEngine->DeleteSource(sourceName);
}

void SoundEngine::DestroyEngine()
{
	if (soundEngine != nullptr)
	{
		delete soundEngine;
		soundEngine = nullptr;
	}
}

Sound::Sound()
{
	soundSource = nullptr;
}

Sound::~Sound()
{
	if (soundSource != nullptr)
	{
		delete soundSource;
		soundSource = nullptr;
	}		
}

void Sound::LoadSound(const char* soundName, const char* path, K_Audio::SoundSource::LoadMode mode)
{
	this->name = soundName;
	this->path = path;
	this->mode = mode;
	soundSource = (new K_Audio::SoundSource(soundName,path,mode));
}

void Sound::Play(bool isLoop, float gain)
{
	soundSource->SetVolume(gain);
	soundSource->Play(isLoop);
}