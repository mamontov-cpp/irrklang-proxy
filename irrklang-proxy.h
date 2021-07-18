#pragma once

#include <irrKlang.h>

#ifdef IRRKLANGPROXY_EXPORTS
	// ReSharper disable once IdentifierTypo
	#define IPAPI __declspec(dllexport)  // NOLINT(cppcoreguidelines-macro-usage)
#else
	// ReSharper disable once IdentifierTypo
	#define IPAPI __declspec(dllimport)  // NOLINT(cppcoreguidelines-macro-usage)
#endif
// ReSharper disable once IdentifierTypo
#define KDECL __cdecl // NOLINT(cppcoreguidelines-macro-usage)

extern "C"
{
namespace ikProxy
{

IPAPI irrklang::ISoundEngine* KDECL createIrrKlangDevice(irrklang::E_SOUND_OUTPUT_DRIVER driver = irrklang::ESOD_AUTO_DETECT,
	int options = irrklang::ESEO_DEFAULT_OPTIONS,
	const char* deviceID = nullptr,
	const char* sdk_version_do_not_use = IRR_KLANG_VERSION
);

IPAPI irrklang::ISoundDeviceList* KDECL createSoundDeviceList(
	irrklang::E_SOUND_OUTPUT_DRIVER driver = irrklang::ESOD_AUTO_DETECT,
	const char* sdk_version_do_not_use = IRR_KLANG_VERSION
);

IPAPI irrklang::IAudioRecorder* KDECL createIrrKlangAudioRecorder(
	irrklang::ISoundEngine* irrKlangDeviceForPlayback,
	irrklang::E_SOUND_OUTPUT_DRIVER driver = irrklang::ESOD_AUTO_DETECT,
	const char* deviceID = nullptr,
	const char* sdk_version_do_not_use = IRR_KLANG_VERSION
);

IPAPI irrklang::ISoundDeviceList* KDECL createAudioRecorderDeviceList(
	irrklang::E_SOUND_OUTPUT_DRIVER driver = irrklang::ESOD_AUTO_DETECT,
	const char* sdk_version_do_not_use = IRR_KLANG_VERSION
);

IPAPI bool KDECL makeUTF8fromUTF16string(
	const wchar_t* pInputString, char* pOutputBuffer, int outputBufferSize
);

namespace SAudioStreamFormat
{
	IPAPI irrklang::SAudioStreamFormat KDECL makeDefaultFormat();
	IPAPI irrklang::SAudioStreamFormat KDECL makeFormat(
		int channelCount,
		int frameCount,
		int sampleRate,
		irrklang::ESampleFormat sampleFormat
	);
	IPAPI void KDECL setChannelCount(irrklang::SAudioStreamFormat& format, int channelCount);
	IPAPI int  KDECL getChannelCount(const irrklang::SAudioStreamFormat& format);

	IPAPI void  KDECL setFrameCount(irrklang::SAudioStreamFormat& format, int frameCount);
	IPAPI int  KDECL getFrameCount(const irrklang::SAudioStreamFormat& format);

	IPAPI void  KDECL setSampleRate(irrklang::SAudioStreamFormat& format, int sampleRate);
	IPAPI int  KDECL getSampleRate(const irrklang::SAudioStreamFormat& format);

	IPAPI void  KDECL setSampleFormat(irrklang::SAudioStreamFormat& format, irrklang::ESampleFormat sampleFormat);
	IPAPI irrklang::ESampleFormat  KDECL getSampleFormat(const irrklang::SAudioStreamFormat& format);

	IPAPI irrklang::ik_s32  KDECL getSampleSize(const irrklang::SAudioStreamFormat& format);
	irrklang::ik_s32  KDECL getFrameSize(const irrklang::SAudioStreamFormat& format);
	irrklang::ik_s32  KDECL getSampleDataSize(const irrklang::SAudioStreamFormat& format);
	irrklang::ik_s32  KDECL getBytesPerSecond(const irrklang::SAudioStreamFormat& format);
	
}

namespace SInternalAudioInterface
{
	IPAPI void*  KDECL getIDirectSound(const irrklang::SInternalAudioInterface& i);
	IPAPI void*  KDECL getIDirectSound8(const irrklang::SInternalAudioInterface& i);
	IPAPI void*  KDECL getWinMM_HWaveOut(const irrklang::SInternalAudioInterface& i);
	IPAPI void*  KDECL getALSA_SND_PCM(const irrklang::SInternalAudioInterface& i);

	IPAPI irrklang::ik_u32  KDECL getCoreAudioDeviceID(const irrklang::SInternalAudioInterface& i);
	
}

namespace SoundEngine
{
IPAPI const char* KDECL getDriverName(irrklang::ISoundEngine* engine);
IPAPI irrklang::ISound* KDECL play2DFileName(
	irrklang::ISoundEngine* engine,
	const char* soundFileName,
	bool playLooped = false,
	bool startPaused = false,
	bool track = false,
	irrklang::E_STREAM_MODE streamMode = irrklang::ESM_AUTO_DETECT,
	bool enableSoundEffects = false
);

IPAPI irrklang::ISound* KDECL play2DSoundSource(
	irrklang::ISoundEngine* engine,
	irrklang::ISoundSource* source,
	bool playLooped = false,
	bool startPaused = false,
	bool track = false,
	bool enableSoundEffects = false
);

IPAPI irrklang::ISound* KDECL play3DFileName(
	irrklang::ISoundEngine* engine,
	const char* soundFileName,
	irrklang::vec3df pos,
	bool playLooped = false,
	bool startPaused = false,
	bool track = false,
	irrklang::E_STREAM_MODE streamMode = irrklang::ESM_AUTO_DETECT,
	bool enableSoundEffects = false
);

IPAPI irrklang::ISound* KDECL play3DSoundSource(
	irrklang::ISoundEngine* engine,
	irrklang::ISoundSource* source,
	irrklang::vec3df pos,
	bool playLooped = false,
	bool startPaused = false,
	bool track = false,
	bool enableSoundEffects = false
);

IPAPI void KDECL stopAllSounds(irrklang::ISoundEngine* engine);
IPAPI void KDECL setAllSoundsPaused(irrklang::ISoundEngine* engine, bool bPaused = true);


IPAPI irrklang::ISoundSource* KDECL getSoundSourceByName(irrklang::ISoundEngine* engine, const char* soundName, bool addIfNotFound = true);
IPAPI irrklang::ISoundSource* KDECL getSoundSourceByIndex(irrklang::ISoundEngine* engine, int index);

IPAPI int KDECL getSoundSourceCount(irrklang::ISoundEngine* engine);

IPAPI void KDECL grabSoundEngine(irrklang::ISoundEngine* engine);
IPAPI void KDECL dropSoundEngine(irrklang::ISoundEngine* engine);

IPAPI irrklang::ISoundSource* KDECL addSoundSourceFromFile(irrklang::ISoundEngine* engine, const char* fileName, irrklang::E_STREAM_MODE mode = irrklang::ESM_AUTO_DETECT, bool preload = false);
IPAPI irrklang::ISoundSource* KDECL addSoundSourceFromMemory(irrklang::ISoundEngine* engine, void* memory, int sizeInBytes, const char* soundName, bool copyMemory = true);

IPAPI irrklang::ISoundSource* KDECL addSoundSourceFromPCMData(
	irrklang::ISoundEngine* engine,
	void* memory, 
	int sizeInBytes, 
	const char* soundName, 
	const irrklang::SAudioStreamFormat& format,
	bool copyMemory = true
);

IPAPI irrklang::ISoundSource* KDECL addSoundSourceAlias(irrklang::ISoundEngine* engine, irrklang::ISoundSource* baseSource, const char* soundName);

IPAPI void KDECL removeSoundSource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source);
IPAPI void KDECL removeSoundSourceByName(irrklang::ISoundEngine* engine, const char* name);

IPAPI void KDECL removeAllSoundSources(irrklang::ISoundEngine* engine);
IPAPI void KDECL setSoundVolume(irrklang::ISoundEngine* engine, float volume);
IPAPI float KDECL getSoundVolume(irrklang::ISoundEngine* engine);

IPAPI void KDECL setListenerPosition(
	irrklang::ISoundEngine* engine,
	const irrklang::vec3df& pos,
	const irrklang::vec3df& lookdir,
	const irrklang::vec3df& velPerSecond = irrklang::vec3df(0, 0, 0),
	const irrklang::vec3df& upVector = irrklang::vec3df(0, 1, 0)
);

IPAPI void KDECL updateSoundEngine(irrklang::ISoundEngine* engine);

IPAPI bool KDECL isCurrentlyPlayingByName(irrklang::ISoundEngine* engine, const char* soundName);

IPAPI bool KDECL isCurrentlyPlayingBySource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source);

IPAPI bool KDECL isMultiThreaded(irrklang::ISoundEngine* engine);

IPAPI void KDECL setDefault3DSoundMinDistance(irrklang::ISoundEngine* engine, float minDistance);
IPAPI float KDECL getDefault3DSoundMinDistance(irrklang::ISoundEngine* engine);

IPAPI void KDECL setDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine, float maxDistance);
IPAPI float KDECL getDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine);

IPAPI void KDECL setRolloffFactor(irrklang::ISoundEngine* engine, float rolloff);

IPAPI void KDECL setDopplerEffectParameters(irrklang::ISoundEngine* engine, float dopplerFactor = 1.0f, float distanceFactor = 1.0f);
IPAPI bool KDECL loadPlugins(irrklang::ISoundEngine* engine, const char* path);

IPAPI const irrklang::SInternalAudioInterface& KDECL getInternalAudioInterface(irrklang::ISoundEngine* engine);

}

namespace SoundDeviceList
{
IPAPI int KDECL getDeviceCount(irrklang::ISoundDeviceList* list);
IPAPI const char* KDECL getDeviceID(irrklang::ISoundDeviceList* list, int index);
IPAPI const char* KDECL getDeviceDescription(irrklang::ISoundDeviceList* list, int index);
	
IPAPI void KDECL grabSoundDeviceList(irrklang::ISoundDeviceList* list);
IPAPI void KDECL dropSoundDeviceList(irrklang::ISoundDeviceList* list);

}

}

}
