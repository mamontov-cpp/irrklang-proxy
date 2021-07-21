#pragma once

#include <irrKlang.h>
#include <functional>

#ifndef USE_STATIC 
	#ifdef IRRKLANGPROXY_EXPORTS
		// ReSharper disable once IdentifierTypo
		#define IPAPI __declspec(dllexport)  // NOLINT(cppcoreguidelines-macro-usage)
	#else
		// ReSharper disable once IdentifierTypo
		#define IPAPI __declspec(dllimport)  // NOLINT(cppcoreguidelines-macro-usage)
	#endif
#else
	#define IPAPI
#endif

// ReSharper disable once IdentifierTypo
#define KDECL __cdecl // NOLINT(cppcoreguidelines-macro-usage)
extern "C"
{
namespace irrklangProxy
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

IPAPI void KDECL grabRefCounted(irrklang::IRefCounted* p);
IPAPI void KDECL dropRefCounted(irrklang::IRefCounted* p);
	
IPAPI void KDECL grabVirtualRefCounted(irrklang::IVirtualRefCounted* p);
IPAPI void KDECL dropVirtualRefCounted(irrklang::IVirtualRefCounted* p);

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

typedef void (*dtorFn)(void* user_data);

namespace IAudioStream
{
	typedef irrklang::SAudioStreamFormat (*getFormatFn)(void* user_data);
	typedef bool (*setPositionFn)(void* user_data, irrklang::ik_s32 pos);
	typedef bool (*getIsSeekingSupportedFn)(void* user_data);
	typedef irrklang::ik_s32 (*readFramesFn)(void* user_data, void* target, irrklang::ik_s32 frameCountToRead);

	IPAPI void KDECL grabAudioStream(irrklang::IAudioStream* stream);
	IPAPI void KDECL dropAudioStream(irrklang::IAudioStream* stream);

	IPAPI irrklang::IAudioStream* KDECL makeAudioStream(
		void* user_data, 
		irrklangProxy::dtorFn dtor, getFormatFn getFormat, 
		irrklangProxy::IAudioStream::setPositionFn setPosition, 
		irrklangProxy::IAudioStream::getIsSeekingSupportedFn getIsSeekingSupported, 
		irrklangProxy::IAudioStream::readFramesFn readFrames
	);

	IPAPI irrklang::SAudioStreamFormat KDECL getFormat(irrklang::IAudioStream* stream);
	IPAPI bool KDECL setPosition(irrklang::IAudioStream* stream, irrklang::ik_s32 pos);
	IPAPI bool KDECL getIsSeekingSupported(irrklang::IAudioStream* stream);
	IPAPI irrklang::ik_s32 KDECL readFrames(irrklang::IAudioStream* stream, void* target, irrklang::ik_s32 frameCountToRead);
}

namespace IAudioStreamLoader
{
	typedef bool(*isALoadableFileExtensionFn)(void* user_data, const char* fileName);
	typedef irrklang::IAudioStream* (*createAudioStreamFn)(void* user_data, irrklang::IFileReader* file);

	IPAPI void KDECL grabAudioStreamLoader(irrklang::IAudioStreamLoader* stream);
	IPAPI void KDECL dropAudioStreamLoader(irrklang::IAudioStreamLoader* stream);

	IPAPI irrklang::IAudioStreamLoader* KDECL makeAudioStreamLoader(
		void* user_data, 
		irrklangProxy::dtorFn dtor, 
		irrklangProxy::IAudioStreamLoader::isALoadableFileExtensionFn isALoadableFileExtensionVal, 
		irrklangProxy::IAudioStreamLoader::createAudioStreamFn createAudioStreamVal
	);

	IPAPI bool KDECL isALoadableFileExtension(irrklang::IAudioStreamLoader* stream, const irrklang::ik_c8* fileName);
	IPAPI irrklang::IAudioStream* KDECL createAudioStream(irrklang::IAudioStreamLoader* stream, irrklang::IFileReader* reader);
}

namespace IFileReader
{
	typedef irrklang::ik_s32 (*readFn)(void* user_data, void* buffer, irrklang::ik_u32 sizeToRead);
	typedef bool (*seekFn)(void* user_data, irrklang::ik_s32 finalPos, bool relativeMovement);
	typedef irrklang::ik_s32 (*getSizeFn)(void* user_data);
	typedef irrklang::ik_s32 (*getPosFn)(void* user_data);
	typedef const irrklang::ik_c8* (*getFileNameFn)(void* user_data);

	IPAPI void KDECL grabFileReader(irrklang::IFileReader* reader);
	IPAPI void KDECL dropFileReader(irrklang::IFileReader* reader);

	IPAPI irrklang::IFileReader* KDECL makeFileReader(
		void* user_data, 
		irrklangProxy::dtorFn dtor, 
		irrklangProxy::IFileReader::readFn readVal, 
		irrklangProxy::IFileReader::seekFn seekVal,
		irrklangProxy::IFileReader::getSizeFn getSizeVal,
		irrklangProxy::IFileReader::getPosFn getPosVal,
		irrklangProxy::IFileReader::getFileNameFn getFileNameVal
	);

	IPAPI irrklang::ik_s32 KDECL read(irrklang::IFileReader* reader, void* buffer, irrklang::ik_u32 sizeToRead);
	IPAPI bool KDECL seek(irrklang::IFileReader* reader, irrklang::ik_s32 finalPos, bool relativeMovement = false);
	IPAPI irrklang::ik_s32 KDECL getSize(irrklang::IFileReader* reader);
	IPAPI irrklang::ik_s32 KDECL getPos(irrklang::IFileReader* reader);
	IPAPI const irrklang::ik_c8* KDECL getFileName(irrklang::IFileReader* reader);
}

namespace IFileFactory
{
	typedef irrklang::IFileReader* (*createFileReaderFn)(void* user_data, const irrklang::ik_c8* filename);

	IPAPI void KDECL grabFileFactory(irrklang::IFileFactory* factory);
	IPAPI void KDECL dropFileFactory(irrklang::IFileFactory* factory);
	
	IPAPI irrklang::IFileFactory* KDECL makeFileFactory(
		void* user_data, 
		irrklangProxy::dtorFn dtor, 
		irrklangProxy::IFileFactory::createFileReaderFn createFileReaderVal
	);

	IPAPI irrklang::IFileReader* KDECL createFileReader(irrklang::IFileFactory* factory, const irrklang::ik_c8* filename);
}

namespace ISoundMixedOutputReceiver
{
	typedef void (*onAudioDataReadyFn)(void* user_data, const void* data, int byteCount, int playbackrate);
	
	IPAPI irrklang::ISoundMixedOutputReceiver* KDECL makeSoundMixedOutputReceiver(
		void* user_data, 
		irrklangProxy::dtorFn dtor, 
		irrklangProxy::ISoundMixedOutputReceiver::onAudioDataReadyFn onAudioDataReadyVal
	);

	IPAPI void KDECL onAudioDataReady(irrklang::ISoundMixedOutputReceiver* receiver, const void* data, int byteCount, int playbackrate);
}


namespace ICapturedAudioDataReceiver
{
	typedef void (*onReceiveAudioDataStreamChunkFn)(void* user_data, unsigned char* audioData, unsigned long lengthInBytes);

	IPAPI irrklang::ICapturedAudioDataReceiver* KDECL makeCapturedAudioDataReceiver(
		void* user_data,
		irrklangProxy::dtorFn dtor,
		irrklangProxy::ICapturedAudioDataReceiver::onReceiveAudioDataStreamChunkFn onReceiveAudioDataStreamChunkVal
	);

	IPAPI void KDECL grabCapturedAudioDataReceiver(irrklang::ICapturedAudioDataReceiver* receiver);
	IPAPI void KDECL dropCapturedAudioDataReceiver(irrklang::ICapturedAudioDataReceiver* receiver);
	
	IPAPI void KDECL onReceiveAudioDataStreamChunk(irrklang::ICapturedAudioDataReceiver* receiver, unsigned char* audioData, unsigned long lengthInBytes);
}

namespace ISoundStopEventReceiver
{
	typedef void(*onSoundStoppedFn)(void* user_data, irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* receiverUserData);

	
	IPAPI irrklang::ISoundStopEventReceiver* KDECL makeSoundStopEventReceiver(
		void* user_data,
		irrklangProxy::dtorFn dtor,
		irrklangProxy::ISoundStopEventReceiver::onSoundStoppedFn onSoundStoppedVal
	);

	void onSoundStopped(irrklang::ISoundStopEventReceiver* receiver, irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* userData);
}
	
namespace ISoundEngine
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
	const irrklang::vec3df& pos,
	bool playLooped = false,
	bool startPaused = false,
	bool track = false,
	irrklang::E_STREAM_MODE streamMode = irrklang::ESM_AUTO_DETECT,
	bool enableSoundEffects = false
);

