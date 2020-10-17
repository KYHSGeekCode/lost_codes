//AudioManager.cpp
#include "spaceship.h"

bool AudioManager::Initialize()
{
	
	return (MyInitializeOpenAL()==TRUE);
}

void AudioManager::DeInitialize()
{
	MyDeInitializeOpenAL();
}

// Initialization
BOOL AudioManager::MyInitializeOpenAL()
{
	Device = alcOpenDevice(NULL); // select the "preferred device"
	if (Device) {
		Context=alcCreateContext(Device,NULL);
		alcMakeContextCurrent(Context);
	}
	// Check for EAX 2.0 support
	bEAX = alIsExtensionPresent("EAX2.0");
	alGetError(); // clear error code
	// Generate Buffers
	alGenBuffers(NUM_BUFFERS, Buffers);
	if ((error = alGetError()) != AL_NO_ERROR)
	{
		//DisplayALError("alGenBuffers :", error);
		return FALSE;
	}
}

void AudioManager::MyDeInitializeOpenAL()
{
	for(int i=0;i<NUM_SOURCES;i++)
		alSourceStop(Sources[i]);
    alDeleteSources(NUM_SOURCES, Sources);
	alDeleteBuffers(NUM_BUFFERS, Buffers);
	// Exit
	Context=alcGetCurrentContext();
	Device=alcGetContextsDevice(Context);
	alcMakeContextCurrent(NULL);
	alcDestroyContext(Context);
	alcCloseDevice(Device);
}

void AudioManager::ListenerPos(const vec & pos)
{
	alListener3f(AL_POSITION,pos.x,pos.y,pos.z);
}

void AudioManager::ListenerVel(const vec & vel)
{
	alListener3f(AL_VELOCITY,vel.x,vel.y,vel.z);
}

AudioIndex AudioManager::LoadAudio(const char *filename)
{
	return 0;
}

SourceIndex AudioManager::AllocSource(AudioIndex i)
{
	return 0;
}

