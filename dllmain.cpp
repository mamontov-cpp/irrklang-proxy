﻿#include "irrklang-proxy.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

irrklang::ISoundEngine* ikProxy::createIrrKlangDevice(irrklang::E_SOUND_OUTPUT_DRIVER driver,
		int options,
		const char* deviceID ,
		const char* sdk_version_do_not_use
)
{
	return irrklang::createIrrKlangDevice(driver, options, deviceID, sdk_version_do_not_use);
}

irrklang::ISoundDeviceList* ikProxy::createSoundDeviceList(
	irrklang::E_SOUND_OUTPUT_DRIVER driver ,
	const char* sdk_version_do_not_use
)
{
	return irrklang::createSoundDeviceList(driver, sdk_version_do_not_use);
}

irrklang::IAudioRecorder* ikProxy::createIrrKlangAudioRecorder(
	irrklang::ISoundEngine* irrKlangDeviceForPlayback,
	irrklang::E_SOUND_OUTPUT_DRIVER driver,
	const char* deviceID,
	const char* sdk_version_do_not_use
)
{
	return irrklang::createIrrKlangAudioRecorder(irrKlangDeviceForPlayback, driver, deviceID, sdk_version_do_not_use);
}

irrklang::ISoundDeviceList* ikProxy::createAudioRecorderDeviceList(
	irrklang::E_SOUND_OUTPUT_DRIVER driver,
	const char* sdk_version_do_not_use
)
{
	return irrklang::createAudioRecorderDeviceList(driver, sdk_version_do_not_use);
}

bool ikProxy::makeUTF8fromUTF16string(
	const wchar_t* pInputString, char* pOutputBuffer, int outputBufferSize
)
{
	return irrklang::makeUTF8fromUTF16string(pInputString, pOutputBuffer, outputBufferSize);
}

irrklang::SAudioStreamFormat ikProxy::SAudioStreamFormat::makeDefaultFormat()
{
	return { 2, -1, 44100, irrklang::ESF_U8 };
}

irrklang::SAudioStreamFormat ikProxy::SAudioStreamFormat::makeFormat(
	int channelCount,
	int frameCount,
	int sampleRate,
	irrklang::ESampleFormat sampleFormat
)
{
	return { channelCount, frameCount, sampleRate, sampleFormat };
}

void ikProxy::SAudioStreamFormat::setChannelCount(irrklang::SAudioStreamFormat& format, int channelCount)
{
	format.ChannelCount = channelCount;
}


int ikProxy::SAudioStreamFormat::getChannelCount(const irrklang::SAudioStreamFormat& format)
{
	return format.ChannelCount;
}

void ikProxy::SAudioStreamFormat::setFrameCount(irrklang::SAudioStreamFormat& format, int frameCount)
{
	format.FrameCount = frameCount;
}

int ikProxy::SAudioStreamFormat::getFrameCount(const irrklang::SAudioStreamFormat& format)
{
	return format.FrameCount;
}

void ikProxy::SAudioStreamFormat::setSampleRate(irrklang::SAudioStreamFormat& format, int sampleRate)
{
	format.SampleRate = sampleRate;
}

int ikProxy::SAudioStreamFormat::getSampleRate(const irrklang::SAudioStreamFormat& format)
{
	return format.SampleRate;
}

void ikProxy::SAudioStreamFormat::setSampleFormat(irrklang::SAudioStreamFormat& format, irrklang::ESampleFormat sampleFormat)
{
	format.SampleFormat = sampleFormat;
}

irrklang::ESampleFormat ikProxy::SAudioStreamFormat::getSampleFormat(const irrklang::SAudioStreamFormat& format)
{
	return format.SampleFormat;
}

irrklang::ik_s32 ikProxy::SAudioStreamFormat::getSampleSize(const irrklang::SAudioStreamFormat& format)
{
	return format.getSampleSize();
}

irrklang::ik_s32 ikProxy::SAudioStreamFormat::getFrameSize(const irrklang::SAudioStreamFormat& format)
{
	return format.getFrameSize();
}

irrklang::ik_s32 ikProxy::SAudioStreamFormat::getSampleDataSize(const irrklang::SAudioStreamFormat& format)
{
	return format.getSampleDataSize();
}

irrklang::ik_s32 ikProxy::SAudioStreamFormat::getBytesPerSecond(const irrklang::SAudioStreamFormat& format)
{
	return format.getBytesPerSecond();
}

void* ikProxy::SInternalAudioInterface::getIDirectSound(const irrklang::SInternalAudioInterface& i)
{
	return i.pIDirectSound;
}