IPAPI irrklang::ISound* KDECL play3DSoundSource(
	irrklang::ISoundEngine* engine,
	irrklang::ISoundSource* source,
	const irrklang::vec3df& pos,
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

IPAPI void KDECL registerAudioStreamLoader(irrklang::ISoundEngine* engine, irrklang::IAudioStreamLoader* loader);

IPAPI bool KDECL isMultiThreaded(irrklang::ISoundEngine* engine);

IPAPI void KDECL addFileFactory(irrklang::ISoundEngine* engine, irrklang::IFileFactory* fileFactory);

IPAPI void KDECL setDefault3DSoundMinDistance(irrklang::ISoundEngine* engine, float minDistance);
IPAPI float KDECL getDefault3DSoundMinDistance(irrklang::ISoundEngine* engine);

IPAPI void KDECL setDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine, float maxDistance);
IPAPI float KDECL getDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine);

IPAPI void KDECL setRolloffFactor(irrklang::ISoundEngine* engine, float rolloff);

IPAPI void KDECL setDopplerEffectParameters(irrklang::ISoundEngine* engine, float dopplerFactor = 1.0f, float distanceFactor = 1.0f);
IPAPI bool KDECL loadPlugins(irrklang::ISoundEngine* engine, const char* path);

IPAPI const irrklang::SInternalAudioInterface* KDECL getInternalAudioInterface(irrklang::ISoundEngine* engine);

