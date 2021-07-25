#pragma once

#include <irrKlang.h>
#include <functional>

// Don't use static versions only 
#ifndef _MSC_VER
	#ifndef __MINGW64__
		#define IRRKLANG_PROXY_USE_STATIC 1
	#endif
#endif 


#ifndef IRRKLANG_PROXY_USE_STATIC
	#ifdef IRRKLANGPROXY_EXPORTS
		// ReSharper disable once IdentifierTypo
		#define IRRKLANG_PROXY_API __declspec(dllexport)  // NOLINT(cppcoreguidelines-macro-usage)
	#else
		// ReSharper disable once IdentifierTypo
		#define IRRKLANG_PROXY_API __declspec(dllimport)  // NOLINT(cppcoreguidelines-macro-usage)
	#endif
#else
	#define IRRKLANG_PROXY_API
#endif

// ReSharper disable once IdentifierTypo
#if (defined(_MSC_VER) ||  defined(__MINGW64__) ||  defined(__MINGW32__))
	#define IRRKLANG_PROXY_CALLCONV __cdecl // NOLINT(cppcoreguidelines-macro-usage)
#else
	#define IRRKLANG_PROXY_CALLCONV // __attribute__((cdecl))
#endif 


namespace irrklangProxy
{
typedef void (*dtorFn)(void* user_data);

namespace IAudioStream
{
	typedef irrklang::SAudioStreamFormat(*getFormatFn)(void* user_data);
	typedef bool(*setPositionFn)(void* user_data, irrklang::ik_s32 pos);
	typedef bool(*getIsSeekingSupportedFn)(void* user_data);
	typedef irrklang::ik_s32(*readFramesFn)(void* user_data, void* target, irrklang::ik_s32 frameCountToRead);
}

namespace IAudioStreamLoader
{
	typedef bool(*isALoadableFileExtensionFn)(void* user_data, const char* fileName);
	typedef irrklang::IAudioStream* (*createAudioStreamFn)(void* user_data, irrklang::IFileReader* file);
}

namespace IFileReader
{
	typedef irrklang::ik_s32(*readFn)(void* user_data, void* buffer, irrklang::ik_u32 sizeToRead);
	typedef bool(*seekFn)(void* user_data, irrklang::ik_s32 finalPos, bool relativeMovement);
	typedef irrklang::ik_s32(*getSizeFn)(void* user_data);
	typedef irrklang::ik_s32(*getPosFn)(void* user_data);
	typedef const irrklang::ik_c8* (*getFileNameFn)(void* user_data);
}

namespace IFileFactory
{
	typedef irrklang::IFileReader* (*createFileReaderFn)(void* user_data, const irrklang::ik_c8* filename);
}

namespace ISoundMixedOutputReceiver
{
	typedef void(*onAudioDataReadyFn)(void* user_data, const void* data, int byteCount, int playbackrate);
}

namespace ICapturedAudioDataReceiver
{
	typedef void(*onReceiveAudioDataStreamChunkFn)(void* user_data, unsigned char* audioData, unsigned long lengthInBytes);
}

namespace ISoundStopEventReceiver
{
	typedef void(*onSoundStoppedFn)(void* user_data, irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* receiverUserData);
}

}

