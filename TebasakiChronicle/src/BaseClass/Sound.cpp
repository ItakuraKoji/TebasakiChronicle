#include "Sound.h"

Sound::Sound()
{
	for (int i = 0; i < sound.size(); ++i)
	{
		sound[i] = nullptr;
	}
	source = new K_Audio::SoundClass;
	masterGain = 1.0f;
}

Sound::~Sound()
{

	for (int i = 0; i < sound.size(); ++i)
	{
		delete sound[i];
	}
	
	if (source != nullptr)
	{
		delete source;
	}
}
 
void Sound::LoadSound(const char* soundName, const char* path, K_Audio::SoundSource::LoadMode mode)
{
	sound.push_back(new K_Audio::SoundSource(soundName,path,mode));
}
bool Sound::IsPlay(Id id)
{
	return sound[static_cast<int>(id)]->IsPlay();
}

void Sound::Play(Id id,bool isloop,float gain)
{
		sound[static_cast<int>(id)]->SetVolume(gain * masterGain);
		sound[static_cast<int>(id)]->Play(isloop);
}

void Sound::MasterGain(float gain)
{
	masterGain = gain;
}