IPAPI bool KDECL setMixedDataOutputReceiver(irrklang::ISoundEngine* engine, irrklang::ISoundMixedOutputReceiver* receiver);
}

namespace ISoundDeviceList
{
IPAPI int KDECL getDeviceCount(irrklang::ISoundDeviceList* list);
IPAPI const char* KDECL getDeviceID(irrklang::ISoundDeviceList* list, int index);
IPAPI const char* KDECL getDeviceDescription(irrklang::ISoundDeviceList* list, int index);
	
IPAPI void KDECL grabSoundDeviceList(irrklang::ISoundDeviceList* list);
IPAPI void KDECL dropSoundDeviceList(irrklang::ISoundDeviceList* list);
}

namespace IAudioRecorder
{
IPAPI bool KDECL startRecordingBufferedAudio(irrklang::IAudioRecorder* recorder, irrklang::ik_s32 sampleRate = 22000, irrklang::ESampleFormat sampleFormat = irrklang::ESF_S16, irrklang::ik_s32 channelCount = 1);
IPAPI bool KDECL startRecordingCustomHandledAudio(irrklang::IAudioRecorder* recorder, irrklang::ICapturedAudioDataReceiver* receiver, irrklang::ik_s32 sampleRate = 22000, irrklang::ESampleFormat sampleFormat = irrklang::ESF_S16, irrklang::ik_s32 channelCount = 1);
IPAPI void KDECL stopRecordingAudio(irrklang::IAudioRecorder* recorder);
IPAPI irrklang::ISoundSource* KDECL addSoundSourceFromRecordedAudio(irrklang::IAudioRecorder* recorder, const char* soundName);
IPAPI void KDECL clearRecordedAudioDataBuffer(irrklang::IAudioRecorder* recorder);
IPAPI bool KDECL isRecording(irrklang::IAudioRecorder* recorder);
IPAPI irrklang::SAudioStreamFormat KDECL getAudioFormat(irrklang::IAudioRecorder* recorder);
IPAPI void* KDECL getRecordedAudioData(irrklang::IAudioRecorder* recorder);
IPAPI const char* KDECL getAudioRecorderDriverName(irrklang::IAudioRecorder* recorder);
}