extern "C"
{
	IRRKLANG_PROXY_API irrklang::ISoundEngine* IRRKLANG_PROXY_CALLCONV irrklangProxy_createIrrKlangDevice(irrklang::E_SOUND_OUTPUT_DRIVER driver, int options, const char* deviceID, const char* sdk_version_do_not_use);
	IRRKLANG_PROXY_API irrklang::ISoundDeviceList* IRRKLANG_PROXY_CALLCONV irrklangProxy_createSoundDeviceList( irrklang::E_SOUND_OUTPUT_DRIVER driver, const char* sdk_version_do_not_use);
	IRRKLANG_PROXY_API irrklang::IAudioRecorder* IRRKLANG_PROXY_CALLCONV irrklangProxy_createIrrKlangAudioRecorder( irrklang::ISoundEngine* irrKlangDeviceForPlayback, irrklang::E_SOUND_OUTPUT_DRIVER driver, const char* deviceID, const char* sdk_version_do_not_use);
	IRRKLANG_PROXY_API irrklang::ISoundDeviceList* IRRKLANG_PROXY_CALLCONV irrklangProxy_createAudioRecorderDeviceList( irrklang::E_SOUND_OUTPUT_DRIVER driver, const char* sdk_version_do_not_use);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_makeUTF8fromUTF16string( const wchar_t* pInputString, char* pOutputBuffer, int outputBufferSize);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_grabRefCounted(irrklang::IRefCounted* p);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_dropRefCounted(irrklang::IRefCounted* p);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_grabVirtualRefCounted(irrklang::IVirtualRefCounted* p);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_dropVirtualRefCounted(irrklang::IVirtualRefCounted* p);
	IRRKLANG_PROXY_API irrklang::SAudioStreamFormat IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_makeDefaultFormat();
	IRRKLANG_PROXY_API irrklang::SAudioStreamFormat IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_makeFormat( int channelCount, int frameCount, int sampleRate, irrklang::ESampleFormat sampleFormat);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_setChannelCount(irrklang::SAudioStreamFormat& format, int channelCount);
	IRRKLANG_PROXY_API int IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_getChannelCount(const irrklang::SAudioStreamFormat& format);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_setFrameCount(irrklang::SAudioStreamFormat& format, int frameCount);
	IRRKLANG_PROXY_API int IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_getFrameCount(const irrklang::SAudioStreamFormat& format);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_setSampleRate(irrklang::SAudioStreamFormat& format, int sampleRate);
	IRRKLANG_PROXY_API int IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_getSampleRate(const irrklang::SAudioStreamFormat& format);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_setSampleFormat(irrklang::SAudioStreamFormat& format, irrklang::ESampleFormat sampleFormat);
	IRRKLANG_PROXY_API irrklang::ESampleFormat IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_getSampleFormat(const irrklang::SAudioStreamFormat& format);
	IRRKLANG_PROXY_API irrklang::ik_s32 IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_getSampleSize(const irrklang::SAudioStreamFormat& format);
	IRRKLANG_PROXY_API irrklang::ik_s32 IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_getFrameSize(const irrklang::SAudioStreamFormat& format);
	IRRKLANG_PROXY_API irrklang::ik_s32 IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_getSampleDataSize(const irrklang::SAudioStreamFormat& format);
	IRRKLANG_PROXY_API irrklang::ik_s32 IRRKLANG_PROXY_CALLCONV irrklangProxy_SAudioStreamFormat_getBytesPerSecond(const irrklang::SAudioStreamFormat& format);
	IRRKLANG_PROXY_API void* IRRKLANG_PROXY_CALLCONV irrklangProxy_SInternalAudioInterface_getIDirectSound(const irrklang::SInternalAudioInterface& i);
	IRRKLANG_PROXY_API void* IRRKLANG_PROXY_CALLCONV irrklangProxy_SInternalAudioInterface_getIDirectSound8(const irrklang::SInternalAudioInterface& i);
	IRRKLANG_PROXY_API void* IRRKLANG_PROXY_CALLCONV irrklangProxy_SInternalAudioInterface_getWinMM_HWaveOut(const irrklang::SInternalAudioInterface& i);
	IRRKLANG_PROXY_API void* IRRKLANG_PROXY_CALLCONV irrklangProxy_SInternalAudioInterface_getALSA_SND_PCM(const irrklang::SInternalAudioInterface& i);
	IRRKLANG_PROXY_API irrklang::ik_u32 IRRKLANG_PROXY_CALLCONV irrklangProxy_SInternalAudioInterface_getCoreAudioDeviceID(const irrklang::SInternalAudioInterface& i);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioStream_grabAudioStream(irrklang::IAudioStream* stream);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioStream_dropAudioStream(irrklang::IAudioStream* stream);
	IRRKLANG_PROXY_API irrklang::IAudioStream* IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioStream_makeAudioStream( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::IAudioStream::getFormatFn getFormat, irrklangProxy::IAudioStream::setPositionFn setPosition, irrklangProxy::IAudioStream::getIsSeekingSupportedFn getIsSeekingSupported, irrklangProxy::IAudioStream::readFramesFn readFrames);
	IRRKLANG_PROXY_API irrklang::SAudioStreamFormat IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioStream_getFormat(irrklang::IAudioStream* stream);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioStream_setPosition(irrklang::IAudioStream* stream, irrklang::ik_s32 pos);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioStream_getIsSeekingSupported(irrklang::IAudioStream* stream);
	IRRKLANG_PROXY_API irrklang::ik_s32 IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioStream_readFrames(irrklang::IAudioStream* stream, void* target, irrklang::ik_s32 frameCountToRead);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioStreamLoader_grabAudioStreamLoader(irrklang::IAudioStreamLoader* stream);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioStreamLoader_dropAudioStreamLoader(irrklang::IAudioStreamLoader* stream);
	IRRKLANG_PROXY_API irrklang::IAudioStreamLoader* IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioStreamLoader_makeAudioStreamLoader( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::IAudioStreamLoader::isALoadableFileExtensionFn isALoadableFileExtensionVal, irrklangProxy::IAudioStreamLoader::createAudioStreamFn createAudioStreamVal);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioStreamLoader_isALoadableFileExtension(irrklang::IAudioStreamLoader* stream, const irrklang::ik_c8* fileName);
	IRRKLANG_PROXY_API irrklang::IAudioStream* IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioStreamLoader_createAudioStream(irrklang::IAudioStreamLoader* stream, irrklang::IFileReader* reader);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_IFileReader_grabFileReader(irrklang::IFileReader* reader);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_IFileReader_dropFileReader(irrklang::IFileReader* reader);
	IRRKLANG_PROXY_API irrklang::IFileReader* IRRKLANG_PROXY_CALLCONV irrklangProxy_IFileReader_makeFileReader( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::IFileReader::readFn readVal, irrklangProxy::IFileReader::seekFn seekVal, irrklangProxy::IFileReader::getSizeFn getSizeVal, irrklangProxy::IFileReader::getPosFn getPosVal, irrklangProxy::IFileReader::getFileNameFn getFileNameVal);
	IRRKLANG_PROXY_API irrklang::ik_s32 IRRKLANG_PROXY_CALLCONV irrklangProxy_IFileReader_read(irrklang::IFileReader* reader, void* buffer, irrklang::ik_u32 sizeToRead);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_IFileReader_seek(irrklang::IFileReader* reader, irrklang::ik_s32 finalPos, bool relativeMovement);
	IRRKLANG_PROXY_API irrklang::ik_s32 IRRKLANG_PROXY_CALLCONV irrklangProxy_IFileReader_getSize(irrklang::IFileReader* reader);
	IRRKLANG_PROXY_API irrklang::ik_s32 IRRKLANG_PROXY_CALLCONV irrklangProxy_IFileReader_getPos(irrklang::IFileReader* reader);
	IRRKLANG_PROXY_API const irrklang::ik_c8* IRRKLANG_PROXY_CALLCONV irrklangProxy_IFileReader_getFileName(irrklang::IFileReader* reader);
	IRRKLANG_PROXY_API irrklang::IFileFactory* IRRKLANG_PROXY_CALLCONV irrklangProxy_IFileFactory_makeFileFactory( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::IFileFactory::createFileReaderFn createFileReaderVal);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_IFileFactory_grabFileFactory(irrklang::IFileFactory* factory);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_IFileFactory_dropFileFactory(irrklang::IFileFactory* factory);
	IRRKLANG_PROXY_API irrklang::IFileReader* IRRKLANG_PROXY_CALLCONV irrklangProxy_IFileFactory_createFileReader(irrklang::IFileFactory* factory, const irrklang::ik_c8* filename);
	IRRKLANG_PROXY_API irrklang::ISoundMixedOutputReceiver* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundMixedOutputReceiver_makeSoundMixedOutputReceiver( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::ISoundMixedOutputReceiver::onAudioDataReadyFn onAudioDataReadyVal);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundMixedOutputReceiver_onAudioDataReady(irrklang::ISoundMixedOutputReceiver* receiver, const void* data, int byteCount, int playbackrate);
	IRRKLANG_PROXY_API irrklang::ICapturedAudioDataReceiver* IRRKLANG_PROXY_CALLCONV irrklangProxy_ICapturedAudioDataReceiver_makeCapturedAudioDataReceiver( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::ICapturedAudioDataReceiver::onReceiveAudioDataStreamChunkFn onReceiveAudioDataStreamChunkVal);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ICapturedAudioDataReceiver_grabCapturedAudioDataReceiver(irrklang::ICapturedAudioDataReceiver* receiver);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ICapturedAudioDataReceiver_dropCapturedAudioDataReceiver(irrklang::ICapturedAudioDataReceiver* receiver);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ICapturedAudioDataReceiver_onReceiveAudioDataStreamChunk(irrklang::ICapturedAudioDataReceiver* receiver, unsigned char* audioData, unsigned long lengthInBytes);
	IRRKLANG_PROXY_API irrklang::ISoundStopEventReceiver* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundStopEventReceiver_makeSoundStopEventReceiver( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::ISoundStopEventReceiver::onSoundStoppedFn onSoundStoppedVal);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundStopEventReceiver_onSoundStopped(irrklang::ISoundStopEventReceiver* receiver, irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* userData);
	IRRKLANG_PROXY_API const char* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_getDriverName(irrklang::ISoundEngine* engine);
	IRRKLANG_PROXY_API irrklang::ISound* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_play2DFileName( irrklang::ISoundEngine* engine, const char* soundFileName, bool playLooped, bool startPaused, bool track, irrklang::E_STREAM_MODE streamMode, bool enableSoundEffects);
	IRRKLANG_PROXY_API irrklang::ISound* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_play2DSoundSource( irrklang::ISoundEngine* engine, irrklang::ISoundSource* source, bool playLooped, bool startPaused, bool track, bool enableSoundEffects);
	IRRKLANG_PROXY_API irrklang::ISound* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_play3DFileName( irrklang::ISoundEngine* engine, const char* soundFileName, const irrklang::vec3df& pos, bool playLooped, bool startPaused, bool track, irrklang::E_STREAM_MODE streamMode, bool enableSoundEffects);
	IRRKLANG_PROXY_API irrklang::ISound* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_play3DSoundSource( irrklang::ISoundEngine* engine, irrklang::ISoundSource* source, const irrklang::vec3df& pos, bool playLooped, bool startPaused, bool track, bool enableSoundEffects);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_stopAllSounds(irrklang::ISoundEngine* engine);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_setAllSoundsPaused(irrklang::ISoundEngine* engine, bool bPaused);
	IRRKLANG_PROXY_API irrklang::ISoundSource* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_getSoundSourceByName(irrklang::ISoundEngine* engine, const char* soundName, bool addIfNotFound);
	IRRKLANG_PROXY_API irrklang::ISoundSource* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_getSoundSourceByIndex(irrklang::ISoundEngine* engine, int index);
	IRRKLANG_PROXY_API int IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_getSoundSourceCount(irrklang::ISoundEngine* engine);
	IRRKLANG_PROXY_API irrklang::ISoundSource* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_addSoundSourceFromFile(irrklang::ISoundEngine* engine, const char* fileName, irrklang::E_STREAM_MODE mode, bool preload);
	IRRKLANG_PROXY_API irrklang::ISoundSource* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_addSoundSourceFromMemory(irrklang::ISoundEngine* engine, void* memory, int sizeInBytes, const char* soundName, bool copyMemory);
	IRRKLANG_PROXY_API irrklang::ISoundSource* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_addSoundSourceFromPCMData( irrklang::ISoundEngine* engine, void* memory, int sizeInBytes, const char* soundName, const irrklang::SAudioStreamFormat& format, bool copyMemory);
	IRRKLANG_PROXY_API irrklang::ISoundSource* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_addSoundSourceAlias(irrklang::ISoundEngine* engine, irrklang::ISoundSource* baseSource, const char* soundName);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_removeSoundSource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_removeSoundSourceByName(irrklang::ISoundEngine* engine, const char* name);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_removeAllSoundSources(irrklang::ISoundEngine* engine);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_setSoundVolume(irrklang::ISoundEngine* engine, float volume);
	IRRKLANG_PROXY_API float IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_getSoundVolume(irrklang::ISoundEngine* engine);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_setListenerPosition( irrklang::ISoundEngine* engine, const irrklang::vec3df& pos, const irrklang::vec3df& lookdir, const irrklang::vec3df& velPerSecond, const irrklang::vec3df& upVector);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_updateSoundEngine(irrklang::ISoundEngine* engine);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_grabSoundEngine(irrklang::ISoundEngine* engine);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_dropSoundEngine(irrklang::ISoundEngine* engine);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_isCurrentlyPlayingByName(irrklang::ISoundEngine* engine, const char* soundName);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_isCurrentlyPlayingBySource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_registerAudioStreamLoader(irrklang::ISoundEngine* engine, irrklang::IAudioStreamLoader* loader);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_isMultiThreaded(irrklang::ISoundEngine* engine);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_addFileFactory(irrklang::ISoundEngine* engine,irrklang::IFileFactory* fileFactory);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_setDefault3DSoundMinDistance(irrklang::ISoundEngine* engine, float minDistance);
	IRRKLANG_PROXY_API float IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_getDefault3DSoundMinDistance(irrklang::ISoundEngine* engine);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_setDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine, float maxDistance);
	IRRKLANG_PROXY_API float IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_getDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_setRolloffFactor(irrklang::ISoundEngine* engine, float rolloff);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_setDopplerEffectParameters(irrklang::ISoundEngine* engine, float dopplerFactor, float distanceFactor);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_loadPlugins(irrklang::ISoundEngine* engine, const char* path);
	IRRKLANG_PROXY_API const irrklang::SInternalAudioInterface* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_getInternalAudioInterface(irrklang::ISoundEngine* engine);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEngine_setMixedDataOutputReceiver(irrklang::ISoundEngine* engine, irrklang::ISoundMixedOutputReceiver* receiver);
	IRRKLANG_PROXY_API int IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundDeviceList_getDeviceCount(irrklang::ISoundDeviceList* list);
	IRRKLANG_PROXY_API const char* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundDeviceList_getDeviceID(irrklang::ISoundDeviceList* list, int index);
	IRRKLANG_PROXY_API const char* IRRKLANG_PROXY_CALLCONV IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundDeviceList_getDeviceDescription(irrklang::ISoundDeviceList* list, int index);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundDeviceList_grabSoundDeviceList(irrklang::ISoundDeviceList* list);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundDeviceList_dropSoundDeviceList(irrklang::ISoundDeviceList* list);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioRecorder_startRecordingBufferedAudio(irrklang::IAudioRecorder* recorder, irrklang::ik_s32 sampleRate, irrklang::ESampleFormat sampleFormat, irrklang::ik_s32 channelCount);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioRecorder_startRecordingCustomHandledAudio(irrklang::IAudioRecorder* recorder, irrklang::ICapturedAudioDataReceiver* receiver, irrklang::ik_s32 sampleRate, irrklang::ESampleFormat sampleFormat, irrklang::ik_s32 channelCount);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioRecorder_stopRecordingAudio(irrklang::IAudioRecorder* recorder);
	IRRKLANG_PROXY_API irrklang::ISoundSource* IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioRecorder_addSoundSourceFromRecordedAudio(irrklang::IAudioRecorder* recorder, const char* soundName);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioRecorder_clearRecordedAudioDataBuffer(irrklang::IAudioRecorder* recorder);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioRecorder_isRecording(irrklang::IAudioRecorder* recorder);
	IRRKLANG_PROXY_API irrklang::SAudioStreamFormat IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioRecorder_getAudioFormatForAudioRecorder(irrklang::IAudioRecorder* recorder);
	IRRKLANG_PROXY_API void* IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioRecorder_getRecordedAudioData(irrklang::IAudioRecorder* recorder);
	IRRKLANG_PROXY_API const char* IRRKLANG_PROXY_CALLCONV irrklangProxy_IAudioRecorder_getAudioRecorderDriverName(irrklang::IAudioRecorder* recorder);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_disableAllEffects(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_enableChorusSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fWetDryMix, irrklang::ik_f32 fDepth, irrklang::ik_f32 fFeedback, irrklang::ik_f32 fFrequency, bool sinusWaveForm, irrklang::ik_f32 fDelay, irrklang::ik_s32 lPhase);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_disableChorusSoundEffect(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_isChorusSoundEffectEnabled(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_enableCompressorSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fGain, irrklang::ik_f32 fAttack, irrklang::ik_f32 fRelease, irrklang::ik_f32 fThreshold, irrklang::ik_f32 fRatio, irrklang::ik_f32 fPredelay);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_disableCompressorSoundEffect(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_isCompressorSoundEffectEnabled(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_enableDistortionSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fGain, irrklang::ik_f32 fEdge, irrklang::ik_f32 fPostEQCenterFrequency, irrklang::ik_f32 fPostEQBandwidth, irrklang::ik_f32 fPreLowpassCutoff);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_disableDistortionSoundEffect(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_isDistortionSoundEffectEnabled(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_enableEchoSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fWetDryMix, irrklang::ik_f32 fFeedback, irrklang::ik_f32 fLeftDelay, irrklang::ik_f32 fRightDelay, irrklang::ik_s32 lPanDelay);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_disableEchoSoundEffect(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_isEchoSoundEffectEnabled(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_enableFlangerSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fWetDryMix, irrklang::ik_f32 fDepth, irrklang::ik_f32 fFeedback, irrklang::ik_f32 fFrequency, bool triangleWaveForm, irrklang::ik_f32 fDelay, irrklang::ik_s32 lPhase);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_disableFlangerSoundEffect(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_isFlangerSoundEffectEnabled(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_enableGargleSoundEffect(irrklang::ISoundEffectControl* control, irrklang::ik_s32 rateHz, bool sinusWaveForm);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_disableGargleSoundEffect(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_isGargleSoundEffectEnabled(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_enableI3DL2ReverbSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_s32 lRoom, irrklang::ik_s32 lRoomHF, irrklang::ik_f32 flRoomRolloffFactor, irrklang::ik_f32 flDecayTime, irrklang::ik_f32 flDecayHFRatio, irrklang::ik_s32 lReflections, irrklang::ik_f32 flReflectionsDelay, irrklang::ik_s32 lReverb, irrklang::ik_f32 flReverbDelay, irrklang::ik_f32 flDiffusion, irrklang::ik_f32 flDensity, irrklang::ik_f32 flHFReference);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_disableI3DL2ReverbSoundEffect(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_isI3DL2ReverbSoundEffectEnabled(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_enableParamEqSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fCenter, irrklang::ik_f32 fBandwidth, irrklang::ik_f32 fGain);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_disableParamEqSoundEffect(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_isParamEqSoundEffectEnabled(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_enableWavesReverbSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fInGain, irrklang::ik_f32 fReverbMix, irrklang::ik_f32 fReverbTime, irrklang::ik_f32 fHighFreqRTRatio);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_disableWavesReverbSoundEffect(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundEffectControl_isWavesReverbSoundEffectEnabled(irrklang::ISoundEffectControl* control);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_grabSoundSource(irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_dropSoundSource(irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API const irrklang::ik_c8* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_getNameForSoundSource(irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_setStreamMode(irrklang::ISoundSource* source, irrklang::E_STREAM_MODE mode);
	IRRKLANG_PROXY_API irrklang::E_STREAM_MODE IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_getStreamMode(irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API irrklang::ik_u32 IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_getSoundSourcePlayLength(irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API irrklang::SAudioStreamFormat IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_getAudioFormatForSoundSource(irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_getIsSeekingSupportedForSoundSource(irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_setDefaultVolume(irrklang::ISoundSource* source, irrklang::ik_f32 volume);
	IRRKLANG_PROXY_API irrklang::ik_f32 IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_getDefaultVolume(irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_setDefaultMinDistance(irrklang::ISoundSource* source, irrklang::ik_f32 minDistance);
	IRRKLANG_PROXY_API irrklang::ik_f32 IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_getDefaultMinDistance(irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_setDefaultMaxDistance(irrklang::ISoundSource* source, irrklang::ik_f32 maxDistance);
	IRRKLANG_PROXY_API irrklang::ik_f32 IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_getDefaultMaxDistance(irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_forceReloadAtNextUse(irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_setForcedStreamingThreshold(irrklang::ISoundSource* source, irrklang::ik_s32 thresholdBytes);
	IRRKLANG_PROXY_API irrklang::ik_s32 IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_getForcedStreamingThreshold(irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API void* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundSource_getSampleData(irrklang::ISoundSource* source);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_grabSound(irrklang::ISound* sound);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_dropSound(irrklang::ISound* sound);
	IRRKLANG_PROXY_API irrklang::ISoundSource* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_getSoundSource(irrklang::ISound* sound);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_setIsPaused(irrklang::ISound* sound, bool paused);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_getIsPaused(irrklang::ISound* sound);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_stop(irrklang::ISound* sound);
	IRRKLANG_PROXY_API irrklang::ik_f32 IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_getCurrentSoundVolume(irrklang::ISound* sound);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_setCurrentSoundVolume(irrklang::ISound* sound, irrklang::ik_f32 volume);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_setPan(irrklang::ISound* sound, irrklang::ik_f32 pan);
	IRRKLANG_PROXY_API irrklang::ik_f32 IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_getPan(irrklang::ISound* sound);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_isSoundLooped(irrklang::ISound* sound);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_setSoundIsLooped(irrklang::ISound* sound, bool looped);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_isSoundFinished(irrklang::ISound* sound);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_setSoundMinDistance(irrklang::ISound* sound, irrklang::ik_f32 min);
	IRRKLANG_PROXY_API irrklang::ik_f32 IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_getSoundMinDistance(irrklang::ISound* sound);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_setSoundMaxDistance(irrklang::ISound* sound, irrklang::ik_f32 max);
	IRRKLANG_PROXY_API irrklang::ik_f32 IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_getSoundMaxDistance(irrklang::ISound* sound);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_setSoundPosition(irrklang::ISound* sound, const irrklang::vec3df& position);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_getSoundPosition(irrklang::ISound* sound, irrklang::vec3df& result);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_setSoundVelocity(irrklang::ISound* sound, const irrklang::vec3df& vel);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_getSoundVelocity(irrklang::ISound* sound, irrklang::vec3df& result);
	IRRKLANG_PROXY_API irrklang::ik_u32 IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_getPlayPosition(irrklang::ISound* sound);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_setPlayPosition(irrklang::ISound* sound, irrklang::ik_u32 pos);
	IRRKLANG_PROXY_API bool IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_setPlaybackSpeed(irrklang::ISound* sound, irrklang::ik_f32 speed);
	IRRKLANG_PROXY_API irrklang::ik_f32 IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_getPlaybackSpeed(irrklang::ISound* sound);
	IRRKLANG_PROXY_API irrklang::ik_u32 IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_getSoundPlayLength(irrklang::ISound* sound);
	IRRKLANG_PROXY_API irrklang::ISoundEffectControl* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_getSoundEffectControl(irrklang::ISound* sound);
	IRRKLANG_PROXY_API void IRRKLANG_PROXY_CALLCONV irrklangProxy_ISound_setSoundStopEventReceiver(irrklang::ISound* sound, irrklang::ISoundStopEventReceiver* receiver, void* userData);
}


namespace irrklangProxy
{

irrklang::ISoundEngine* createIrrKlangDevice(irrklang::E_SOUND_OUTPUT_DRIVER driver = irrklang::ESOD_AUTO_DETECT,
	int options = irrklang::ESEO_DEFAULT_OPTIONS,
	const char* deviceID = nullptr,
	const char* sdk_version_do_not_use = IRR_KLANG_VERSION
);

irrklang::ISoundDeviceList* createSoundDeviceList(
	irrklang::E_SOUND_OUTPUT_DRIVER driver = irrklang::ESOD_AUTO_DETECT,
	const char* sdk_version_do_not_use = IRR_KLANG_VERSION
);

irrklang::IAudioRecorder* createIrrKlangAudioRecorder(
	irrklang::ISoundEngine* irrKlangDeviceForPlayback,
	irrklang::E_SOUND_OUTPUT_DRIVER driver = irrklang::ESOD_AUTO_DETECT,
	const char* deviceID = nullptr,
	const char* sdk_version_do_not_use = IRR_KLANG_VERSION
);

irrklang::ISoundDeviceList* createAudioRecorderDeviceList(
	irrklang::E_SOUND_OUTPUT_DRIVER driver = irrklang::ESOD_AUTO_DETECT,
	const char* sdk_version_do_not_use = IRR_KLANG_VERSION
);

bool makeUTF8fromUTF16string(
	const wchar_t* pInputString, char* pOutputBuffer, int outputBufferSize
);

void grabRefCounted(irrklang::IRefCounted* p);
void dropRefCounted(irrklang::IRefCounted* p);
	
void grabVirtualRefCounted(irrklang::IVirtualRefCounted* p);
void dropVirtualRefCounted(irrklang::IVirtualRefCounted* p);

namespace SAudioStreamFormat
{
	irrklang::SAudioStreamFormat makeDefaultFormat();
	irrklang::SAudioStreamFormat makeFormat(
		int channelCount,
		int frameCount,
		int sampleRate,
		irrklang::ESampleFormat sampleFormat
	);
	void setChannelCount(irrklang::SAudioStreamFormat& format, int channelCount);
	int  getChannelCount(const irrklang::SAudioStreamFormat& format);

	void  setFrameCount(irrklang::SAudioStreamFormat& format, int frameCount);
	int  getFrameCount(const irrklang::SAudioStreamFormat& format);

	void  setSampleRate(irrklang::SAudioStreamFormat& format, int sampleRate);
	int  getSampleRate(const irrklang::SAudioStreamFormat& format);

	void  setSampleFormat(irrklang::SAudioStreamFormat& format, irrklang::ESampleFormat sampleFormat);
	irrklang::ESampleFormat  getSampleFormat(const irrklang::SAudioStreamFormat& format);

	irrklang::ik_s32  getSampleSize(const irrklang::SAudioStreamFormat& format);
	irrklang::ik_s32  getFrameSize(const irrklang::SAudioStreamFormat& format);
	irrklang::ik_s32  getSampleDataSize(const irrklang::SAudioStreamFormat& format);
	irrklang::ik_s32  getBytesPerSecond(const irrklang::SAudioStreamFormat& format);
	
}

namespace SInternalAudioInterface
{
	void*  getIDirectSound(const irrklang::SInternalAudioInterface& i);
	void*  getIDirectSound8(const irrklang::SInternalAudioInterface& i);
	void*  getWinMM_HWaveOut(const irrklang::SInternalAudioInterface& i);
	void*  getALSA_SND_PCM(const irrklang::SInternalAudioInterface& i);

	irrklang::ik_u32  getCoreAudioDeviceID(const irrklang::SInternalAudioInterface& i);
}

namespace IAudioStream
{
	void grabAudioStream(irrklang::IAudioStream* stream);
	void dropAudioStream(irrklang::IAudioStream* stream);

	irrklang::IAudioStream* makeAudioStream(
		void* user_data, 
		irrklangProxy::dtorFn dtor, getFormatFn getFormat, 
		irrklangProxy::IAudioStream::setPositionFn setPosition, 
		irrklangProxy::IAudioStream::getIsSeekingSupportedFn getIsSeekingSupported, 
		irrklangProxy::IAudioStream::readFramesFn readFrames
	);

	irrklang::SAudioStreamFormat getFormat(irrklang::IAudioStream* stream);
	bool setPosition(irrklang::IAudioStream* stream, irrklang::ik_s32 pos);
	bool getIsSeekingSupported(irrklang::IAudioStream* stream);
	irrklang::ik_s32 readFrames(irrklang::IAudioStream* stream, void* target, irrklang::ik_s32 frameCountToRead);
}

namespace IAudioStreamLoader
{
	void grabAudioStreamLoader(irrklang::IAudioStreamLoader* stream);
	void dropAudioStreamLoader(irrklang::IAudioStreamLoader* stream);

	irrklang::IAudioStreamLoader* makeAudioStreamLoader(
		void* user_data, 
		irrklangProxy::dtorFn dtor, 
		irrklangProxy::IAudioStreamLoader::isALoadableFileExtensionFn isALoadableFileExtensionVal, 
		irrklangProxy::IAudioStreamLoader::createAudioStreamFn createAudioStreamVal
	);

	bool isALoadableFileExtension(irrklang::IAudioStreamLoader* stream, const irrklang::ik_c8* fileName);
	irrklang::IAudioStream* createAudioStream(irrklang::IAudioStreamLoader* stream, irrklang::IFileReader* reader);
}

namespace IFileReader
{
	void grabFileReader(irrklang::IFileReader* reader);
	void dropFileReader(irrklang::IFileReader* reader);

	irrklang::IFileReader* makeFileReader(
		void* user_data, 
		irrklangProxy::dtorFn dtor, 
		irrklangProxy::IFileReader::readFn readVal, 
		irrklangProxy::IFileReader::seekFn seekVal,
		irrklangProxy::IFileReader::getSizeFn getSizeVal,
		irrklangProxy::IFileReader::getPosFn getPosVal,
		irrklangProxy::IFileReader::getFileNameFn getFileNameVal
	);

	irrklang::ik_s32 read(irrklang::IFileReader* reader, void* buffer, irrklang::ik_u32 sizeToRead);
	bool seek(irrklang::IFileReader* reader, irrklang::ik_s32 finalPos, bool relativeMovement = false);
	irrklang::ik_s32 getSize(irrklang::IFileReader* reader);
	irrklang::ik_s32 getPos(irrklang::IFileReader* reader);
	const irrklang::ik_c8* getFileName(irrklang::IFileReader* reader);
}

namespace IFileFactory
{
	void grabFileFactory(irrklang::IFileFactory* factory);
	void dropFileFactory(irrklang::IFileFactory* factory);
	
	irrklang::IFileFactory* makeFileFactory(
		void* user_data, 
		irrklangProxy::dtorFn dtor, 
		irrklangProxy::IFileFactory::createFileReaderFn createFileReaderVal
	);

	irrklang::IFileReader* createFileReader(irrklang::IFileFactory* factory, const irrklang::ik_c8* filename);
}

namespace ISoundMixedOutputReceiver
{	
	irrklang::ISoundMixedOutputReceiver* makeSoundMixedOutputReceiver(
		void* user_data, 
		irrklangProxy::dtorFn dtor, 
		irrklangProxy::ISoundMixedOutputReceiver::onAudioDataReadyFn onAudioDataReadyVal
	);

	void onAudioDataReady(irrklang::ISoundMixedOutputReceiver* receiver, const void* data, int byteCount, int playbackrate);
}


namespace ICapturedAudioDataReceiver
{
	irrklang::ICapturedAudioDataReceiver* makeCapturedAudioDataReceiver(
		void* user_data,
		irrklangProxy::dtorFn dtor,
		irrklangProxy::ICapturedAudioDataReceiver::onReceiveAudioDataStreamChunkFn onReceiveAudioDataStreamChunkVal
	);

	void grabCapturedAudioDataReceiver(irrklang::ICapturedAudioDataReceiver* receiver);
	void dropCapturedAudioDataReceiver(irrklang::ICapturedAudioDataReceiver* receiver);
	
	void onReceiveAudioDataStreamChunk(irrklang::ICapturedAudioDataReceiver* receiver, unsigned char* audioData, unsigned long lengthInBytes);
}

namespace ISoundStopEventReceiver
{	
	irrklang::ISoundStopEventReceiver* makeSoundStopEventReceiver(
		void* user_data,
		irrklangProxy::dtorFn dtor,
		irrklangProxy::ISoundStopEventReceiver::onSoundStoppedFn onSoundStoppedVal
	);

	void onSoundStopped(irrklang::ISoundStopEventReceiver* receiver, irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* userData);
}
	
namespace ISoundEngine
{
const char* getDriverName(irrklang::ISoundEngine* engine);
irrklang::ISound* play2DFileName(
	irrklang::ISoundEngine* engine,
	const char* soundFileName,
	bool playLooped = false,
	bool startPaused = false,
	bool track = false,
	irrklang::E_STREAM_MODE streamMode = irrklang::ESM_AUTO_DETECT,
	bool enableSoundEffects = false
);

irrklang::ISound* play2DSoundSource(
	irrklang::ISoundEngine* engine,
	irrklang::ISoundSource* source,
	bool playLooped = false,
	bool startPaused = false,
	bool track = false,
	bool enableSoundEffects = false
);

irrklang::ISound* play3DFileName(
	irrklang::ISoundEngine* engine,
	const char* soundFileName,
	const irrklang::vec3df& pos,
	bool playLooped = false,
	bool startPaused = false,
	bool track = false,
	irrklang::E_STREAM_MODE streamMode = irrklang::ESM_AUTO_DETECT,
	bool enableSoundEffects = false
);

irrklang::ISound* play3DSoundSource(
	irrklang::ISoundEngine* engine,
	irrklang::ISoundSource* source,
	const irrklang::vec3df& pos,
	bool playLooped = false,
	bool startPaused = false,
	bool track = false,
	bool enableSoundEffects = false
);

void stopAllSounds(irrklang::ISoundEngine* engine);
void setAllSoundsPaused(irrklang::ISoundEngine* engine, bool bPaused = true);


irrklang::ISoundSource* getSoundSourceByName(irrklang::ISoundEngine* engine, const char* soundName, bool addIfNotFound = true);
irrklang::ISoundSource* getSoundSourceByIndex(irrklang::ISoundEngine* engine, int index);

int getSoundSourceCount(irrklang::ISoundEngine* engine);

void grabSoundEngine(irrklang::ISoundEngine* engine);
void dropSoundEngine(irrklang::ISoundEngine* engine);

irrklang::ISoundSource* addSoundSourceFromFile(irrklang::ISoundEngine* engine, const char* fileName, irrklang::E_STREAM_MODE mode = irrklang::ESM_AUTO_DETECT, bool preload = false);
irrklang::ISoundSource* addSoundSourceFromMemory(irrklang::ISoundEngine* engine, void* memory, int sizeInBytes, const char* soundName, bool copyMemory = true);

irrklang::ISoundSource* addSoundSourceFromPCMData(
	irrklang::ISoundEngine* engine,
	void* memory, 
	int sizeInBytes, 
	const char* soundName, 
	const irrklang::SAudioStreamFormat& format,
	bool copyMemory = true
);

irrklang::ISoundSource* addSoundSourceAlias(irrklang::ISoundEngine* engine, irrklang::ISoundSource* baseSource, const char* soundName);

void removeSoundSource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source);
void removeSoundSourceByName(irrklang::ISoundEngine* engine, const char* name);

void removeAllSoundSources(irrklang::ISoundEngine* engine);
void setSoundVolume(irrklang::ISoundEngine* engine, float volume);
float getSoundVolume(irrklang::ISoundEngine* engine);

void setListenerPosition(
	irrklang::ISoundEngine* engine,
	const irrklang::vec3df& pos,
	const irrklang::vec3df& lookdir,
	const irrklang::vec3df& velPerSecond = irrklang::vec3df(0, 0, 0),
	const irrklang::vec3df& upVector = irrklang::vec3df(0, 1, 0)
);

void updateSoundEngine(irrklang::ISoundEngine* engine);

bool isCurrentlyPlayingByName(irrklang::ISoundEngine* engine, const char* soundName);

bool isCurrentlyPlayingBySource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source);

void registerAudioStreamLoader(irrklang::ISoundEngine* engine, irrklang::IAudioStreamLoader* loader);

bool isMultiThreaded(irrklang::ISoundEngine* engine);

void addFileFactory(irrklang::ISoundEngine* engine, irrklang::IFileFactory* fileFactory);

void setDefault3DSoundMinDistance(irrklang::ISoundEngine* engine, float minDistance);
float getDefault3DSoundMinDistance(irrklang::ISoundEngine* engine);

void setDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine, float maxDistance);
float getDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine);

void setRolloffFactor(irrklang::ISoundEngine* engine, float rolloff);

void setDopplerEffectParameters(irrklang::ISoundEngine* engine, float dopplerFactor = 1.0f, float distanceFactor = 1.0f);
bool loadPlugins(irrklang::ISoundEngine* engine, const char* path);

const irrklang::SInternalAudioInterface* getInternalAudioInterface(irrklang::ISoundEngine* engine);

bool setMixedDataOutputReceiver(irrklang::ISoundEngine* engine, irrklang::ISoundMixedOutputReceiver* receiver);
}

namespace ISoundDeviceList
{
int getDeviceCount(irrklang::ISoundDeviceList* list);
const char* getDeviceID(irrklang::ISoundDeviceList* list, int index);
const char* getDeviceDescription(irrklang::ISoundDeviceList* list, int index);
	
void grabSoundDeviceList(irrklang::ISoundDeviceList* list);
void dropSoundDeviceList(irrklang::ISoundDeviceList* list);
}

namespace IAudioRecorder
{
bool startRecordingBufferedAudio(irrklang::IAudioRecorder* recorder, irrklang::ik_s32 sampleRate = 22000, irrklang::ESampleFormat sampleFormat = irrklang::ESF_S16, irrklang::ik_s32 channelCount = 1);
bool startRecordingCustomHandledAudio(irrklang::IAudioRecorder* recorder, irrklang::ICapturedAudioDataReceiver* receiver, irrklang::ik_s32 sampleRate = 22000, irrklang::ESampleFormat sampleFormat = irrklang::ESF_S16, irrklang::ik_s32 channelCount = 1);
void stopRecordingAudio(irrklang::IAudioRecorder* recorder);
irrklang::ISoundSource* addSoundSourceFromRecordedAudio(irrklang::IAudioRecorder* recorder, const char* soundName);
void clearRecordedAudioDataBuffer(irrklang::IAudioRecorder* recorder);
bool isRecording(irrklang::IAudioRecorder* recorder);
irrklang::SAudioStreamFormat getAudioFormatForAudioRecorder(irrklang::IAudioRecorder* recorder);
void* getRecordedAudioData(irrklang::IAudioRecorder* recorder);
const char* getAudioRecorderDriverName(irrklang::IAudioRecorder* recorder);
}

namespace ISoundEffectControl
{
void disableAllEffects(irrklang::ISoundEffectControl* control);
bool enableChorusSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fWetDryMix = 50,
	irrklang::ik_f32 fDepth = 10,
	irrklang::ik_f32 fFeedback = 25,
	irrklang::ik_f32 fFrequency = 1.1f,
	bool sinusWaveForm = true,
	irrklang::ik_f32 fDelay = 16,
	irrklang::ik_s32 lPhase = 90
);

void disableChorusSoundEffect(irrklang::ISoundEffectControl* control);
bool isChorusSoundEffectEnabled(irrklang::ISoundEffectControl* control);
bool enableCompressorSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fGain = 0,
	irrklang::ik_f32 fAttack = 10,
	irrklang::ik_f32 fRelease = 200,
	irrklang::ik_f32 fThreshold = -20,
	irrklang::ik_f32 fRatio = 3,
	irrklang::ik_f32 fPredelay = 4
);
void disableCompressorSoundEffect(irrklang::ISoundEffectControl* control);
bool isCompressorSoundEffectEnabled(irrklang::ISoundEffectControl* control);
bool enableDistortionSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fGain = -18,
	irrklang::ik_f32 fEdge = 15,
	irrklang::ik_f32 fPostEQCenterFrequency = 2400,
	irrklang::ik_f32 fPostEQBandwidth = 2400,
	irrklang::ik_f32 fPreLowpassCutoff = 8000
);

void disableDistortionSoundEffect(irrklang::ISoundEffectControl* control);
bool isDistortionSoundEffectEnabled(irrklang::ISoundEffectControl* control);
bool enableEchoSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fWetDryMix = 50,
	irrklang::ik_f32 fFeedback = 50,
	irrklang::ik_f32 fLeftDelay = 500,
	irrklang::ik_f32 fRightDelay = 500,
	irrklang::ik_s32 lPanDelay = 0
);

 void disableEchoSoundEffect(irrklang::ISoundEffectControl* control);
 bool isEchoSoundEffectEnabled(irrklang::ISoundEffectControl* control);
 bool enableFlangerSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fWetDryMix = 50,
	irrklang::ik_f32 fDepth = 100,
	irrklang::ik_f32 fFeedback = -50,
	irrklang::ik_f32 fFrequency = 0.25f,
	bool triangleWaveForm = true,
	irrklang::ik_f32 fDelay = 2,
	irrklang::ik_s32 lPhase = 0
);
void disableFlangerSoundEffect(irrklang::ISoundEffectControl* control);
bool isFlangerSoundEffectEnabled(irrklang::ISoundEffectControl* control);
bool enableGargleSoundEffect(irrklang::ISoundEffectControl* control, irrklang::ik_s32 rateHz = 20, bool sinusWaveForm = true);
void disableGargleSoundEffect(irrklang::ISoundEffectControl* control);
bool isGargleSoundEffectEnabled(irrklang::ISoundEffectControl* control);

bool enableI3DL2ReverbSoundEffect(
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
void  disableI3DL2ReverbSoundEffect(irrklang::ISoundEffectControl* control);
bool  isI3DL2ReverbSoundEffectEnabled(irrklang::ISoundEffectControl* control);
bool  enableParamEqSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fCenter = 8000,
	irrklang::ik_f32 fBandwidth = 12,
	irrklang::ik_f32 fGain = 0
);
void  disableParamEqSoundEffect(irrklang::ISoundEffectControl* control);
bool  isParamEqSoundEffectEnabled(irrklang::ISoundEffectControl* control);
bool  enableWavesReverbSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fInGain = 0,
	irrklang::ik_f32 fReverbMix = 0,
	irrklang::ik_f32 fReverbTime = 1000,
	irrklang::ik_f32 fHighFreqRTRatio = 0.001f
);
void  disableWavesReverbSoundEffect(irrklang::ISoundEffectControl* control);
bool  isWavesReverbSoundEffectEnabled(irrklang::ISoundEffectControl* control);
}

namespace ISoundSource
{
void grabSoundSource(irrklang::ISoundSource* source);
void dropSoundSource(irrklang::ISoundSource* source);


const irrklang::ik_c8*  getNameForSoundSource(irrklang::ISoundSource* source);
void  setStreamMode(irrklang::ISoundSource* source, irrklang::E_STREAM_MODE mode);
irrklang::E_STREAM_MODE  getStreamMode(irrklang::ISoundSource* source);

irrklang::ik_u32  getSoundSourcePlayLength(irrklang::ISoundSource* source);

irrklang::SAudioStreamFormat  getAudioFormatForSoundSource(irrklang::ISoundSource* source);
bool  getIsSeekingSupportedForSoundSource(irrklang::ISoundSource* source);
void  setDefaultVolume(irrklang::ISoundSource* source, irrklang::ik_f32 volume = 1.0f);
irrklang::ik_f32  getDefaultVolume(irrklang::ISoundSource* source);
void  setDefaultMinDistance(irrklang::ISoundSource* source, irrklang::ik_f32 minDistance);
irrklang::ik_f32  getDefaultMinDistance(irrklang::ISoundSource* source);
void  setDefaultMaxDistance(irrklang::ISoundSource* source, irrklang::ik_f32 maxDistance);
irrklang::ik_f32 getDefaultMaxDistance(irrklang::ISoundSource* source);
void  forceReloadAtNextUse(irrklang::ISoundSource* source);
void setForcedStreamingThreshold(irrklang::ISoundSource* source, irrklang::ik_s32 thresholdBytes);
irrklang::ik_s32 getForcedStreamingThreshold(irrklang::ISoundSource* source);
void* getSampleData(irrklang::ISoundSource* source);
}

namespace ISound
{
void  grabSound(irrklang::ISound* sound);
void  dropSound(irrklang::ISound* sound);

irrklang::ISoundSource*  getSoundSource(irrklang::ISound* sound);
void  setIsPaused(irrklang::ISound* sound, bool paused = true);
bool  getIsPaused(irrklang::ISound* sound);
void  stop(irrklang::ISound* sound);
irrklang::ik_f32  getCurrentSoundVolume(irrklang::ISound* sound);
void  setCurrentSoundVolume(irrklang::ISound* sound, irrklang::ik_f32 volume);
void  setPan(irrklang::ISound* sound, irrklang::ik_f32 pan);
irrklang::ik_f32  getPan(irrklang::ISound* sound);
bool  isSoundLooped(irrklang::ISound* sound);
void  setSoundIsLooped(irrklang::ISound* sound, bool looped);
bool  isSoundFinished(irrklang::ISound* sound);
void  setSoundMinDistance(irrklang::ISound* sound, irrklang::ik_f32 min);
irrklang::ik_f32  getSoundMinDistance(irrklang::ISound* sound);
void  setSoundMaxDistance(irrklang::ISound* sound, irrklang::ik_f32 max);
irrklang::ik_f32  getSoundMaxDistance(irrklang::ISound* sound);
void  setSoundPosition(irrklang::ISound* sound, const irrklang::vec3df& position);
void  getSoundPosition(irrklang::ISound* sound, irrklang::vec3df& result);
void  setSoundVelocity(irrklang::ISound* sound, const irrklang::vec3df& vel);
void  getSoundVelocity(irrklang::ISound* sound, irrklang::vec3df& result);
irrklang::ik_u32  getPlayPosition(irrklang::ISound* sound);
bool  setPlayPosition(irrklang::ISound* sound, irrklang::ik_u32 pos);
bool  setPlaybackSpeed(irrklang::ISound* sound, irrklang::ik_f32 speed = 1.0f);
irrklang::ik_f32  getPlaybackSpeed(irrklang::ISound* sound);
irrklang::ik_u32  getSoundPlayLength(irrklang::ISound* sound);
irrklang::ISoundEffectControl*  getSoundEffectControl(irrklang::ISound* sound);
void  setSoundStopEventReceiver(irrklang::ISound* sound, irrklang::ISoundStopEventReceiver* receiver, void* userData = nullptr);
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
		T* object = new T(std::forward<Ts&&>(args)...);
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
		T* object = new T(std::forward<Ts&&>(args)...);
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
		T* object = new T(std::forward<Ts&&>(args)...);
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
		T* object = new T(std::forward<Ts&&>(args)...);
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
		T* object = new T(std::forward<Ts&&>(args)...);
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
		T* object = new T(std::forward<Ts&&>(args)...);
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
		T* object = new T(std::forward<Ts&&>(args)...);
		return irrklangProxy::ISoundStopEventReceiver::makeSoundStopEventReceiver(
			object, 
			[](void* user_data) -> void { delete static_cast<T*>(user_data);  },
			[](void* user_data, irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* userData) -> void { static_cast<T*>(user_data)->OnSoundStopped(sound,  reason, userData);  }
		);
	}
};
	
}

inline irrklang::ISoundEngine* irrklangProxy::createIrrKlangDevice(irrklang::E_SOUND_OUTPUT_DRIVER driver, int options, const char* deviceID, const char* sdk_version_do_not_use)
{
	return irrklangProxy_createIrrKlangDevice(driver, options, deviceID, sdk_version_do_not_use);
}
inline irrklang::ISoundDeviceList* irrklangProxy::createSoundDeviceList( irrklang::E_SOUND_OUTPUT_DRIVER driver, const char* sdk_version_do_not_use)
{
	return irrklangProxy_createSoundDeviceList(driver, sdk_version_do_not_use);
}
inline irrklang::IAudioRecorder* irrklangProxy::createIrrKlangAudioRecorder( irrklang::ISoundEngine* irrKlangDeviceForPlayback, irrklang::E_SOUND_OUTPUT_DRIVER driver, const char* deviceID, const char* sdk_version_do_not_use)
{
	return irrklangProxy_createIrrKlangAudioRecorder(irrKlangDeviceForPlayback, driver, deviceID, sdk_version_do_not_use);
}
inline irrklang::ISoundDeviceList* irrklangProxy::createAudioRecorderDeviceList( irrklang::E_SOUND_OUTPUT_DRIVER driver, const char* sdk_version_do_not_use)
{
	return irrklangProxy_createAudioRecorderDeviceList(driver, sdk_version_do_not_use);
}
inline bool irrklangProxy::makeUTF8fromUTF16string( const wchar_t* pInputString, char* pOutputBuffer, int outputBufferSize)
{
	return irrklangProxy_makeUTF8fromUTF16string(pInputString, pOutputBuffer, outputBufferSize);
}
inline void irrklangProxy::grabRefCounted(irrklang::IRefCounted* p)
{
	irrklangProxy_grabRefCounted(p);
}
inline void irrklangProxy::dropRefCounted(irrklang::IRefCounted* p)
{
	irrklangProxy_dropRefCounted(p);
}
inline void irrklangProxy::grabVirtualRefCounted(irrklang::IVirtualRefCounted* p)
{
	irrklangProxy_grabVirtualRefCounted(p);
}
inline void irrklangProxy::dropVirtualRefCounted(irrklang::IVirtualRefCounted* p)
{
	irrklangProxy_dropVirtualRefCounted(p);
}
inline irrklang::SAudioStreamFormat irrklangProxy::SAudioStreamFormat::makeDefaultFormat()
{
	return irrklangProxy_SAudioStreamFormat_makeDefaultFormat();
}
inline irrklang::SAudioStreamFormat irrklangProxy::SAudioStreamFormat::makeFormat( int channelCount, int frameCount, int sampleRate, irrklang::ESampleFormat sampleFormat)
{
	return irrklangProxy_SAudioStreamFormat_makeFormat(channelCount, frameCount, sampleRate, sampleFormat);
}
inline void irrklangProxy::SAudioStreamFormat::setChannelCount(irrklang::SAudioStreamFormat& format, int channelCount)
{
	irrklangProxy_SAudioStreamFormat_setChannelCount(format, channelCount);
}
inline int irrklangProxy::SAudioStreamFormat::getChannelCount(const irrklang::SAudioStreamFormat& format)
{
	return irrklangProxy_SAudioStreamFormat_getChannelCount(format);
}
inline void irrklangProxy::SAudioStreamFormat::setFrameCount(irrklang::SAudioStreamFormat& format, int frameCount)
{
	irrklangProxy_SAudioStreamFormat_setFrameCount(format, frameCount);
}
inline int irrklangProxy::SAudioStreamFormat::getFrameCount(const irrklang::SAudioStreamFormat& format)
{
	return irrklangProxy_SAudioStreamFormat_getFrameCount(format);
}
inline void irrklangProxy::SAudioStreamFormat::setSampleRate(irrklang::SAudioStreamFormat& format, int sampleRate)
{
	irrklangProxy_SAudioStreamFormat_setSampleRate(format, sampleRate);
}
inline int irrklangProxy::SAudioStreamFormat::getSampleRate(const irrklang::SAudioStreamFormat& format)
{
	return irrklangProxy_SAudioStreamFormat_getSampleRate(format);
}
inline void irrklangProxy::SAudioStreamFormat::setSampleFormat(irrklang::SAudioStreamFormat& format, irrklang::ESampleFormat sampleFormat)
{
	irrklangProxy_SAudioStreamFormat_setSampleFormat(format, sampleFormat);
}
inline irrklang::ESampleFormat irrklangProxy::SAudioStreamFormat::getSampleFormat(const irrklang::SAudioStreamFormat& format)
{
	return irrklangProxy_SAudioStreamFormat_getSampleFormat(format);
}
inline irrklang::ik_s32 irrklangProxy::SAudioStreamFormat::getSampleSize(const irrklang::SAudioStreamFormat& format)
{
	return irrklangProxy_SAudioStreamFormat_getSampleSize(format);
}
inline irrklang::ik_s32 irrklangProxy::SAudioStreamFormat::getFrameSize(const irrklang::SAudioStreamFormat& format)
{
	return irrklangProxy_SAudioStreamFormat_getFrameSize(format);
}
inline irrklang::ik_s32 irrklangProxy::SAudioStreamFormat::getSampleDataSize(const irrklang::SAudioStreamFormat& format)
{
	return irrklangProxy_SAudioStreamFormat_getSampleDataSize(format);
}
inline irrklang::ik_s32 irrklangProxy::SAudioStreamFormat::getBytesPerSecond(const irrklang::SAudioStreamFormat& format)
{
	return irrklangProxy_SAudioStreamFormat_getBytesPerSecond(format);
}
inline void* irrklangProxy::SInternalAudioInterface::getIDirectSound(const irrklang::SInternalAudioInterface& i)
{
	return irrklangProxy_SInternalAudioInterface_getIDirectSound(i);
}
inline void* irrklangProxy::SInternalAudioInterface::getIDirectSound8(const irrklang::SInternalAudioInterface& i)
{
	return irrklangProxy_SInternalAudioInterface_getIDirectSound8(i);
}
inline void* irrklangProxy::SInternalAudioInterface::getWinMM_HWaveOut(const irrklang::SInternalAudioInterface& i)
{
	return irrklangProxy_SInternalAudioInterface_getWinMM_HWaveOut(i);
}
inline void* irrklangProxy::SInternalAudioInterface::getALSA_SND_PCM(const irrklang::SInternalAudioInterface& i)
{
	return irrklangProxy_SInternalAudioInterface_getALSA_SND_PCM(i);
}
inline irrklang::ik_u32 irrklangProxy::SInternalAudioInterface::getCoreAudioDeviceID(const irrklang::SInternalAudioInterface& i)
{
	return irrklangProxy_SInternalAudioInterface_getCoreAudioDeviceID(i);
}
inline void irrklangProxy::IAudioStream::grabAudioStream(irrklang::IAudioStream* stream)
{
	irrklangProxy_IAudioStream_grabAudioStream(stream);
}
inline void irrklangProxy::IAudioStream::dropAudioStream(irrklang::IAudioStream* stream)
{
	irrklangProxy_IAudioStream_dropAudioStream(stream);
}
inline irrklang::IAudioStream* irrklangProxy::IAudioStream::makeAudioStream( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::IAudioStream::getFormatFn getFormat, irrklangProxy::IAudioStream::setPositionFn setPosition, irrklangProxy::IAudioStream::getIsSeekingSupportedFn getIsSeekingSupported, irrklangProxy::IAudioStream::readFramesFn readFrames)
{
	return irrklangProxy_IAudioStream_makeAudioStream(user_data, dtor, getFormat, setPosition, getIsSeekingSupported, readFrames);
}
inline irrklang::SAudioStreamFormat irrklangProxy::IAudioStream::getFormat(irrklang::IAudioStream* stream)
{
	return irrklangProxy_IAudioStream_getFormat(stream);
}
inline bool irrklangProxy::IAudioStream::setPosition(irrklang::IAudioStream* stream, irrklang::ik_s32 pos)
{
	return irrklangProxy_IAudioStream_setPosition(stream, pos);
}
inline bool irrklangProxy::IAudioStream::getIsSeekingSupported(irrklang::IAudioStream* stream)
{
	return irrklangProxy_IAudioStream_getIsSeekingSupported(stream);
}
inline irrklang::ik_s32 irrklangProxy::IAudioStream::readFrames(irrklang::IAudioStream* stream, void* target, irrklang::ik_s32 frameCountToRead)
{
	return irrklangProxy_IAudioStream_readFrames(stream, target, frameCountToRead);
}
inline void irrklangProxy::IAudioStreamLoader::grabAudioStreamLoader(irrklang::IAudioStreamLoader* stream)
{
	irrklangProxy_IAudioStreamLoader_grabAudioStreamLoader(stream);
}
inline void irrklangProxy::IAudioStreamLoader::dropAudioStreamLoader(irrklang::IAudioStreamLoader* stream)
{
	irrklangProxy_IAudioStreamLoader_dropAudioStreamLoader(stream);
}
inline irrklang::IAudioStreamLoader* irrklangProxy::IAudioStreamLoader::makeAudioStreamLoader( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::IAudioStreamLoader::isALoadableFileExtensionFn isALoadableFileExtensionVal, irrklangProxy::IAudioStreamLoader::createAudioStreamFn createAudioStreamVal)
{
	return irrklangProxy_IAudioStreamLoader_makeAudioStreamLoader(user_data, dtor, isALoadableFileExtensionVal, createAudioStreamVal);
}
inline bool irrklangProxy::IAudioStreamLoader::isALoadableFileExtension(irrklang::IAudioStreamLoader* stream, const irrklang::ik_c8* fileName)
{
	return irrklangProxy_IAudioStreamLoader_isALoadableFileExtension(stream, fileName);
}
inline irrklang::IAudioStream* irrklangProxy::IAudioStreamLoader::createAudioStream(irrklang::IAudioStreamLoader* stream, irrklang::IFileReader* reader)
{
	return irrklangProxy_IAudioStreamLoader_createAudioStream(stream, reader);
}
inline void irrklangProxy::IFileReader::grabFileReader(irrklang::IFileReader* reader)
{
	irrklangProxy_IFileReader_grabFileReader(reader);
}
inline void irrklangProxy::IFileReader::dropFileReader(irrklang::IFileReader* reader)
{
	irrklangProxy_IFileReader_dropFileReader(reader);
}
inline irrklang::IFileReader* irrklangProxy::IFileReader::makeFileReader( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::IFileReader::readFn readVal, irrklangProxy::IFileReader::seekFn seekVal, irrklangProxy::IFileReader::getSizeFn getSizeVal, irrklangProxy::IFileReader::getPosFn getPosVal, irrklangProxy::IFileReader::getFileNameFn getFileNameVal)
{
	return irrklangProxy_IFileReader_makeFileReader(user_data, dtor, readVal, seekVal, getSizeVal, getPosVal, getFileNameVal);
}
inline irrklang::ik_s32 irrklangProxy::IFileReader::read(irrklang::IFileReader* reader, void* buffer, irrklang::ik_u32 sizeToRead)
{
	return irrklangProxy_IFileReader_read(reader, buffer, sizeToRead);
}
inline bool irrklangProxy::IFileReader::seek(irrklang::IFileReader* reader, irrklang::ik_s32 finalPos, bool relativeMovement)
{
	return irrklangProxy_IFileReader_seek(reader, finalPos, relativeMovement);
}
inline irrklang::ik_s32 irrklangProxy::IFileReader::getSize(irrklang::IFileReader* reader)
{
	return irrklangProxy_IFileReader_getSize(reader);
}
inline irrklang::ik_s32 irrklangProxy::IFileReader::getPos(irrklang::IFileReader* reader)
{
	return irrklangProxy_IFileReader_getPos(reader);
}
inline const irrklang::ik_c8* irrklangProxy::IFileReader::getFileName(irrklang::IFileReader* reader)
{
	return irrklangProxy_IFileReader_getFileName(reader);
}
inline irrklang::IFileFactory* irrklangProxy::IFileFactory::makeFileFactory( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::IFileFactory::createFileReaderFn createFileReaderVal)
{
	return irrklangProxy_IFileFactory_makeFileFactory(user_data, dtor, createFileReaderVal);
}
inline void irrklangProxy::IFileFactory::grabFileFactory(irrklang::IFileFactory* factory)
{
	irrklangProxy_IFileFactory_grabFileFactory(factory);
}
inline void irrklangProxy::IFileFactory::dropFileFactory(irrklang::IFileFactory* factory)
{
	irrklangProxy_IFileFactory_dropFileFactory(factory);
}
inline irrklang::IFileReader* irrklangProxy::IFileFactory::createFileReader(irrklang::IFileFactory* factory, const irrklang::ik_c8* filename)
{
	return irrklangProxy_IFileFactory_createFileReader(factory, filename);
}
inline irrklang::ISoundMixedOutputReceiver* irrklangProxy::ISoundMixedOutputReceiver::makeSoundMixedOutputReceiver( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::ISoundMixedOutputReceiver::onAudioDataReadyFn onAudioDataReadyVal)
{
	return irrklangProxy_ISoundMixedOutputReceiver_makeSoundMixedOutputReceiver(user_data, dtor, onAudioDataReadyVal);
}
inline void irrklangProxy::ISoundMixedOutputReceiver::onAudioDataReady(irrklang::ISoundMixedOutputReceiver* receiver, const void* data, int byteCount, int playbackrate)
{
	irrklangProxy_ISoundMixedOutputReceiver_onAudioDataReady(receiver, data, byteCount, playbackrate);
}
inline irrklang::ICapturedAudioDataReceiver* irrklangProxy::ICapturedAudioDataReceiver::makeCapturedAudioDataReceiver( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::ICapturedAudioDataReceiver::onReceiveAudioDataStreamChunkFn onReceiveAudioDataStreamChunkVal)
{
	return irrklangProxy_ICapturedAudioDataReceiver_makeCapturedAudioDataReceiver(user_data, dtor, onReceiveAudioDataStreamChunkVal);
}
inline void irrklangProxy::ICapturedAudioDataReceiver::grabCapturedAudioDataReceiver(irrklang::ICapturedAudioDataReceiver* receiver)
{
	irrklangProxy_ICapturedAudioDataReceiver_grabCapturedAudioDataReceiver(receiver);
}
inline void irrklangProxy::ICapturedAudioDataReceiver::dropCapturedAudioDataReceiver(irrklang::ICapturedAudioDataReceiver* receiver)
{
	irrklangProxy_ICapturedAudioDataReceiver_dropCapturedAudioDataReceiver(receiver);
}
inline void irrklangProxy::ICapturedAudioDataReceiver::onReceiveAudioDataStreamChunk(irrklang::ICapturedAudioDataReceiver* receiver, unsigned char* audioData, unsigned long lengthInBytes)
{
	irrklangProxy_ICapturedAudioDataReceiver_onReceiveAudioDataStreamChunk(receiver, audioData, lengthInBytes);
}
inline irrklang::ISoundStopEventReceiver* irrklangProxy::ISoundStopEventReceiver::makeSoundStopEventReceiver( void* user_data, irrklangProxy::dtorFn dtor, irrklangProxy::ISoundStopEventReceiver::onSoundStoppedFn onSoundStoppedVal)
{
	return irrklangProxy_ISoundStopEventReceiver_makeSoundStopEventReceiver(user_data, dtor, onSoundStoppedVal);
}
inline void irrklangProxy::ISoundStopEventReceiver::onSoundStopped(irrklang::ISoundStopEventReceiver* receiver, irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* userData)
{
	irrklangProxy_ISoundStopEventReceiver_onSoundStopped(receiver, sound, reason, userData);
}
inline const char* irrklangProxy::ISoundEngine::getDriverName(irrklang::ISoundEngine* engine)
{
	return irrklangProxy_ISoundEngine_getDriverName(engine);
}
inline irrklang::ISound* irrklangProxy::ISoundEngine::play2DFileName( irrklang::ISoundEngine* engine, const char* soundFileName, bool playLooped, bool startPaused, bool track, irrklang::E_STREAM_MODE streamMode, bool enableSoundEffects)
{
	return irrklangProxy_ISoundEngine_play2DFileName(engine, soundFileName, playLooped, startPaused, track, streamMode, enableSoundEffects);
}
inline irrklang::ISound* irrklangProxy::ISoundEngine::play2DSoundSource( irrklang::ISoundEngine* engine, irrklang::ISoundSource* source, bool playLooped, bool startPaused, bool track, bool enableSoundEffects)
{
	return irrklangProxy_ISoundEngine_play2DSoundSource(engine, source, playLooped, startPaused, track, enableSoundEffects);
}
inline irrklang::ISound* irrklangProxy::ISoundEngine::play3DFileName( irrklang::ISoundEngine* engine, const char* soundFileName, const irrklang::vec3df& pos, bool playLooped, bool startPaused, bool track, irrklang::E_STREAM_MODE streamMode, bool enableSoundEffects)
{
	return irrklangProxy_ISoundEngine_play3DFileName(engine, soundFileName, pos, playLooped, startPaused, track, streamMode, enableSoundEffects);
}
inline irrklang::ISound* irrklangProxy::ISoundEngine::play3DSoundSource( irrklang::ISoundEngine* engine, irrklang::ISoundSource* source, const irrklang::vec3df& pos, bool playLooped, bool startPaused, bool track, bool enableSoundEffects)
{
	return irrklangProxy_ISoundEngine_play3DSoundSource(engine, source, pos, playLooped, startPaused, track, enableSoundEffects);
}
inline void irrklangProxy::ISoundEngine::stopAllSounds(irrklang::ISoundEngine* engine)
{
	irrklangProxy_ISoundEngine_stopAllSounds(engine);
}
inline void irrklangProxy::ISoundEngine::setAllSoundsPaused(irrklang::ISoundEngine* engine, bool bPaused)
{
	irrklangProxy_ISoundEngine_setAllSoundsPaused(engine, bPaused);
}
inline irrklang::ISoundSource* irrklangProxy::ISoundEngine::getSoundSourceByName(irrklang::ISoundEngine* engine, const char* soundName, bool addIfNotFound)
{
	return irrklangProxy_ISoundEngine_getSoundSourceByName(engine, soundName, addIfNotFound);
}
inline irrklang::ISoundSource* irrklangProxy::ISoundEngine::getSoundSourceByIndex(irrklang::ISoundEngine* engine, int index)
{
	return irrklangProxy_ISoundEngine_getSoundSourceByIndex(engine, index);
}
inline int irrklangProxy::ISoundEngine::getSoundSourceCount(irrklang::ISoundEngine* engine)
{
	return irrklangProxy_ISoundEngine_getSoundSourceCount(engine);
}
inline irrklang::ISoundSource* irrklangProxy::ISoundEngine::addSoundSourceFromFile(irrklang::ISoundEngine* engine, const char* fileName, irrklang::E_STREAM_MODE mode, bool preload)
{
	return irrklangProxy_ISoundEngine_addSoundSourceFromFile(engine, fileName, mode, preload);
}
inline irrklang::ISoundSource* irrklangProxy::ISoundEngine::addSoundSourceFromMemory(irrklang::ISoundEngine* engine, void* memory, int sizeInBytes, const char* soundName, bool copyMemory)
{
	return irrklangProxy_ISoundEngine_addSoundSourceFromMemory(engine, memory, sizeInBytes, soundName, copyMemory);
}
inline irrklang::ISoundSource* irrklangProxy::ISoundEngine::addSoundSourceFromPCMData( irrklang::ISoundEngine* engine, void* memory, int sizeInBytes, const char* soundName, const irrklang::SAudioStreamFormat& format, bool copyMemory)
{
	return irrklangProxy_ISoundEngine_addSoundSourceFromPCMData(engine, memory, sizeInBytes, soundName, format, copyMemory);
}
inline irrklang::ISoundSource* irrklangProxy::ISoundEngine::addSoundSourceAlias(irrklang::ISoundEngine* engine, irrklang::ISoundSource* baseSource, const char* soundName)
{
	return irrklangProxy_ISoundEngine_addSoundSourceAlias(engine, baseSource, soundName);
}
inline void irrklangProxy::ISoundEngine::removeSoundSource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source)
{
	irrklangProxy_ISoundEngine_removeSoundSource(engine, source);
}
inline void irrklangProxy::ISoundEngine::removeSoundSourceByName(irrklang::ISoundEngine* engine, const char* name)
{
	irrklangProxy_ISoundEngine_removeSoundSourceByName(engine, name);
}
inline void irrklangProxy::ISoundEngine::removeAllSoundSources(irrklang::ISoundEngine* engine)
{
	irrklangProxy_ISoundEngine_removeAllSoundSources(engine);
}
inline void irrklangProxy::ISoundEngine::setSoundVolume(irrklang::ISoundEngine* engine, float volume)
{
	irrklangProxy_ISoundEngine_setSoundVolume(engine, volume);
}
inline float irrklangProxy::ISoundEngine::getSoundVolume(irrklang::ISoundEngine* engine)
{
	return irrklangProxy_ISoundEngine_getSoundVolume(engine);
}
inline void irrklangProxy::ISoundEngine::setListenerPosition( irrklang::ISoundEngine* engine, const irrklang::vec3df& pos, const irrklang::vec3df& lookdir, const irrklang::vec3df& velPerSecond, const irrklang::vec3df& upVector)
{
	irrklangProxy_ISoundEngine_setListenerPosition(engine, pos, lookdir, velPerSecond, upVector);
}
inline void irrklangProxy::ISoundEngine::updateSoundEngine(irrklang::ISoundEngine* engine)
{
	irrklangProxy_ISoundEngine_updateSoundEngine(engine);
}
inline void irrklangProxy::ISoundEngine::grabSoundEngine(irrklang::ISoundEngine* engine)
{
	irrklangProxy_ISoundEngine_grabSoundEngine(engine);
}
inline void irrklangProxy::ISoundEngine::dropSoundEngine(irrklang::ISoundEngine* engine)
{
	irrklangProxy_ISoundEngine_dropSoundEngine(engine);
}
inline bool irrklangProxy::ISoundEngine::isCurrentlyPlayingByName(irrklang::ISoundEngine* engine, const char* soundName)
{
	return irrklangProxy_ISoundEngine_isCurrentlyPlayingByName(engine, soundName);
}
inline bool irrklangProxy::ISoundEngine::isCurrentlyPlayingBySource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source)
{
	return irrklangProxy_ISoundEngine_isCurrentlyPlayingBySource(engine, source);
}
inline void irrklangProxy::ISoundEngine::registerAudioStreamLoader(irrklang::ISoundEngine* engine, irrklang::IAudioStreamLoader* loader)
{
	irrklangProxy_ISoundEngine_registerAudioStreamLoader(engine, loader);
}
inline bool irrklangProxy::ISoundEngine::isMultiThreaded(irrklang::ISoundEngine* engine)
{
	return irrklangProxy_ISoundEngine_isMultiThreaded(engine);
}
inline void irrklangProxy::ISoundEngine::addFileFactory(irrklang::ISoundEngine* engine,irrklang::IFileFactory* fileFactory)
{
	irrklangProxy_ISoundEngine_addFileFactory(engine, fileFactory);
}
inline void irrklangProxy::ISoundEngine::setDefault3DSoundMinDistance(irrklang::ISoundEngine* engine, float minDistance)
{
	irrklangProxy_ISoundEngine_setDefault3DSoundMinDistance(engine, minDistance);
}
inline float irrklangProxy::ISoundEngine::getDefault3DSoundMinDistance(irrklang::ISoundEngine* engine)
{
	return irrklangProxy_ISoundEngine_getDefault3DSoundMinDistance(engine);
}
inline void irrklangProxy::ISoundEngine::setDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine, float maxDistance)
{
	irrklangProxy_ISoundEngine_setDefault3DSoundMaxDistance(engine, maxDistance);
}
inline float irrklangProxy::ISoundEngine::getDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine)
{
	return irrklangProxy_ISoundEngine_getDefault3DSoundMaxDistance(engine);
}
inline void irrklangProxy::ISoundEngine::setRolloffFactor(irrklang::ISoundEngine* engine, float rolloff)
{
	irrklangProxy_ISoundEngine_setRolloffFactor(engine, rolloff);
}
inline void irrklangProxy::ISoundEngine::setDopplerEffectParameters(irrklang::ISoundEngine* engine, float dopplerFactor, float distanceFactor)
{
	irrklangProxy_ISoundEngine_setDopplerEffectParameters(engine, dopplerFactor, distanceFactor);
}
inline bool irrklangProxy::ISoundEngine::loadPlugins(irrklang::ISoundEngine* engine, const char* path)
{
	return irrklangProxy_ISoundEngine_loadPlugins(engine, path);
}
inline const irrklang::SInternalAudioInterface* irrklangProxy::ISoundEngine::getInternalAudioInterface(irrklang::ISoundEngine* engine)
{
	return irrklangProxy_ISoundEngine_getInternalAudioInterface(engine);
}
inline bool irrklangProxy::ISoundEngine::setMixedDataOutputReceiver(irrklang::ISoundEngine* engine, irrklang::ISoundMixedOutputReceiver* receiver)
{
	return irrklangProxy_ISoundEngine_setMixedDataOutputReceiver(engine, receiver);
}
inline int irrklangProxy::ISoundDeviceList::getDeviceCount(irrklang::ISoundDeviceList* list)
{
	return irrklangProxy_ISoundDeviceList_getDeviceCount(list);
}
inline const char* irrklangProxy::ISoundDeviceList::getDeviceID(irrklang::ISoundDeviceList* list, int index)
{
	return irrklangProxy_ISoundDeviceList_getDeviceID(list, index);
}
inline const char* irrklangProxy::ISoundDeviceList::getDeviceDescription(irrklang::ISoundDeviceList* list, int index)
{
	return irrklangProxy_ISoundDeviceList_getDeviceDescription(list, index);
}
inline void irrklangProxy::ISoundDeviceList::grabSoundDeviceList(irrklang::ISoundDeviceList* list)
{
	irrklangProxy_ISoundDeviceList_grabSoundDeviceList(list);
}
inline void irrklangProxy::ISoundDeviceList::dropSoundDeviceList(irrklang::ISoundDeviceList* list)
{
	irrklangProxy_ISoundDeviceList_dropSoundDeviceList(list);
}
inline bool irrklangProxy::IAudioRecorder::startRecordingBufferedAudio(irrklang::IAudioRecorder* recorder, irrklang::ik_s32 sampleRate, irrklang::ESampleFormat sampleFormat, irrklang::ik_s32 channelCount)
{
	return irrklangProxy_IAudioRecorder_startRecordingBufferedAudio(recorder, sampleRate, sampleFormat, channelCount);
}
inline bool irrklangProxy::IAudioRecorder::startRecordingCustomHandledAudio(irrklang::IAudioRecorder* recorder, irrklang::ICapturedAudioDataReceiver* receiver, irrklang::ik_s32 sampleRate, irrklang::ESampleFormat sampleFormat, irrklang::ik_s32 channelCount)
{
	return irrklangProxy_IAudioRecorder_startRecordingCustomHandledAudio(recorder, receiver, sampleRate, sampleFormat, channelCount);
}
inline void irrklangProxy::IAudioRecorder::stopRecordingAudio(irrklang::IAudioRecorder* recorder)
{
	irrklangProxy_IAudioRecorder_stopRecordingAudio(recorder);
}
inline irrklang::ISoundSource* irrklangProxy::IAudioRecorder::addSoundSourceFromRecordedAudio(irrklang::IAudioRecorder* recorder, const char* soundName)
{
	return irrklangProxy_IAudioRecorder_addSoundSourceFromRecordedAudio(recorder, soundName);
}
inline void irrklangProxy::IAudioRecorder::clearRecordedAudioDataBuffer(irrklang::IAudioRecorder* recorder)
{
	irrklangProxy_IAudioRecorder_clearRecordedAudioDataBuffer(recorder);
}
inline bool irrklangProxy::IAudioRecorder::isRecording(irrklang::IAudioRecorder* recorder)
{
	return irrklangProxy_IAudioRecorder_isRecording(recorder);
}
inline irrklang::SAudioStreamFormat irrklangProxy::IAudioRecorder::getAudioFormatForAudioRecorder(irrklang::IAudioRecorder* recorder)
{
	return irrklangProxy_IAudioRecorder_getAudioFormatForAudioRecorder(recorder);
}
inline void* irrklangProxy::IAudioRecorder::getRecordedAudioData(irrklang::IAudioRecorder* recorder)
{
	return irrklangProxy_IAudioRecorder_getRecordedAudioData(recorder);
}
inline const char* irrklangProxy::IAudioRecorder::getAudioRecorderDriverName(irrklang::IAudioRecorder* recorder)
{
	return irrklangProxy_IAudioRecorder_getAudioRecorderDriverName(recorder);
}
inline void irrklangProxy::ISoundEffectControl::disableAllEffects(irrklang::ISoundEffectControl* control)
{
	irrklangProxy_ISoundEffectControl_disableAllEffects(control);
}
inline bool irrklangProxy::ISoundEffectControl::enableChorusSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fWetDryMix, irrklang::ik_f32 fDepth, irrklang::ik_f32 fFeedback, irrklang::ik_f32 fFrequency, bool sinusWaveForm, irrklang::ik_f32 fDelay, irrklang::ik_s32 lPhase)
{
	return irrklangProxy_ISoundEffectControl_enableChorusSoundEffect(control, fWetDryMix, fDepth, fFeedback, fFrequency, sinusWaveForm, fDelay, lPhase);
}
inline void irrklangProxy::ISoundEffectControl::disableChorusSoundEffect(irrklang::ISoundEffectControl* control)
{
	irrklangProxy_ISoundEffectControl_disableChorusSoundEffect(control);
}
inline bool irrklangProxy::ISoundEffectControl::isChorusSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return irrklangProxy_ISoundEffectControl_isChorusSoundEffectEnabled(control);
}
inline bool irrklangProxy::ISoundEffectControl::enableCompressorSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fGain, irrklang::ik_f32 fAttack, irrklang::ik_f32 fRelease, irrklang::ik_f32 fThreshold, irrklang::ik_f32 fRatio, irrklang::ik_f32 fPredelay)
{
	return irrklangProxy_ISoundEffectControl_enableCompressorSoundEffect(control, fGain, fAttack, fRelease, fThreshold, fRatio, fPredelay);
}
inline void irrklangProxy::ISoundEffectControl::disableCompressorSoundEffect(irrklang::ISoundEffectControl* control)
{
	irrklangProxy_ISoundEffectControl_disableCompressorSoundEffect(control);
}
inline bool irrklangProxy::ISoundEffectControl::isCompressorSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return irrklangProxy_ISoundEffectControl_isCompressorSoundEffectEnabled(control);
}
inline bool irrklangProxy::ISoundEffectControl::enableDistortionSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fGain, irrklang::ik_f32 fEdge, irrklang::ik_f32 fPostEQCenterFrequency, irrklang::ik_f32 fPostEQBandwidth, irrklang::ik_f32 fPreLowpassCutoff)
{
	return irrklangProxy_ISoundEffectControl_enableDistortionSoundEffect(control, fGain, fEdge, fPostEQCenterFrequency, fPostEQBandwidth, fPreLowpassCutoff);
}
inline void irrklangProxy::ISoundEffectControl::disableDistortionSoundEffect(irrklang::ISoundEffectControl* control)
{
	irrklangProxy_ISoundEffectControl_disableDistortionSoundEffect(control);
}
inline bool irrklangProxy::ISoundEffectControl::isDistortionSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return irrklangProxy_ISoundEffectControl_isDistortionSoundEffectEnabled(control);
}
inline bool irrklangProxy::ISoundEffectControl::enableEchoSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fWetDryMix, irrklang::ik_f32 fFeedback, irrklang::ik_f32 fLeftDelay, irrklang::ik_f32 fRightDelay, irrklang::ik_s32 lPanDelay)
{
	return irrklangProxy_ISoundEffectControl_enableEchoSoundEffect(control, fWetDryMix, fFeedback, fLeftDelay, fRightDelay, lPanDelay);
}
inline void irrklangProxy::ISoundEffectControl::disableEchoSoundEffect(irrklang::ISoundEffectControl* control)
{
	irrklangProxy_ISoundEffectControl_disableEchoSoundEffect(control);
}
inline bool irrklangProxy::ISoundEffectControl::isEchoSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return irrklangProxy_ISoundEffectControl_isEchoSoundEffectEnabled(control);
}
inline bool irrklangProxy::ISoundEffectControl::enableFlangerSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fWetDryMix, irrklang::ik_f32 fDepth, irrklang::ik_f32 fFeedback, irrklang::ik_f32 fFrequency, bool triangleWaveForm, irrklang::ik_f32 fDelay, irrklang::ik_s32 lPhase)
{
	return irrklangProxy_ISoundEffectControl_enableFlangerSoundEffect(control, fWetDryMix, fDepth, fFeedback, fFrequency, triangleWaveForm, fDelay, lPhase);
}
inline void irrklangProxy::ISoundEffectControl::disableFlangerSoundEffect(irrklang::ISoundEffectControl* control)
{
	irrklangProxy_ISoundEffectControl_disableFlangerSoundEffect(control);
}
inline bool irrklangProxy::ISoundEffectControl::isFlangerSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return irrklangProxy_ISoundEffectControl_isFlangerSoundEffectEnabled(control);
}
inline bool irrklangProxy::ISoundEffectControl::enableGargleSoundEffect(irrklang::ISoundEffectControl* control, irrklang::ik_s32 rateHz, bool sinusWaveForm)
{
	return irrklangProxy_ISoundEffectControl_enableGargleSoundEffect(control, rateHz, sinusWaveForm);
}
inline void irrklangProxy::ISoundEffectControl::disableGargleSoundEffect(irrklang::ISoundEffectControl* control)
{
	irrklangProxy_ISoundEffectControl_disableGargleSoundEffect(control);
}
inline bool irrklangProxy::ISoundEffectControl::isGargleSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return irrklangProxy_ISoundEffectControl_isGargleSoundEffectEnabled(control);
}
inline bool irrklangProxy::ISoundEffectControl::enableI3DL2ReverbSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_s32 lRoom, irrklang::ik_s32 lRoomHF, irrklang::ik_f32 flRoomRolloffFactor, irrklang::ik_f32 flDecayTime, irrklang::ik_f32 flDecayHFRatio, irrklang::ik_s32 lReflections, irrklang::ik_f32 flReflectionsDelay, irrklang::ik_s32 lReverb, irrklang::ik_f32 flReverbDelay, irrklang::ik_f32 flDiffusion, irrklang::ik_f32 flDensity, irrklang::ik_f32 flHFReference)
{
	return irrklangProxy_ISoundEffectControl_enableI3DL2ReverbSoundEffect(control, lRoom, lRoomHF, flRoomRolloffFactor, flDecayTime, flDecayHFRatio, lReflections, flReflectionsDelay, lReverb, flReverbDelay, flDiffusion, flDensity, flHFReference);
}
inline void irrklangProxy::ISoundEffectControl::disableI3DL2ReverbSoundEffect(irrklang::ISoundEffectControl* control)
{
	irrklangProxy_ISoundEffectControl_disableI3DL2ReverbSoundEffect(control);
}
inline bool irrklangProxy::ISoundEffectControl::isI3DL2ReverbSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return irrklangProxy_ISoundEffectControl_isI3DL2ReverbSoundEffectEnabled(control);
}
inline bool irrklangProxy::ISoundEffectControl::enableParamEqSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fCenter, irrklang::ik_f32 fBandwidth, irrklang::ik_f32 fGain)
{
	return irrklangProxy_ISoundEffectControl_enableParamEqSoundEffect(control, fCenter, fBandwidth, fGain);
}
inline void irrklangProxy::ISoundEffectControl::disableParamEqSoundEffect(irrklang::ISoundEffectControl* control)
{
	irrklangProxy_ISoundEffectControl_disableParamEqSoundEffect(control);
}
inline bool irrklangProxy::ISoundEffectControl::isParamEqSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return irrklangProxy_ISoundEffectControl_isParamEqSoundEffectEnabled(control);
}
inline bool irrklangProxy::ISoundEffectControl::enableWavesReverbSoundEffect( irrklang::ISoundEffectControl* control, irrklang::ik_f32 fInGain, irrklang::ik_f32 fReverbMix, irrklang::ik_f32 fReverbTime, irrklang::ik_f32 fHighFreqRTRatio)
{
	return irrklangProxy_ISoundEffectControl_enableWavesReverbSoundEffect(control, fInGain, fReverbMix, fReverbTime, fHighFreqRTRatio);
}
inline void irrklangProxy::ISoundEffectControl::disableWavesReverbSoundEffect(irrklang::ISoundEffectControl* control)
{
	irrklangProxy_ISoundEffectControl_disableWavesReverbSoundEffect(control);
}
inline bool irrklangProxy::ISoundEffectControl::isWavesReverbSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return irrklangProxy_ISoundEffectControl_isWavesReverbSoundEffectEnabled(control);
}
inline void irrklangProxy::ISoundSource::grabSoundSource(irrklang::ISoundSource* source)
{
	irrklangProxy_ISoundSource_grabSoundSource(source);
}
inline void irrklangProxy::ISoundSource::dropSoundSource(irrklang::ISoundSource* source)
{
	irrklangProxy_ISoundSource_dropSoundSource(source);
}
inline const irrklang::ik_c8* irrklangProxy::ISoundSource::getNameForSoundSource(irrklang::ISoundSource* source)
{
	return irrklangProxy_ISoundSource_getNameForSoundSource(source);
}
inline void irrklangProxy::ISoundSource::setStreamMode(irrklang::ISoundSource* source, irrklang::E_STREAM_MODE mode)
{
	irrklangProxy_ISoundSource_setStreamMode(source, mode);
}
inline irrklang::E_STREAM_MODE irrklangProxy::ISoundSource::getStreamMode(irrklang::ISoundSource* source)
{
	return irrklangProxy_ISoundSource_getStreamMode(source);
}
inline irrklang::ik_u32 irrklangProxy::ISoundSource::getSoundSourcePlayLength(irrklang::ISoundSource* source)
{
	return irrklangProxy_ISoundSource_getSoundSourcePlayLength(source);
}
inline irrklang::SAudioStreamFormat irrklangProxy::ISoundSource::getAudioFormatForSoundSource(irrklang::ISoundSource* source)
{
	return irrklangProxy_ISoundSource_getAudioFormatForSoundSource(source);
}
inline bool irrklangProxy::ISoundSource::getIsSeekingSupportedForSoundSource(irrklang::ISoundSource* source)
{
	return irrklangProxy_ISoundSource_getIsSeekingSupportedForSoundSource(source);
}
inline void irrklangProxy::ISoundSource::setDefaultVolume(irrklang::ISoundSource* source, irrklang::ik_f32 volume)
{
	irrklangProxy_ISoundSource_setDefaultVolume(source, volume);
}
inline irrklang::ik_f32 irrklangProxy::ISoundSource::getDefaultVolume(irrklang::ISoundSource* source)
{
	return irrklangProxy_ISoundSource_getDefaultVolume(source);
}
inline void irrklangProxy::ISoundSource::setDefaultMinDistance(irrklang::ISoundSource* source, irrklang::ik_f32 minDistance)
{
	irrklangProxy_ISoundSource_setDefaultMinDistance(source, minDistance);
}
inline irrklang::ik_f32 irrklangProxy::ISoundSource::getDefaultMinDistance(irrklang::ISoundSource* source)
{
	return irrklangProxy_ISoundSource_getDefaultMinDistance(source);
}
inline void irrklangProxy::ISoundSource::setDefaultMaxDistance(irrklang::ISoundSource* source, irrklang::ik_f32 maxDistance)
{
	irrklangProxy_ISoundSource_setDefaultMaxDistance(source, maxDistance);
}
inline irrklang::ik_f32 irrklangProxy::ISoundSource::getDefaultMaxDistance(irrklang::ISoundSource* source)
{
	return irrklangProxy_ISoundSource_getDefaultMaxDistance(source);
}
inline void irrklangProxy::ISoundSource::forceReloadAtNextUse(irrklang::ISoundSource* source)
{
	irrklangProxy_ISoundSource_forceReloadAtNextUse(source);
}
inline void irrklangProxy::ISoundSource::setForcedStreamingThreshold(irrklang::ISoundSource* source, irrklang::ik_s32 thresholdBytes)
{
	irrklangProxy_ISoundSource_setForcedStreamingThreshold(source, thresholdBytes);
}
inline irrklang::ik_s32 irrklangProxy::ISoundSource::getForcedStreamingThreshold(irrklang::ISoundSource* source)
{
	return irrklangProxy_ISoundSource_getForcedStreamingThreshold(source);
}
inline void* irrklangProxy::ISoundSource::getSampleData(irrklang::ISoundSource* source)
{
	return irrklangProxy_ISoundSource_getSampleData(source);
}
inline void irrklangProxy::ISound::grabSound(irrklang::ISound* sound)
{
	irrklangProxy_ISound_grabSound(sound);
}
inline void irrklangProxy::ISound::dropSound(irrklang::ISound* sound)
{
	irrklangProxy_ISound_dropSound(sound);
}
inline irrklang::ISoundSource* irrklangProxy::ISound::getSoundSource(irrklang::ISound* sound)
{
	return irrklangProxy_ISound_getSoundSource(sound);
}
inline void irrklangProxy::ISound::setIsPaused(irrklang::ISound* sound, bool paused)
{
	irrklangProxy_ISound_setIsPaused(sound, paused);
}
inline bool irrklangProxy::ISound::getIsPaused(irrklang::ISound* sound)
{
	return irrklangProxy_ISound_getIsPaused(sound);
}
inline void irrklangProxy::ISound::stop(irrklang::ISound* sound)
{
	irrklangProxy_ISound_stop(sound);
}
inline irrklang::ik_f32 irrklangProxy::ISound::getCurrentSoundVolume(irrklang::ISound* sound)
{
	return irrklangProxy_ISound_getCurrentSoundVolume(sound);
}
inline void irrklangProxy::ISound::setCurrentSoundVolume(irrklang::ISound* sound, irrklang::ik_f32 volume)
{
	irrklangProxy_ISound_setCurrentSoundVolume(sound, volume);
}
inline void irrklangProxy::ISound::setPan(irrklang::ISound* sound, irrklang::ik_f32 pan)
{
	irrklangProxy_ISound_setPan(sound, pan);
}
inline irrklang::ik_f32 irrklangProxy::ISound::getPan(irrklang::ISound* sound)
{
	return irrklangProxy_ISound_getPan(sound);
}
inline bool irrklangProxy::ISound::isSoundLooped(irrklang::ISound* sound)
{
	return irrklangProxy_ISound_isSoundLooped(sound);
}
inline void irrklangProxy::ISound::setSoundIsLooped(irrklang::ISound* sound, bool looped)
{
	irrklangProxy_ISound_setSoundIsLooped(sound, looped);
}
inline bool irrklangProxy::ISound::isSoundFinished(irrklang::ISound* sound)
{
	return irrklangProxy_ISound_isSoundFinished(sound);
}
inline void irrklangProxy::ISound::setSoundMinDistance(irrklang::ISound* sound, irrklang::ik_f32 min)
{
	irrklangProxy_ISound_setSoundMinDistance(sound, min);
}
inline irrklang::ik_f32 irrklangProxy::ISound::getSoundMinDistance(irrklang::ISound* sound)
{
	return irrklangProxy_ISound_getSoundMinDistance(sound);
}
inline void irrklangProxy::ISound::setSoundMaxDistance(irrklang::ISound* sound, irrklang::ik_f32 max)
{
	irrklangProxy_ISound_setSoundMaxDistance(sound, max);
}
inline irrklang::ik_f32 irrklangProxy::ISound::getSoundMaxDistance(irrklang::ISound* sound)
{
	return irrklangProxy_ISound_getSoundMaxDistance(sound);
}
inline void irrklangProxy::ISound::setSoundPosition(irrklang::ISound* sound, const irrklang::vec3df& position)
{
	irrklangProxy_ISound_setSoundPosition(sound, position);
}
inline void irrklangProxy::ISound::getSoundPosition(irrklang::ISound* sound, irrklang::vec3df& result)
{
	irrklangProxy_ISound_getSoundPosition(sound, result);
}
inline void irrklangProxy::ISound::setSoundVelocity(irrklang::ISound* sound, const irrklang::vec3df& vel)
{
	irrklangProxy_ISound_setSoundVelocity(sound, vel);
}
inline void irrklangProxy::ISound::getSoundVelocity(irrklang::ISound* sound, irrklang::vec3df& result)
{
	irrklangProxy_ISound_getSoundVelocity(sound, result);
}
inline irrklang::ik_u32 irrklangProxy::ISound::getPlayPosition(irrklang::ISound* sound)
{
	return irrklangProxy_ISound_getPlayPosition(sound);
}
inline bool irrklangProxy::ISound::setPlayPosition(irrklang::ISound* sound, irrklang::ik_u32 pos)
{
	return irrklangProxy_ISound_setPlayPosition(sound, pos);
}
inline bool irrklangProxy::ISound::setPlaybackSpeed(irrklang::ISound* sound, irrklang::ik_f32 speed)
{
	return irrklangProxy_ISound_setPlaybackSpeed(sound, speed);
}
inline irrklang::ik_f32 irrklangProxy::ISound::getPlaybackSpeed(irrklang::ISound* sound)
{
	return irrklangProxy_ISound_getPlaybackSpeed(sound);
}
inline irrklang::ik_u32 irrklangProxy::ISound::getSoundPlayLength(irrklang::ISound* sound)
{
	return irrklangProxy_ISound_getSoundPlayLength(sound);
}
inline irrklang::ISoundEffectControl* irrklangProxy::ISound::getSoundEffectControl(irrklang::ISound* sound)
{
	return irrklangProxy_ISound_getSoundEffectControl(sound);
}
inline void irrklangProxy::ISound::setSoundStopEventReceiver(irrklang::ISound* sound, irrklang::ISoundStopEventReceiver* receiver, void* userData)
{
	irrklangProxy_ISound_setSoundStopEventReceiver(sound, receiver, userData);
}