void* ikProxy::SInternalAudioInterface::getIDirectSound8(const irrklang::SInternalAudioInterface& i)
{
	return i.pIDirectSound8;
}

void* ikProxy::SInternalAudioInterface::getWinMM_HWaveOut(const irrklang::SInternalAudioInterface& i)
{
	return i.pWinMM_HWaveOut;
}

void* ikProxy::SInternalAudioInterface::getALSA_SND_PCM(const irrklang::SInternalAudioInterface& i)
{
	return i.pALSA_SND_PCM;
}

irrklang::ik_u32 ikProxy::SInternalAudioInterface::getCoreAudioDeviceID(const irrklang::SInternalAudioInterface& i)
{
	return i.pCoreAudioDeciceID;
}

const char* ikProxy::SoundEngine::getDriverName(irrklang::ISoundEngine* engine)
{
	return engine->getDriverName();
}

irrklang::ISound* ikProxy::SoundEngine::play2DFileName(
	irrklang::ISoundEngine* engine,
	const char* soundFileName,
	bool playLooped,
	bool startPaused,
	bool track,
	irrklang::E_STREAM_MODE streamMode,
	bool enableSoundEffects
)
{
	return engine->play2D(soundFileName, playLooped, startPaused, track, streamMode, enableSoundEffects);
}

irrklang::ISound* ikProxy::SoundEngine::play2DSoundSource(
	irrklang::ISoundEngine* engine,
	irrklang::ISoundSource* source,
	bool playLooped ,
	bool startPaused,
	bool track,
	bool enableSoundEffects
)
{
	return engine->play2D(source, playLooped, startPaused, track, enableSoundEffects);
}

irrklang::ISound* ikProxy::SoundEngine::play3DFileName(
	irrklang::ISoundEngine* engine,
	const char* soundFileName, 
	irrklang::vec3df pos,
	bool playLooped , 
	bool startPaused,
	bool track,
	irrklang::E_STREAM_MODE streamMode,
	bool enableSoundEffects
)
{
	return engine->play3D(soundFileName, pos, playLooped, startPaused, track, streamMode, enableSoundEffects);
}


irrklang::ISound* ikProxy::SoundEngine::play3DSoundSource(
	irrklang::ISoundEngine* engine,
	irrklang::ISoundSource* source, 
	irrklang::vec3df pos,
	bool playLooped ,
	bool startPaused,
	bool track,
	bool enableSoundEffects
)
{
	return engine->play3D(source, pos, playLooped, startPaused, track, enableSoundEffects);
}


void ikProxy::SoundEngine::stopAllSounds(irrklang::ISoundEngine* engine)
{
	engine->stopAllSounds();
}


void  ikProxy::SoundEngine::setAllSoundsPaused(irrklang::ISoundEngine* engine, bool bPaused)
{
	engine->setAllSoundsPaused(bPaused);
}

irrklang::ISoundSource* ikProxy::SoundEngine::getSoundSourceByName(irrklang::ISoundEngine* engine, const char* soundName, bool addIfNotFound)
{
	return engine->getSoundSource(soundName, addIfNotFound);
}

irrklang::ISoundSource* ikProxy::SoundEngine::getSoundSourceByIndex(irrklang::ISoundEngine* engine, int index)
{
	return engine->getSoundSource(index);
}

int ikProxy::SoundEngine::getSoundSourceCount(irrklang::ISoundEngine* engine)
{
	return engine->getSoundSourceCount();
}

irrklang::ISoundSource*  ikProxy::SoundEngine::addSoundSourceFromFile(irrklang::ISoundEngine* engine, const char* fileName, irrklang::E_STREAM_MODE mode, bool preload)
{
	return engine->addSoundSourceFromFile(fileName, mode, preload);
}

irrklang::ISoundSource* ikProxy::SoundEngine::addSoundSourceFromMemory(irrklang::ISoundEngine* engine, void* memory, int sizeInBytes, const char* soundName, bool copyMemory)
{
	return engine->addSoundSourceFromMemory(memory, sizeInBytes, soundName, copyMemory);
}

irrklang::ISoundSource*  ikProxy::SoundEngine::addSoundSourceFromPCMData(
	irrklang::ISoundEngine* engine,
	void* memory, 
	int sizeInBytes, 
	const char* soundName, 
	const irrklang::SAudioStreamFormat& format,
	bool copyMemory
)
{
	return engine->addSoundSourceFromPCMData(memory, sizeInBytes, soundName, format, copyMemory);
}