namespace ISoundEffectControl
{
IPAPI void KDECL disableAllEffects(irrklang::ISoundEffectControl* control);
IPAPI bool KDECL enableChorusSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fWetDryMix = 50,
	irrklang::ik_f32 fDepth = 10,
	irrklang::ik_f32 fFeedback = 25,
	irrklang::ik_f32 fFrequency = 1.1f,
	bool sinusWaveForm = true,
	irrklang::ik_f32 fDelay = 16,
	irrklang::ik_s32 lPhase = 90
);

IPAPI void KDECL disableChorusSoundEffect(irrklang::ISoundEffectControl* control);
IPAPI bool KDECL isChorusSoundEffectEnabled(irrklang::ISoundEffectControl* control);
IPAPI bool KDECL enableCompressorSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fGain = 0,
	irrklang::ik_f32 fAttack = 10,
	irrklang::ik_f32 fRelease = 200,
	irrklang::ik_f32 fThreshold = -20,
	irrklang::ik_f32 fRatio = 3,
	irrklang::ik_f32 fPredelay = 4
);
IPAPI void KDECL disableCompressorSoundEffect(irrklang::ISoundEffectControl* control);
IPAPI bool KDECL isCompressorSoundEffectEnabled(irrklang::ISoundEffectControl* control);
IPAPI bool KDECL enableDistortionSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fGain = -18,
	irrklang::ik_f32 fEdge = 15,
	irrklang::ik_f32 fPostEQCenterFrequency = 2400,
	irrklang::ik_f32 fPostEQBandwidth = 2400,
	irrklang::ik_f32 fPreLowpassCutoff = 8000
);

IPAPI void KDECL disableDistortionSoundEffect(irrklang::ISoundEffectControl* control);
IPAPI bool KDECL isDistortionSoundEffectEnabled(irrklang::ISoundEffectControl* control);
IPAPI bool KDECL enableEchoSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fWetDryMix = 50,
	irrklang::ik_f32 fFeedback = 50,
	irrklang::ik_f32 fLeftDelay = 500,
	irrklang::ik_f32 fRightDelay = 500,
	irrklang::ik_s32 lPanDelay = 0
);

IPAPI  void KDECL disableEchoSoundEffect(irrklang::ISoundEffectControl* control);
IPAPI  bool KDECL isEchoSoundEffectEnabled(irrklang::ISoundEffectControl* control);
IPAPI  bool KDECL enableFlangerSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fWetDryMix = 50,
	irrklang::ik_f32 fDepth = 100,
	irrklang::ik_f32 fFeedback = -50,
	irrklang::ik_f32 fFrequency = 0.25f,
	bool triangleWaveForm = true,
	irrklang::ik_f32 fDelay = 2,
	irrklang::ik_s32 lPhase = 0
);
IPAPI void KDECL disableFlangerSoundEffect(irrklang::ISoundEffectControl* control);
IPAPI bool KDECL isFlangerSoundEffectEnabled(irrklang::ISoundEffectControl* control);
IPAPI bool KDECL enableGargleSoundEffect(irrklang::ISoundEffectControl* control, irrklang::ik_s32 rateHz = 20, bool sinusWaveForm = true);
IPAPI void KDECL disableGargleSoundEffect(irrklang::ISoundEffectControl* control);
IPAPI bool KDECL isGargleSoundEffectEnabled(irrklang::ISoundEffectControl* control);

IPAPI bool KDECL enableI3DL2ReverbSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_s32 lRoom = -1000,
	irrklang::ik_s32 lRoomHF = -100,
	irrklang::ik_f32 flRoomRolloffFactor = 0,
	irrklang::ik_f32 flDecayTime = 1.49f,
	irrklang::ik_f32 flDecayHFRatio = 0.83f,
	irrklang::ik_s32 lReflections = -2602,
	irrklang::ik_f32 flReflectionsDelay = 0.007f,
	irrklang::ik_s32 lReverb = 200,
	irrklang::ik_f32 flReverbDelay = 0.011f,
	irrklang::ik_f32 flDiffusion = 100.0f,
	irrklang::ik_f32 flDensity = 100.0f,
	irrklang::ik_f32 flHFReference = 5000.0f
);
IPAPI void  KDECL disableI3DL2ReverbSoundEffect(irrklang::ISoundEffectControl* control);
IPAPI bool  KDECL isI3DL2ReverbSoundEffectEnabled(irrklang::ISoundEffectControl* control);
IPAPI bool  KDECL enableParamEqSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fCenter = 8000,
	irrklang::ik_f32 fBandwidth = 12,
	irrklang::ik_f32 fGain = 0
);
IPAPI void  KDECL disableParamEqSoundEffect(irrklang::ISoundEffectControl* control);
IPAPI bool  KDECL isParamEqSoundEffectEnabled(irrklang::ISoundEffectControl* control);
IPAPI bool  KDECL enableWavesReverbSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fInGain = 0,
	irrklang::ik_f32 fReverbMix = 0,
	irrklang::ik_f32 fReverbTime = 1000,
	irrklang::ik_f32 fHighFreqRTRatio = 0.001f
);
IPAPI void  KDECL disableWavesReverbSoundEffect(irrklang::ISoundEffectControl* control);
IPAPI bool  KDECL isWavesReverbSoundEffectEnabled(irrklang::ISoundEffectControl* control);
}

namespace ISoundSource
{
IPAPI void KDECL grabSoundSource(irrklang::ISoundSource* source);
IPAPI void KDECL dropSoundSource(irrklang::ISoundSource* source);


IPAPI const irrklang::ik_c8* KDECL  getNameForSoundSource(irrklang::ISoundSource* source);
IPAPI void KDECL  setStreamMode(irrklang::ISoundSource* source, irrklang::E_STREAM_MODE mode);
IPAPI irrklang::E_STREAM_MODE KDECL  getStreamMode(irrklang::ISoundSource* source);

IPAPI irrklang::ik_u32 KDECL  getPlayLength(irrklang::ISoundSource* source);

IPAPI irrklang::SAudioStreamFormat KDECL  getAudioFormatForSoundSource(irrklang::ISoundSource* source);
IPAPI bool KDECL  getIsSeekingSupportedForSoundSource(irrklang::ISoundSource* source);
IPAPI void KDECL  setDefaultVolume(irrklang::ISoundSource* source, irrklang::ik_f32 volume = 1.0f);
IPAPI irrklang::ik_f32  KDECL getDefaultVolume(irrklang::ISoundSource* source);
IPAPI void KDECL  setDefaultMinDistance(irrklang::ISoundSource* source, irrklang::ik_f32 minDistance);
IPAPI irrklang::ik_f32 KDECL  getDefaultMinDistance(irrklang::ISoundSource* source);
IPAPI void KDECL  setDefaultMaxDistance(irrklang::ISoundSource* source, irrklang::ik_f32 maxDistance);
IPAPI irrklang::ik_f32 KDECL getDefaultMaxDistance(irrklang::ISoundSource* source);
IPAPI void KDECL  forceReloadAtNextUse(irrklang::ISoundSource* source);
IPAPI void KDECL setForcedStreamingThreshold(irrklang::ISoundSource* source, irrklang::ik_s32 thresholdBytes);
IPAPI irrklang::ik_s32 KDECL getForcedStreamingThreshold(irrklang::ISoundSource* source);
IPAPI void* KDECL getSampleData(irrklang::ISoundSource* source);
}

}

}