irrklang::ISoundSource* ikProxy::SoundEngine::addSoundSourceAlias(irrklang::ISoundEngine* engine, irrklang::ISoundSource* baseSource, const char* soundName)
{
	return engine->addSoundSourceAlias(baseSource, soundName);
}

void ikProxy::SoundEngine::removeSoundSource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source)
{
	engine->removeSoundSource(source);
}

void ikProxy::SoundEngine::removeSoundSourceByName(irrklang::ISoundEngine* engine, const char* name)
{
	engine->removeSoundSource(name);
}

void ikProxy::SoundEngine::removeAllSoundSources(irrklang::ISoundEngine* engine)
{
	engine->removeAllSoundSources();
}

void ikProxy::SoundEngine::setSoundVolume(irrklang::ISoundEngine* engine, float volume)
{
	engine->setSoundVolume(volume);
}

float ikProxy::SoundEngine::getSoundVolume(irrklang::ISoundEngine* engine)
{
	return engine->getSoundVolume();
}

void ikProxy::SoundEngine::setListenerPosition(
	irrklang::ISoundEngine* engine,
	const irrklang::vec3df& pos,
	const irrklang::vec3df& lookdir,
	const irrklang::vec3df& velPerSecond,
	const irrklang::vec3df& upVector
)
{
	engine->setListenerPosition(pos, lookdir, velPerSecond, upVector);
}

void ikProxy::SoundEngine::updateSoundEngine(irrklang::ISoundEngine* engine)
{
	engine->update();
}


void ikProxy::SoundEngine::grabSoundEngine(irrklang::ISoundEngine* engine)
{
	engine->grab();
}

void ikProxy::SoundEngine::dropSoundEngine(irrklang::ISoundEngine* engine)
{
	engine->drop();
}

bool ikProxy::SoundEngine::isCurrentlyPlayingByName(irrklang::ISoundEngine* engine, const char* soundName)
{
	return engine->isCurrentlyPlaying(soundName);
}

bool ikProxy::SoundEngine::isCurrentlyPlayingBySource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source)
{
	return engine->isCurrentlyPlaying(source);
}

bool ikProxy::SoundEngine::isMultiThreaded(irrklang::ISoundEngine* engine)
{
	return engine->isMultiThreaded();
}

void ikProxy::SoundEngine::setDefault3DSoundMinDistance(irrklang::ISoundEngine* engine, float minDistance)
{
	engine->setDefault3DSoundMinDistance(minDistance);
}

float ikProxy::SoundEngine::getDefault3DSoundMinDistance(irrklang::ISoundEngine* engine)
{
	return engine->getDefault3DSoundMinDistance();
}

void ikProxy::SoundEngine::setDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine, float maxDistance)
{
	engine->setDefault3DSoundMaxDistance(maxDistance);
}

float ikProxy::SoundEngine::getDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine)
{
	return engine->getDefault3DSoundMaxDistance();
}

void ikProxy::SoundEngine::setRolloffFactor(irrklang::ISoundEngine* engine, float rolloff)
{
	engine->setRolloffFactor(rolloff);
}

void ikProxy::SoundEngine::setDopplerEffectParameters(irrklang::ISoundEngine* engine, float dopplerFactor, float distanceFactor)
{
	engine->setDopplerEffectParameters(dopplerFactor, distanceFactor);
}

bool ikProxy::SoundEngine::loadPlugins(irrklang::ISoundEngine* engine, const char* path)
{
	return engine->loadPlugins(path);
}

const irrklang::SInternalAudioInterface& ikProxy::SoundEngine::getInternalAudioInterface(irrklang::ISoundEngine* engine)
{
	return engine->getInternalAudioInterface();
}

int ikProxy::SoundDeviceList::getDeviceCount(irrklang::ISoundDeviceList* list)
{
	return list->getDeviceCount();
}

const char*  ikProxy::SoundDeviceList::getDeviceID(irrklang::ISoundDeviceList* list, int index)
{
	return list->getDeviceID(index);
}

const char* KDECL ikProxy::SoundDeviceList::getDeviceDescription(irrklang::ISoundDeviceList* list, int index)
{
	return list->getDeviceDescription(index);
}

void ikProxy::SoundDeviceList::grabSoundDeviceList(irrklang::ISoundDeviceList* list)
{
	list->grab();
}

void ikProxy::SoundDeviceList::dropSoundDeviceList(irrklang::ISoundDeviceList* list)
{
	list->drop();
}



BOOL APIENTRY DllMain( HMODULE,
                       DWORD,
                       LPVOID
                     )
{
    return TRUE;
}