namespace irrklangProxy
{

template<int Id = 0>
class AudioStream  // NOLINT(cppcoreguidelines-special-member-functions)
{
public: 
	virtual ~AudioStream() {}
	virtual irrklang::SAudioStreamFormat getFormat() = 0;
	virtual bool setPosition(irrklang::ik_s32 pos) = 0;
	virtual bool getIsSeekingSupported() { return true; }
	virtual irrklang::ik_s32 readFrames(void* target, irrklang::ik_s32 frameCountToRead) = 0;
};

template<int Id = 0>
class AudioStreamLoader  // NOLINT(cppcoreguidelines-special-member-functions)
{
public: 
	virtual ~AudioStreamLoader() {}
	virtual bool isALoadableFileExtension(const irrklang::ik_c8* fileName) = 0;
	virtual irrklang::IAudioStream* createAudioStream(irrklang::IFileReader* file) = 0;
};

template<int Id = 0>
class FileReader  // NOLINT(cppcoreguidelines-special-member-functions)
{
public: 
	virtual ~FileReader() {}
	virtual irrklang::ik_s32 read(void* buffer, irrklang::ik_u32 sizeToRead) = 0;
	virtual bool seek(irrklang::ik_s32 finalPos, bool relativeMovement = false) = 0;
	virtual irrklang::ik_s32 getSize() = 0;
	virtual irrklang::ik_s32 getPos() = 0;
	virtual const irrklang::ik_c8* getFileName() = 0;
};

template<int Id = 0>
class FileFactory  // NOLINT(cppcoreguidelines-special-member-functions)
{
public: 
	virtual ~FileFactory() {}
	virtual irrklang::IFileReader* createFileReader(const irrklang::ik_c8* filename) = 0;
};

template<int Id = 0>
class SoundMixedOutputReceiver  // NOLINT(cppcoreguidelines-special-member-functions)
{
public: 
	virtual ~SoundMixedOutputReceiver() {}
	virtual void OnAudioDataReady(const void* data, int byteCount, int playbackrate) = 0;
};

template<int Id = 0>
class CapturedAudioDataReceiver  // NOLINT(cppcoreguidelines-special-member-functions)
{
public: 
	virtual ~CapturedAudioDataReceiver() {}
	virtual void OnReceiveAudioDataStreamChunk(unsigned char* audioData, unsigned long lengthInBytes) = 0;
};

template<int Id = 0>
class SoundStopEventReceiver  // NOLINT(cppcoreguidelines-special-member-functions)
{
public: 
	virtual ~SoundStopEventReceiver() {}
	virtual void OnSoundStopped(irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* userData) = 0;
};

template<typename T, int Id = 0>
struct make_stream
{
	template<typename... Ts>
	static irrklang::IAudioStream* exec(Ts&&... args)
	{
		static_assert(std::is_base_of<irrklangProxy::AudioStream<Id>, T>::value, "type parameter of this class must derive from irrklangProxy::AudioStream");
		T* object = new T(std::forward<Ts>(args));
		return irrklangProxy::IAudioStream::makeAudioStream(
			object, 
			[](void* user_data) -> void { delete static_cast<T*>(user_data);  },
			[](void* user_data) -> irrklang::SAudioStreamFormat { return static_cast<T*>(user_data)->getFormat();  },
			[](void* user_data, irrklang::ik_s32 pos) -> bool { return static_cast<T*>(user_data)->setPosition(pos);  },
			[](void* user_data) -> bool { return static_cast<T*>(user_data)->getIsSeekingSupported(); },
			[](void* user_data, void * target, irrklang::ik_s32 frameCountToRead) -> bool { return static_cast<T*>(user_data)->readFrames(target, frameCountToRead); }
		);
	}
};

template<typename T, int Id = 0>
struct make_stream_loader
{
	template<typename... Ts>
	static irrklang::IAudioStreamLoader* exec(Ts&&... args)
	{
		static_assert(std::is_base_of<irrklangProxy::AudioStreamLoader<Id>, T>::value, "type parameter of this class must derive from irrklangProxy::AudioStreamLoader");
		T* object = new T(std::forward<Ts>(args));
		return irrklangProxy::IAudioStreamLoader::makeAudioStreamLoader(
			object, 
			[](void* user_data) -> void { delete static_cast<T*>(user_data);  },
			[](void* user_data, const irrklang::ik_c8* fileName) -> bool { return static_cast<T*>(user_data)->isALoadableFileExtension(fileName);  },
			[](void* user_data, irrklang::IFileReader* file) -> irrklang::IAudioStream* { return static_cast<T*>(user_data)->createAudioStream(file);  }
		);
	}
};

template<typename T, int Id = 0>
struct make_file_reader
{
	template<typename... Ts>
	static irrklang::IFileReader* exec(Ts&&... args)
	{
		static_assert(std::is_base_of<irrklangProxy::FileReader<Id>, T>::value, "type parameter of this class must derive from irrklangProxy::FileReader");
		T* object = new T(std::forward<Ts>(args));
		return irrklangProxy::IFileReader::makeFileReader(
			object, 
			[](void* user_data) -> void { delete static_cast<T*>(user_data);  },
			[](void* user_data, void* buffer, irrklang::ik_u32 sizeToRead) -> irrklang::ik_s32 { return static_cast<T*>(user_data)->read(buffer, sizeToRead);  },
			[](void* user_data, irrklang::ik_s32 finalPos, bool relativeMovement) -> bool { return static_cast<T*>(user_data)->seek(finalPos, relativeMovement);  },
			[](void* user_data) -> irrklang::ik_s32 { return static_cast<T*>(user_data)->getSize();  },
			[](void* user_data) -> irrklang::ik_s32 { return static_cast<T*>(user_data)->getPos();  },
			[](void* user_data) -> const irrklang::ik_c8* { return static_cast<T*>(user_data)->getFileName();  }
		);
	}
};

template<typename T, int Id = 0>
struct make_file_factory
{
	template<typename... Ts>
	static irrklang::IFileFactory* exec(Ts&&... args)
	{
		static_assert(std::is_base_of<irrklangProxy::FileFactory<Id>, T>::value, "type parameter of this class must derive from irrklangProxy::FileFactory");
		T* object = new T(std::forward<Ts>(args));
		return irrklangProxy::IFileFactory::makeFileFactory(
			object, 
			[](void* user_data) -> void { delete static_cast<T*>(user_data);  },
			[](void* user_data, const irrklang::ik_c8* filename) -> irrklang::IFileReader* { return static_cast<T*>(user_data)->createFileReader(filename);  }
		);
	}
};

template<typename T, int Id = 0>
struct make_sound_mixed_output_receiver
{
	template<typename... Ts>
	static irrklang::ISoundMixedOutputReceiver* exec(Ts&&... args)
	{
		static_assert(std::is_base_of<irrklangProxy::SoundMixedOutputReceiver<Id>, T>::value, "type parameter of this class must derive from irrklangProxy::SoundMixedOutputReceiver");
		T* object = new T(std::forward<Ts>(args));
		return irrklangProxy::ISoundMixedOutputReceiver::makeSoundMixedOutputReceiver(
			object, 
			[](void* user_data) -> void { delete static_cast<T*>(user_data);  },
			[](void* user_data, const void* data, int byteCount, int playbackrate) -> void { static_cast<T*>(user_data)->OnAudioDataReady(data, byteCount, playbackrate);  }
		);
	}
};


template<typename T, int Id = 0>
struct make_captured_audio_data_receiver
{
	template<typename... Ts>
	static irrklang::ICapturedAudioDataReceiver* exec(Ts&&... args)
	{
		static_assert(std::is_base_of<irrklangProxy::CapturedAudioDataReceiver<Id>, T>::value, "type parameter of this class must derive from irrklangProxy::CapturedAudioDataReceiver");
		T* object = new T(std::forward<Ts>(args));
		return irrklangProxy::ICapturedAudioDataReceiver::makeCapturedAudioDataReceiver(
			object, 
			[](void* user_data) -> void { delete static_cast<T*>(user_data);  },
			[](void* user_data, unsigned char* audioData, unsigned long lengthInBytes) -> void { static_cast<T*>(user_data)->OnReceiveAudioDataStreamChunk(audioData,  lengthInBytes);  }
		);
	}
};

template<typename T, int Id = 0>
struct make_sound_stop_event_receiver
{
	template<typename... Ts>
	static irrklang::ISoundStopEventReceiver* exec(Ts&&... args)
	{
		static_assert(std::is_base_of<irrklangProxy::SoundStopEventReceiver<Id>, T>::value, "type parameter of this class must derive from irrklangProxy::SoundStopEventReceiver");
		T* object = new T(std::forward<Ts>(args));
		return irrklangProxy::ISoundStopEventReceiver::makeSoundStopEventReceiver(
			object, 
			[](void* user_data) -> void { delete static_cast<T*>(user_data);  },
			[](void* user_data, irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* userData) -> void { static_cast<T*>(user_data)->OnSoundStopped(sound,  reason, userData);  }
		);
	}
};
	
}