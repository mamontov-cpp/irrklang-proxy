#include "../include/irrklang-proxy.h"
#define WIN32_LEAN_AND_MEAN
#ifdef _WIN32
#include <Windows.h>
#endif


irrklang::ISoundEngine* irrklangProxy_createIrrKlangDevice(irrklang::E_SOUND_OUTPUT_DRIVER driver,
		int options,
		const char* deviceID ,
		const char* sdk_version_do_not_use
)
{
	return irrklang::createIrrKlangDevice(driver, options, deviceID, sdk_version_do_not_use);
}

irrklang::ISoundDeviceList* irrklangProxy_createSoundDeviceList(
	irrklang::E_SOUND_OUTPUT_DRIVER driver ,
	const char* sdk_version_do_not_use
)
{
	return irrklang::createSoundDeviceList(driver, sdk_version_do_not_use);
}

irrklang::IAudioRecorder* irrklangProxy_createIrrKlangAudioRecorder(
	irrklang::ISoundEngine* irrKlangDeviceForPlayback,
	irrklang::E_SOUND_OUTPUT_DRIVER driver,
	const char* deviceID,
	const char* sdk_version_do_not_use
)
{
	return irrklang::createIrrKlangAudioRecorder(irrKlangDeviceForPlayback, driver, deviceID, sdk_version_do_not_use);
}

irrklang::ISoundDeviceList* irrklangProxy_createAudioRecorderDeviceList(
	irrklang::E_SOUND_OUTPUT_DRIVER driver,
	const char* sdk_version_do_not_use
)
{
	return irrklang::createAudioRecorderDeviceList(driver, sdk_version_do_not_use);
}

bool irrklangProxy_makeUTF8fromUTF16string(
	const wchar_t* pInputString, char* pOutputBuffer, int outputBufferSize
)
{
#ifdef __MINGW32__
	if (outputBufferSize == 0)
	{
		return true;
	}
	if (!pInputString || !pOutputBuffer)
	{
		return false;
	}
	// Took from https://mariusbancila.ro/blog/2008/10/20/writing-utf-8-files-in-c/, see to_utf8
	// irrKlang somehow lacks this function, even if it's in header.
	int len = wcslen(pInputString);
	int length = ::WideCharToMultiByte(CP_UTF8, 0, pInputString, len, NULL, 0, NULL, NULL);
	if (length ==0)
	{
		return true;
	}
	if ((length + 1) > outputBufferSize)
	{
		return false;
	}
	::WideCharToMultiByte( CP_UTF8, 0, pInputString, len, pOutputBuffer, length, NULL, NULL);
	return true;
#else
	return irrklang::makeUTF8fromUTF16string(pInputString, pOutputBuffer, outputBufferSize);
#endif
}

void irrklangProxy_grabRefCounted(irrklang::IRefCounted* p)
{
	p->grab();
}

void irrklangProxy_dropRefCounted(irrklang::IRefCounted* p)
{
	p->drop();
}

void irrklangProxy_grabVirtualRefCounted(irrklang::IVirtualRefCounted* p)
{
	p->grab();
}

void irrklangProxy_dropVirtualRefCounted(irrklang::IVirtualRefCounted* p)
{
	p->drop();
}

irrklang::SAudioStreamFormat irrklangProxy_SAudioStreamFormat_makeDefaultFormat()
{
	return { 2, -1, 44100, irrklang::ESF_U8 };
}

irrklang::SAudioStreamFormat irrklangProxy_SAudioStreamFormat_makeFormat(
	int channelCount,
	int frameCount,
	int sampleRate,
	irrklang::ESampleFormat sampleFormat
)
{
	return { channelCount, frameCount, sampleRate, sampleFormat };
}

void irrklangProxy_SAudioStreamFormat_setChannelCount(irrklang::SAudioStreamFormat& format, int channelCount)
{
	format.ChannelCount = channelCount;
}


int irrklangProxy_SAudioStreamFormat_getChannelCount(const irrklang::SAudioStreamFormat& format)
{
	return format.ChannelCount;
}

void irrklangProxy_SAudioStreamFormat_setFrameCount(irrklang::SAudioStreamFormat& format, int frameCount)
{
	format.FrameCount = frameCount;
}

int irrklangProxy_SAudioStreamFormat_getFrameCount(const irrklang::SAudioStreamFormat& format)
{
	return format.FrameCount;
}

void irrklangProxy_SAudioStreamFormat_setSampleRate(irrklang::SAudioStreamFormat& format, int sampleRate)
{
	format.SampleRate = sampleRate;
}

int irrklangProxy_SAudioStreamFormat_getSampleRate(const irrklang::SAudioStreamFormat& format)
{
	return format.SampleRate;
}

void irrklangProxy_SAudioStreamFormat_setSampleFormat(irrklang::SAudioStreamFormat& format, irrklang::ESampleFormat sampleFormat)
{
	format.SampleFormat = sampleFormat;
}

irrklang::ESampleFormat irrklangProxy_SAudioStreamFormat_getSampleFormat(const irrklang::SAudioStreamFormat& format)
{
	return format.SampleFormat;
}

irrklang::ik_s32 irrklangProxy_SAudioStreamFormat_getSampleSize(const irrklang::SAudioStreamFormat& format)
{
	return format.getSampleSize();
}

irrklang::ik_s32 irrklangProxy_SAudioStreamFormat_getFrameSize(const irrklang::SAudioStreamFormat& format)
{
	return format.getFrameSize();
}

irrklang::ik_s32 irrklangProxy_SAudioStreamFormat_getSampleDataSize(const irrklang::SAudioStreamFormat& format)
{
	return format.getSampleDataSize();
}

irrklang::ik_s32 irrklangProxy_SAudioStreamFormat_getBytesPerSecond(const irrklang::SAudioStreamFormat& format)
{
	return format.getBytesPerSecond();
}

void* irrklangProxy_SInternalAudioInterface_getIDirectSound(const irrklang::SInternalAudioInterface& i)
{
	return i.pIDirectSound;
}

void* irrklangProxy_SInternalAudioInterface_getIDirectSound8(const irrklang::SInternalAudioInterface& i)
{
	return i.pIDirectSound8;
}

void* irrklangProxy_SInternalAudioInterface_getWinMM_HWaveOut(const irrklang::SInternalAudioInterface& i)
{
	return i.pWinMM_HWaveOut;
}

void* irrklangProxy_SInternalAudioInterface_getALSA_SND_PCM(const irrklang::SInternalAudioInterface& i)
{
	return i.pALSA_SND_PCM;
}

irrklang::ik_u32 irrklangProxy_SInternalAudioInterface_getCoreAudioDeviceID(const irrklang::SInternalAudioInterface& i)
{
	return i.pCoreAudioDeciceID;
}

void irrklangProxy_IAudioStream_grabAudioStream(irrklang::IAudioStream* stream)
{
	stream->grab();
}

void irrklangProxy_IAudioStream_dropAudioStream(irrklang::IAudioStream* stream)
{
	stream->drop();
}

namespace irrklangProxy
{

class IAudioStreamWrapper: public irrklang::IAudioStream  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
	IAudioStreamWrapper(
		void* user_data, 
		irrklangProxy::dtorFn dtor, 
		irrklangProxy::IAudioStream::getFormatFn getFormatArg, 
		irrklangProxy::IAudioStream::setPositionFn setPositionArg, 
		irrklangProxy::IAudioStream::getIsSeekingSupportedFn getIsSeekingSupportedArg, 
		irrklangProxy::IAudioStream::readFramesFn readFramesArg
	) : m_user_data(user_data),
	m_dtor(dtor), m_get_format(getFormatArg),
	m_set_position(setPositionArg),
	m_get_is_seeking_supported(getIsSeekingSupportedArg),
	m_read_frames(readFramesArg)
	{
	}

	virtual ~IAudioStreamWrapper() override
	{
		m_dtor(m_user_data);
	}

	virtual irrklang::SAudioStreamFormat getFormat() override
	{
		return m_get_format(m_user_data);
	}

	virtual bool setPosition(irrklang::ik_s32 pos) override
	{
		return m_set_position(m_user_data, pos);
	}

	virtual bool getIsSeekingSupported() override
	{
		return m_get_is_seeking_supported(m_user_data);
	}

	irrklang::ik_s32 readFrames(void* target, irrklang::ik_s32 frameCountToRead) override
	{
		return m_read_frames(m_user_data, target, frameCountToRead);
	}
	
private:
	void* m_user_data;
	irrklangProxy::dtorFn m_dtor;
	irrklangProxy::IAudioStream::getFormatFn m_get_format;
	irrklangProxy::IAudioStream::setPositionFn m_set_position;
	irrklangProxy::IAudioStream::getIsSeekingSupportedFn m_get_is_seeking_supported;
	irrklangProxy::IAudioStream::readFramesFn m_read_frames;
};

	
}

irrklang::IAudioStream*  irrklangProxy_IAudioStream_makeAudioStream(
	void* user_data, 
	irrklangProxy::dtorFn dtor, 
	irrklangProxy::IAudioStream::getFormatFn getFormat, 
	irrklangProxy::IAudioStream::setPositionFn setPosition, 
	irrklangProxy::IAudioStream::getIsSeekingSupportedFn getIsSeekingSupported, 
	irrklangProxy::IAudioStream::readFramesFn readFrames
)
{
	return new irrklangProxy::IAudioStreamWrapper(user_data, dtor, getFormat, setPosition, getIsSeekingSupported, readFrames);
}
irrklang::SAudioStreamFormat irrklangProxy_IAudioStream_getFormat(irrklang::IAudioStream* stream)
{
	return stream->getFormat();
}

bool irrklangProxy_IAudioStream_setPosition(irrklang::IAudioStream* stream, irrklang::ik_s32 pos)
{
	return stream->setPosition(pos);
}

bool irrklangProxy_IAudioStream_getIsSeekingSupported(irrklang::IAudioStream* stream)
{
	return stream->getIsSeekingSupported();
}

irrklang::ik_s32 irrklangProxy_IAudioStream_readFrames(irrklang::IAudioStream* stream, void* target, irrklang::ik_s32 frameCountToRead)
{
	return stream->readFrames(target, frameCountToRead);
}

void irrklangProxy_IAudioStreamLoader_grabAudioStreamLoader(irrklang::IAudioStreamLoader* stream)
{
	stream->grab();
}

void irrklangProxy_IAudioStreamLoader_dropAudioStreamLoader(irrklang::IAudioStreamLoader* stream)
{
	stream->drop();
}


namespace irrklangProxy
{

class IAudioStreamLoaderWrapper: public irrklang::IAudioStreamLoader  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
	IAudioStreamLoaderWrapper(
		void* user_data, 
		irrklangProxy::dtorFn dtor, 
		irrklangProxy::IAudioStreamLoader::isALoadableFileExtensionFn isALoadableFileExtensionVal, 
		irrklangProxy::IAudioStreamLoader::createAudioStreamFn createAudioStreamVal
	) : m_user_data(user_data),
	m_dtor(dtor),
	m_is_a_loadable_file_extension(isALoadableFileExtensionVal),
	m_create_audio_stream(createAudioStreamVal)
	{
	}

	virtual ~IAudioStreamLoaderWrapper() override
	{
		m_dtor(m_user_data);
	}

	bool isALoadableFileExtension(const irrklang::ik_c8* fileName) override
	{
		return m_is_a_loadable_file_extension(m_user_data, fileName);
	}

	virtual irrklang::IAudioStream* createAudioStream(irrklang::IFileReader* file) override
	{
		return m_create_audio_stream(m_user_data, file);
	}
private:
	void* m_user_data;
	irrklangProxy::dtorFn m_dtor;
	irrklangProxy::IAudioStreamLoader::isALoadableFileExtensionFn m_is_a_loadable_file_extension;
	irrklangProxy::IAudioStreamLoader::createAudioStreamFn m_create_audio_stream;
};

	
}

irrklang::IAudioStreamLoader* irrklangProxy_IAudioStreamLoader_makeAudioStreamLoader(
		void* user_data, 
		irrklangProxy::dtorFn dtor, 
		irrklangProxy::IAudioStreamLoader::isALoadableFileExtensionFn isALoadableFileExtensionVal, 
		irrklangProxy::IAudioStreamLoader::createAudioStreamFn createAudioStreamVal
)
{
	return new irrklangProxy::IAudioStreamLoaderWrapper(user_data, dtor, isALoadableFileExtensionVal, createAudioStreamVal);
}

bool irrklangProxy_IAudioStreamLoader_isALoadableFileExtension(irrklang::IAudioStreamLoader* stream, const irrklang::ik_c8* fileName)
{
	return stream->isALoadableFileExtension(fileName);
}

irrklang::IAudioStream* irrklangProxy_IAudioStreamLoader_createAudioStream(irrklang::IAudioStreamLoader* stream, irrklang::IFileReader* reader)
{
	return stream->createAudioStream(reader);
}

void irrklangProxy_IFileReader_grabFileReader(irrklang::IFileReader* reader)
{
	reader->grab();
}

void irrklangProxy_IFileReader_dropFileReader(irrklang::IFileReader* reader)
{
	reader->drop();
}



namespace irrklangProxy
{

class IFileReaderWrapper: public irrklang::IFileReader  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
	IFileReaderWrapper(
		void* user_data,
		irrklangProxy::dtorFn dtor,
		irrklangProxy::IFileReader::readFn readVal, 
		irrklangProxy::IFileReader::seekFn seekVal,
		irrklangProxy::IFileReader::getSizeFn getSizeVal,
		irrklangProxy::IFileReader::getPosFn getPosVal,
		irrklangProxy::IFileReader::getFileNameFn getFileNameVal
	) : m_user_data(user_data),
	m_dtor(dtor),
	m_read(readVal),
	m_seek(seekVal),
	m_get_size(getSizeVal),
	m_get_pos(getPosVal),
	m_get_file_name(getFileNameVal)
	{
	}

	virtual ~IFileReaderWrapper() override
	{
		m_dtor(m_user_data);
	}

	virtual irrklang::ik_s32 read(void* buffer, irrklang::ik_u32 sizeToRead) override
	{
		return m_read(m_user_data, buffer, sizeToRead);
	}

	virtual bool seek(irrklang::ik_s32 finalPos, bool relativeMovement = false) override
	{
		return m_seek(m_user_data, finalPos, relativeMovement);
	}

	virtual irrklang::ik_s32 getSize() override
	{
		return m_get_size(m_user_data);
	}

	virtual irrklang::ik_s32 getPos() override
	{
		return m_get_pos(m_user_data);
	}

	virtual const irrklang::ik_c8* getFileName() override
	{
		return m_get_file_name(m_user_data);
	}
	
private:
	void* m_user_data;
	irrklangProxy::dtorFn m_dtor;
	irrklangProxy::IFileReader::readFn m_read;
	irrklangProxy::IFileReader::seekFn m_seek;
	irrklangProxy::IFileReader::getSizeFn m_get_size;
	irrklangProxy::IFileReader::getPosFn m_get_pos;
	irrklangProxy::IFileReader::getFileNameFn m_get_file_name;
};

	
}


irrklang::IFileReader* irrklangProxy_IFileReader_makeFileReader(
		void* user_data, 
		irrklangProxy::dtorFn dtor, 
		irrklangProxy::IFileReader::readFn readVal, 
		irrklangProxy::IFileReader::seekFn seekVal,
		irrklangProxy::IFileReader::getSizeFn getSizeVal,
		irrklangProxy::IFileReader::getPosFn getPosVal,
		irrklangProxy::IFileReader::getFileNameFn getFileNameVal
)
{
	return new irrklangProxy::IFileReaderWrapper(user_data, dtor, readVal, seekVal, getSizeVal, getPosVal, getFileNameVal);
}

irrklang::ik_s32  irrklangProxy_IFileReader_read(irrklang::IFileReader* reader, void* buffer, irrklang::ik_u32 sizeToRead)
{
	return reader->read(buffer, sizeToRead);
}

bool irrklangProxy_IFileReader_seek(irrklang::IFileReader* reader, irrklang::ik_s32 finalPos, bool relativeMovement)
{
	return reader->seek(finalPos, relativeMovement);
}

irrklang::ik_s32 irrklangProxy_IFileReader_getSize(irrklang::IFileReader* reader)
{
	return reader->getSize();
}

irrklang::ik_s32 irrklangProxy_IFileReader_getPos(irrklang::IFileReader* reader)
{
	return reader->getPos();
}

const irrklang::ik_c8* irrklangProxy_IFileReader_getFileName(irrklang::IFileReader* reader)
{
	return reader->getFileName();
}


namespace irrklangProxy
{

class IFileFactoryWrapper: public irrklang::IFileFactory  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
	IFileFactoryWrapper(
		void* user_data,
		irrklangProxy::dtorFn dtor,
		irrklangProxy::IFileFactory::createFileReaderFn createFileReaderVal
	) : m_user_data(user_data),
	m_dtor(dtor),
	m_create_file_reader_fn(createFileReaderVal)
	{
	}

	virtual ~IFileFactoryWrapper() override
	{
		m_dtor(m_user_data);
	}

	virtual irrklang::IFileReader* createFileReader(const irrklang::ik_c8* filename) override
	{
		return m_create_file_reader_fn(m_user_data, filename);
	}
	
private:
	void* m_user_data;
	irrklangProxy::dtorFn m_dtor;
	irrklangProxy::IFileFactory::createFileReaderFn m_create_file_reader_fn;
};

}

irrklang::IFileFactory* irrklangProxy_IFileFactory_makeFileFactory(
	void* user_data, 
	irrklangProxy::dtorFn dtor, 
	irrklangProxy::IFileFactory::createFileReaderFn createFileReaderVal
)
{
	return new irrklangProxy::IFileFactoryWrapper(user_data, dtor, createFileReaderVal);
}

void irrklangProxy_IFileFactory_grabFileFactory(irrklang::IFileFactory* factory)
{
	factory->grab();
}

void irrklangProxy_IFileFactory_dropFileFactory(irrklang::IFileFactory* factory)
{
	factory->drop();
}

irrklang::IFileReader*  irrklangProxy_IFileFactory_createFileReader(irrklang::IFileFactory* factory, const irrklang::ik_c8* filename)
{
	return factory->createFileReader(filename);
}



namespace irrklangProxy
{

class ISoundMixedOutputReceiverWrapper: public irrklang::ISoundMixedOutputReceiver  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
	ISoundMixedOutputReceiverWrapper(
		void* user_data,
		irrklangProxy::dtorFn dtor,
		irrklangProxy::ISoundMixedOutputReceiver::onAudioDataReadyFn onAudioDataReadyVal
	) : m_user_data(user_data),
	m_dtor(dtor),
	m_on_audio_data_ready_fn(onAudioDataReadyVal)
	{
	}

	virtual ~ISoundMixedOutputReceiverWrapper() override
	{
		m_dtor(m_user_data);
	}

	virtual void OnAudioDataReady(const void* data, int byteCount, int playbackrate) override
	{
		m_on_audio_data_ready_fn(m_user_data, data, byteCount, playbackrate);
	}
	
private:
	void* m_user_data;
	irrklangProxy::dtorFn m_dtor;
	irrklangProxy::ISoundMixedOutputReceiver::onAudioDataReadyFn m_on_audio_data_ready_fn;
};

}

irrklang::ISoundMixedOutputReceiver* irrklangProxy_ISoundMixedOutputReceiver_makeSoundMixedOutputReceiver(
	void* user_data, 
	irrklangProxy::dtorFn dtor, 
	irrklangProxy::ISoundMixedOutputReceiver::onAudioDataReadyFn onAudioDataReadyVal
)
{
	return new irrklangProxy::ISoundMixedOutputReceiverWrapper(user_data, dtor, onAudioDataReadyVal);
}

void irrklangProxy_ISoundMixedOutputReceiver_onAudioDataReady(irrklang::ISoundMixedOutputReceiver* receiver, const void* data, int byteCount, int playbackrate)
{
	receiver->OnAudioDataReady(data, byteCount, playbackrate);
}

namespace irrklangProxy
{

class ICapturedAudioDataReceiverWrapper: public irrklang::ICapturedAudioDataReceiver  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
	ICapturedAudioDataReceiverWrapper(
		void* user_data,
		irrklangProxy::dtorFn dtor,
		irrklangProxy::ICapturedAudioDataReceiver::onReceiveAudioDataStreamChunkFn onReceiveAudioDataStreamChunkVal
	) : m_user_data(user_data),
	m_dtor(dtor),
	m_on_receive_audio_data_stream_chunk_fn(onReceiveAudioDataStreamChunkVal)
	{
	}

	virtual ~ICapturedAudioDataReceiverWrapper() override
	{
		m_dtor(m_user_data);
	}

	virtual void OnReceiveAudioDataStreamChunk(unsigned char* audioData, unsigned long lengthInBytes) override
	{
		m_on_receive_audio_data_stream_chunk_fn(m_user_data, audioData, lengthInBytes);
	}
	
private:
	void* m_user_data;
	irrklangProxy::dtorFn m_dtor;
	irrklangProxy::ICapturedAudioDataReceiver::onReceiveAudioDataStreamChunkFn m_on_receive_audio_data_stream_chunk_fn;
};

}

irrklang::ICapturedAudioDataReceiver* irrklangProxy_ICapturedAudioDataReceiver_makeCapturedAudioDataReceiver(
	void* user_data,
	irrklangProxy::dtorFn dtor,
	irrklangProxy::ICapturedAudioDataReceiver::onReceiveAudioDataStreamChunkFn onReceiveAudioDataStreamChunkVal
)
{
	return new irrklangProxy::ICapturedAudioDataReceiverWrapper(user_data, dtor, onReceiveAudioDataStreamChunkVal);
}

void irrklangProxy_ICapturedAudioDataReceiver_grabCapturedAudioDataReceiver(irrklang::ICapturedAudioDataReceiver* receiver)
{
	receiver->grab();
}

void irrklangProxy_ICapturedAudioDataReceiver_dropCapturedAudioDataReceiver(irrklang::ICapturedAudioDataReceiver* receiver)
{
	receiver->drop();
}

void irrklangProxy_ICapturedAudioDataReceiver_onReceiveAudioDataStreamChunk(irrklang::ICapturedAudioDataReceiver* receiver, unsigned char* audioData, unsigned long lengthInBytes)
{
	receiver->OnReceiveAudioDataStreamChunk(audioData, lengthInBytes);
}

namespace irrklangProxy
{

class ISoundStopEventReceiverWrapper: public irrklang::ISoundStopEventReceiver  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
	ISoundStopEventReceiverWrapper(
		void* user_data,
		irrklangProxy::dtorFn dtor,
		irrklangProxy::ISoundStopEventReceiver::onSoundStoppedFn onSoundStoppedVal
	) : m_user_data(user_data),
	m_dtor(dtor),
	m_on_sound_stopped_fn(onSoundStoppedVal)
	{
	}

	virtual ~ISoundStopEventReceiverWrapper() override
	{
		m_dtor(m_user_data);
	}

	virtual void OnSoundStopped(irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* userData) override
	{
		m_on_sound_stopped_fn(m_user_data, sound, reason, userData);
	}
	
private:
	void* m_user_data;
	irrklangProxy::dtorFn m_dtor;
	irrklangProxy::ISoundStopEventReceiver::onSoundStoppedFn m_on_sound_stopped_fn;
};

}

irrklang::ISoundStopEventReceiver* irrklangProxy_ISoundStopEventReceiver_makeSoundStopEventReceiver(
	void* user_data,
	irrklangProxy::dtorFn dtor,
	irrklangProxy::ISoundStopEventReceiver::onSoundStoppedFn onSoundStoppedVal
)
{
	return new irrklangProxy::ISoundStopEventReceiverWrapper(user_data, dtor, onSoundStoppedVal);
}

void irrklangProxy_ISoundStopEventReceiver_onSoundStopped(irrklang::ISoundStopEventReceiver* receiver, irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* userData)
{
	receiver->OnSoundStopped(sound, reason, userData);
}

const char* irrklangProxy_ISoundEngine_getDriverName(irrklang::ISoundEngine* engine)
{
	return engine->getDriverName();
}

irrklang::ISound* irrklangProxy_ISoundEngine_play2DFileName(
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

irrklang::ISound* irrklangProxy_ISoundEngine_play2DSoundSource(
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

irrklang::ISound* irrklangProxy_ISoundEngine_play3DFileName(
	irrklang::ISoundEngine* engine,
	const char* soundFileName,
	const irrklang::vec3df& pos,
	bool playLooped , 
	bool startPaused,
	bool track,
	irrklang::E_STREAM_MODE streamMode,
	bool enableSoundEffects
)
{
	return engine->play3D(soundFileName, pos, playLooped, startPaused, track, streamMode, enableSoundEffects);
}


irrklang::ISound* irrklangProxy_ISoundEngine_play3DSoundSource(
	irrklang::ISoundEngine* engine,
	irrklang::ISoundSource* source,
	const irrklang::vec3df& pos,
	bool playLooped ,
	bool startPaused,
	bool track,
	bool enableSoundEffects
)
{
	return engine->play3D(source, pos, playLooped, startPaused, track, enableSoundEffects);
}


void irrklangProxy_ISoundEngine_stopAllSounds(irrklang::ISoundEngine* engine)
{
	engine->stopAllSounds();
}


void  irrklangProxy_ISoundEngine_setAllSoundsPaused(irrklang::ISoundEngine* engine, bool bPaused)
{
	engine->setAllSoundsPaused(bPaused);
}

irrklang::ISoundSource* irrklangProxy_ISoundEngine_getSoundSourceByName(irrklang::ISoundEngine* engine, const char* soundName, bool addIfNotFound)
{
	return engine->getSoundSource(soundName, addIfNotFound);
}

irrklang::ISoundSource* irrklangProxy_ISoundEngine_getSoundSourceByIndex(irrklang::ISoundEngine* engine, int index)
{
	return engine->getSoundSource(index);
}

int irrklangProxy_ISoundEngine_getSoundSourceCount(irrklang::ISoundEngine* engine)
{
	return engine->getSoundSourceCount();
}

irrklang::ISoundSource*  irrklangProxy_ISoundEngine_addSoundSourceFromFile(irrklang::ISoundEngine* engine, const char* fileName, irrklang::E_STREAM_MODE mode, bool preload)
{
	return engine->addSoundSourceFromFile(fileName, mode, preload);
}

irrklang::ISoundSource* irrklangProxy_ISoundEngine_addSoundSourceFromMemory(irrklang::ISoundEngine* engine, void* memory, int sizeInBytes, const char* soundName, bool copyMemory)
{
	return engine->addSoundSourceFromMemory(memory, sizeInBytes, soundName, copyMemory);
}

irrklang::ISoundSource*  irrklangProxy_ISoundEngine_addSoundSourceFromPCMData(
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

irrklang::ISoundSource* irrklangProxy_ISoundEngine_addSoundSourceAlias(irrklang::ISoundEngine* engine, irrklang::ISoundSource* baseSource, const char* soundName)
{
	return engine->addSoundSourceAlias(baseSource, soundName);
}

void irrklangProxy_ISoundEngine_removeSoundSource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source)
{
	engine->removeSoundSource(source);
}

void irrklangProxy_ISoundEngine_removeSoundSourceByName(irrklang::ISoundEngine* engine, const char* name)
{
	engine->removeSoundSource(name);
}

void irrklangProxy_ISoundEngine_removeAllSoundSources(irrklang::ISoundEngine* engine)
{
	engine->removeAllSoundSources();
}

void irrklangProxy_ISoundEngine_setSoundVolume(irrklang::ISoundEngine* engine, float volume)
{
	engine->setSoundVolume(volume);
}

float irrklangProxy_ISoundEngine_getSoundVolume(irrklang::ISoundEngine* engine)
{
	return engine->getSoundVolume();
}

void irrklangProxy_ISoundEngine_setListenerPosition(
	irrklang::ISoundEngine* engine,
	const irrklang::vec3df& pos,
	const irrklang::vec3df& lookdir,
	const irrklang::vec3df& velPerSecond,
	const irrklang::vec3df& upVector
)
{
	engine->setListenerPosition(pos, lookdir, velPerSecond, upVector);
}

void irrklangProxy_ISoundEngine_updateSoundEngine(irrklang::ISoundEngine* engine)
{
	engine->update();
}


void irrklangProxy_ISoundEngine_grabSoundEngine(irrklang::ISoundEngine* engine)
{
	engine->grab();
}

void irrklangProxy_ISoundEngine_dropSoundEngine(irrklang::ISoundEngine* engine)
{
	engine->drop();
}

bool irrklangProxy_ISoundEngine_isCurrentlyPlayingByName(irrklang::ISoundEngine* engine, const char* soundName)
{
	return engine->isCurrentlyPlaying(soundName);
}

bool irrklangProxy_ISoundEngine_isCurrentlyPlayingBySource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source)
{
	return engine->isCurrentlyPlaying(source);
}

void irrklangProxy_ISoundEngine_registerAudioStreamLoader(irrklang::ISoundEngine* engine, irrklang::IAudioStreamLoader* loader)
{
	engine->registerAudioStreamLoader(loader);
}

bool irrklangProxy_ISoundEngine_isMultiThreaded(irrklang::ISoundEngine* engine)
{
	return engine->isMultiThreaded();
}

void irrklangProxy_ISoundEngine_addFileFactory(irrklang::ISoundEngine* engine,irrklang::IFileFactory* fileFactory)
{
	engine->addFileFactory(fileFactory);
}

void irrklangProxy_ISoundEngine_setDefault3DSoundMinDistance(irrklang::ISoundEngine* engine, float minDistance)
{
	engine->setDefault3DSoundMinDistance(minDistance);
}

float irrklangProxy_ISoundEngine_getDefault3DSoundMinDistance(irrklang::ISoundEngine* engine)
{
	return engine->getDefault3DSoundMinDistance();
}

void irrklangProxy_ISoundEngine_setDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine, float maxDistance)
{
	engine->setDefault3DSoundMaxDistance(maxDistance);
}

float irrklangProxy_ISoundEngine_getDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine)
{
	return engine->getDefault3DSoundMaxDistance();
}

void irrklangProxy_ISoundEngine_setRolloffFactor(irrklang::ISoundEngine* engine, float rolloff)
{
	engine->setRolloffFactor(rolloff);
}

void irrklangProxy_ISoundEngine_setDopplerEffectParameters(irrklang::ISoundEngine* engine, float dopplerFactor, float distanceFactor)
{
	engine->setDopplerEffectParameters(dopplerFactor, distanceFactor);
}

bool irrklangProxy_ISoundEngine_loadPlugins(irrklang::ISoundEngine* engine, const char* path)
{
	return engine->loadPlugins(path);
}

const irrklang::SInternalAudioInterface* irrklangProxy_ISoundEngine_getInternalAudioInterface(irrklang::ISoundEngine* engine)
{
	return &(engine->getInternalAudioInterface());
}

bool irrklangProxy_ISoundEngine_setMixedDataOutputReceiver(irrklang::ISoundEngine* engine, irrklang::ISoundMixedOutputReceiver* receiver)
{
	return engine->setMixedDataOutputReceiver(receiver);
}

int irrklangProxy_ISoundDeviceList_getDeviceCount(irrklang::ISoundDeviceList* list)
{
	return list->getDeviceCount();
}

const char*  irrklangProxy_ISoundDeviceList_getDeviceID(irrklang::ISoundDeviceList* list, int index)
{
	return list->getDeviceID(index);
}

const char* IRRKLANG_PROXY_CALLCONV irrklangProxy_ISoundDeviceList_getDeviceDescription(irrklang::ISoundDeviceList* list, int index)
{
	return list->getDeviceDescription(index);
}

void irrklangProxy_ISoundDeviceList_grabSoundDeviceList(irrklang::ISoundDeviceList* list)
{
	list->grab();
}

void irrklangProxy_ISoundDeviceList_dropSoundDeviceList(irrklang::ISoundDeviceList* list)
{
	list->drop();
}

bool irrklangProxy_IAudioRecorder_startRecordingBufferedAudio(irrklang::IAudioRecorder* recorder, irrklang::ik_s32 sampleRate , irrklang::ESampleFormat sampleFormat, irrklang::ik_s32 channelCount)
{
	return recorder->startRecordingBufferedAudio(sampleRate, sampleFormat, channelCount);
}

bool irrklangProxy_IAudioRecorder_startRecordingCustomHandledAudio(irrklang::IAudioRecorder* recorder, irrklang::ICapturedAudioDataReceiver* receiver, irrklang::ik_s32 sampleRate, irrklang::ESampleFormat sampleFormat, irrklang::ik_s32 channelCount)
{
	return recorder->startRecordingCustomHandledAudio(receiver, sampleRate, sampleFormat, channelCount);
}

void irrklangProxy_IAudioRecorder_stopRecordingAudio(irrklang::IAudioRecorder* recorder)
{
	recorder->stopRecordingAudio();
}

irrklang::ISoundSource* irrklangProxy_IAudioRecorder_addSoundSourceFromRecordedAudio(irrklang::IAudioRecorder* recorder, const char* soundName)
{
	return recorder->addSoundSourceFromRecordedAudio(soundName);
}

void irrklangProxy_IAudioRecorder_clearRecordedAudioDataBuffer(irrklang::IAudioRecorder* recorder)
{
	recorder->clearRecordedAudioDataBuffer();
}

bool irrklangProxy_IAudioRecorder_isRecording(irrklang::IAudioRecorder* recorder)
{
	return recorder->isRecording();
}

irrklang::SAudioStreamFormat irrklangProxy_IAudioRecorder_getAudioFormatForAudioRecorder(irrklang::IAudioRecorder* recorder)
{
	return recorder->getAudioFormat();
}

void* irrklangProxy_IAudioRecorder_getRecordedAudioData(irrklang::IAudioRecorder* recorder)
{
	return recorder->getRecordedAudioData();
}

const char* irrklangProxy_IAudioRecorder_getAudioRecorderDriverName(irrklang::IAudioRecorder* recorder)
{
	return recorder->getDriverName();
}


void irrklangProxy_ISoundEffectControl_disableAllEffects(irrklang::ISoundEffectControl* control)
{
	control->disableAllEffects();
}
bool irrklangProxy_ISoundEffectControl_enableChorusSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fWetDryMix,
	irrklang::ik_f32 fDepth,
	irrklang::ik_f32 fFeedback,
	irrklang::ik_f32 fFrequency,
	bool sinusWaveForm,
	irrklang::ik_f32 fDelay,
	irrklang::ik_s32 lPhase
)
{
	return control->enableChorusSoundEffect(fWetDryMix, fDepth, fFeedback, fFrequency, sinusWaveForm, fDelay, lPhase);
}

void irrklangProxy_ISoundEffectControl_disableChorusSoundEffect(irrklang::ISoundEffectControl* control)
{
	control->disableChorusSoundEffect();
}

bool irrklangProxy_ISoundEffectControl_isChorusSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return control->isChorusSoundEffectEnabled();
}

bool irrklangProxy_ISoundEffectControl_enableCompressorSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fGain,
	irrklang::ik_f32 fAttack,
	irrklang::ik_f32 fRelease,
	irrklang::ik_f32 fThreshold,
	irrklang::ik_f32 fRatio,
	irrklang::ik_f32 fPredelay
)
{
	return control->enableCompressorSoundEffect(fGain, fAttack, fRelease, fThreshold, fRatio, fPredelay);
}

void irrklangProxy_ISoundEffectControl_disableCompressorSoundEffect(irrklang::ISoundEffectControl* control)
{
	control->disableCompressorSoundEffect();
}

bool irrklangProxy_ISoundEffectControl_isCompressorSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return control->isCompressorSoundEffectEnabled();
}

bool irrklangProxy_ISoundEffectControl_enableDistortionSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fGain,
	irrklang::ik_f32 fEdge,
	irrklang::ik_f32 fPostEQCenterFrequency,
	irrklang::ik_f32 fPostEQBandwidth,
	irrklang::ik_f32 fPreLowpassCutoff
)
{
	return control->enableDistortionSoundEffect(fGain, fEdge, fPostEQCenterFrequency, fPostEQBandwidth, fPreLowpassCutoff);
}

void irrklangProxy_ISoundEffectControl_disableDistortionSoundEffect(irrklang::ISoundEffectControl* control)
{
	control->disableDistortionSoundEffect();
}

bool irrklangProxy_ISoundEffectControl_isDistortionSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return control->isDistortionSoundEffectEnabled();
}

bool irrklangProxy_ISoundEffectControl_enableEchoSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fWetDryMix,
	irrklang::ik_f32 fFeedback,
	irrklang::ik_f32 fLeftDelay,
	irrklang::ik_f32 fRightDelay,
	irrklang::ik_s32 lPanDelay
)
{
	return control->enableEchoSoundEffect(fWetDryMix, fFeedback, fLeftDelay, fRightDelay, lPanDelay);
}

void irrklangProxy_ISoundEffectControl_disableEchoSoundEffect(irrklang::ISoundEffectControl* control)
{
	control->disableEchoSoundEffect();
}

bool irrklangProxy_ISoundEffectControl_isEchoSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return control->isEchoSoundEffectEnabled();
}

bool irrklangProxy_ISoundEffectControl_enableFlangerSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fWetDryMix,
	irrklang::ik_f32 fDepth,
	irrklang::ik_f32 fFeedback,
	irrklang::ik_f32 fFrequency,
	bool triangleWaveForm,
	irrklang::ik_f32 fDelay,
	irrklang::ik_s32 lPhase
)
{
	return control->enableFlangerSoundEffect(fWetDryMix, fDepth, fFeedback, fFrequency, triangleWaveForm, fDelay, lPhase);
}

void irrklangProxy_ISoundEffectControl_disableFlangerSoundEffect(irrklang::ISoundEffectControl* control)
{
	control->disableFlangerSoundEffect();
}

bool irrklangProxy_ISoundEffectControl_isFlangerSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return control->isFlangerSoundEffectEnabled();
}

bool irrklangProxy_ISoundEffectControl_enableGargleSoundEffect(irrklang::ISoundEffectControl* control, irrklang::ik_s32 rateHz, bool sinusWaveForm)
{
	return control->enableGargleSoundEffect(rateHz, sinusWaveForm);
}

void irrklangProxy_ISoundEffectControl_disableGargleSoundEffect(irrklang::ISoundEffectControl* control)
{
	control->disableGargleSoundEffect();
}

bool irrklangProxy_ISoundEffectControl_isGargleSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return control->isGargleSoundEffectEnabled();
}

bool irrklangProxy_ISoundEffectControl_enableI3DL2ReverbSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_s32 lRoom,
	irrklang::ik_s32 lRoomHF,
	irrklang::ik_f32 flRoomRolloffFactor,
	irrklang::ik_f32 flDecayTime,
	irrklang::ik_f32 flDecayHFRatio,
	irrklang::ik_s32 lReflections,
	irrklang::ik_f32 flReflectionsDelay,
	irrklang::ik_s32 lReverb,
	irrklang::ik_f32 flReverbDelay,
	irrklang::ik_f32 flDiffusion,
	irrklang::ik_f32 flDensity,
	irrklang::ik_f32 flHFReference
)
{
	return control->enableI3DL2ReverbSoundEffect(lRoom, lRoomHF, flRoomRolloffFactor, flDecayTime, flDecayHFRatio, lReflections, flReflectionsDelay, lReverb, flReverbDelay, flDiffusion, flDensity, flHFReference);
}

void  irrklangProxy_ISoundEffectControl_disableI3DL2ReverbSoundEffect(irrklang::ISoundEffectControl* control)
{
	control->disableI3DL2ReverbSoundEffect();
}

bool  irrklangProxy_ISoundEffectControl_isI3DL2ReverbSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return control->isI3DL2ReverbSoundEffectEnabled();
}

bool  irrklangProxy_ISoundEffectControl_enableParamEqSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fCenter,
	irrklang::ik_f32 fBandwidth,
	irrklang::ik_f32 fGain
)
{
	return control->enableParamEqSoundEffect(fCenter, fBandwidth, fGain);
}

void  irrklangProxy_ISoundEffectControl_disableParamEqSoundEffect(irrklang::ISoundEffectControl* control)
{
	control->disableParamEqSoundEffect();
}

bool  irrklangProxy_ISoundEffectControl_isParamEqSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return control->isParamEqSoundEffectEnabled();
}

bool  irrklangProxy_ISoundEffectControl_enableWavesReverbSoundEffect(
	irrklang::ISoundEffectControl* control,
	irrklang::ik_f32 fInGain,
	irrklang::ik_f32 fReverbMix,
	irrklang::ik_f32 fReverbTime,
	irrklang::ik_f32 fHighFreqRTRatio
)
{
	return control->enableWavesReverbSoundEffect(fInGain, fReverbMix, fReverbTime, fHighFreqRTRatio);
}

void  irrklangProxy_ISoundEffectControl_disableWavesReverbSoundEffect(irrklang::ISoundEffectControl* control)
{
	control->disableWavesReverbSoundEffect();
}

bool  irrklangProxy_ISoundEffectControl_isWavesReverbSoundEffectEnabled(irrklang::ISoundEffectControl* control)
{
	return control->isWavesReverbSoundEffectEnabled();
}

void irrklangProxy_ISoundSource_grabSoundSource(irrklang::ISoundSource* source)
{
	source->grab();
}

void irrklangProxy_ISoundSource_dropSoundSource(irrklang::ISoundSource* source)
{
	source->drop();
}


const irrklang::ik_c8* irrklangProxy_ISoundSource_getNameForSoundSource(irrklang::ISoundSource* source)
{
	return source->getName();
}

void irrklangProxy_ISoundSource_setStreamMode(irrklang::ISoundSource* source, irrklang::E_STREAM_MODE mode)
{
	source->setStreamMode(mode);
}

irrklang::E_STREAM_MODE irrklangProxy_ISoundSource_getStreamMode(irrklang::ISoundSource* source)
{
	return source->getStreamMode();
}

irrklang::ik_u32 irrklangProxy_ISoundSource_getSoundSourcePlayLength(irrklang::ISoundSource* source)
{
	return source->getPlayLength();
}

irrklang::SAudioStreamFormat irrklangProxy_ISoundSource_getAudioFormatForSoundSource(irrklang::ISoundSource* source)
{
	return source->getAudioFormat();
}

bool irrklangProxy_ISoundSource_getIsSeekingSupportedForSoundSource(irrklang::ISoundSource* source)
{
	return source->getIsSeekingSupported();
}

void irrklangProxy_ISoundSource_setDefaultVolume(irrklang::ISoundSource* source, irrklang::ik_f32 volume)
{
	source->setDefaultVolume(volume);
}

irrklang::ik_f32  irrklangProxy_ISoundSource_getDefaultVolume(irrklang::ISoundSource* source)
{
	return source->getDefaultVolume();
}

void irrklangProxy_ISoundSource_setDefaultMinDistance(irrklang::ISoundSource* source, irrklang::ik_f32 minDistance)
{
	source->setDefaultMinDistance(minDistance);
}

irrklang::ik_f32 irrklangProxy_ISoundSource_getDefaultMinDistance(irrklang::ISoundSource* source)
{
	return source->getDefaultMinDistance();
}

void irrklangProxy_ISoundSource_setDefaultMaxDistance(irrklang::ISoundSource* source, irrklang::ik_f32 maxDistance)
{
	source->setDefaultMaxDistance(maxDistance);
}

irrklang::ik_f32 irrklangProxy_ISoundSource_getDefaultMaxDistance(irrklang::ISoundSource* source)
{
	return source->getDefaultMaxDistance();
}

void irrklangProxy_ISoundSource_forceReloadAtNextUse(irrklang::ISoundSource* source)
{
	source->forceReloadAtNextUse();
}

void irrklangProxy_ISoundSource_setForcedStreamingThreshold(irrklang::ISoundSource* source, irrklang::ik_s32 thresholdBytes)
{
	source->setForcedStreamingThreshold(thresholdBytes);
}

irrklang::ik_s32 irrklangProxy_ISoundSource_getForcedStreamingThreshold(irrklang::ISoundSource* source)
{
	return source->getForcedStreamingThreshold();
}

void* irrklangProxy_ISoundSource_getSampleData(irrklang::ISoundSource* source)
{
	return source->getSampleData();
}

void irrklangProxy_ISound_grabSound(irrklang::ISound* sound)
{
	sound->grab();
}

void irrklangProxy_ISound_dropSound(irrklang::ISound* sound)
{
	sound->drop();
}

irrklang::ISoundSource* irrklangProxy_ISound_getSoundSource(irrklang::ISound* sound)
{
	return sound->getSoundSource();
}

void irrklangProxy_ISound_setIsPaused(irrklang::ISound* sound, bool paused)
{
	return sound->setIsPaused(paused);
}

bool irrklangProxy_ISound_getIsPaused(irrklang::ISound* sound)
{
	return sound->getIsPaused();
}

void irrklangProxy_ISound_stop(irrklang::ISound* sound)
{
	sound->stop();
}

irrklang::ik_f32 irrklangProxy_ISound_getCurrentSoundVolume(irrklang::ISound* sound)
{
	return sound->getVolume();
}

void irrklangProxy_ISound_setCurrentSoundVolume(irrklang::ISound* sound, irrklang::ik_f32 volume)
{
	sound->setVolume(volume);
}

void irrklangProxy_ISound_setPan(irrklang::ISound* sound, irrklang::ik_f32 pan)
{
	sound->setPan(pan);
}

irrklang::ik_f32 irrklangProxy_ISound_getPan(irrklang::ISound* sound)
{
	return sound->getPan();
}

bool irrklangProxy_ISound_isSoundLooped(irrklang::ISound* sound)
{
	return sound->isLooped();
}

void irrklangProxy_ISound_setSoundIsLooped(irrklang::ISound* sound, bool looped)
{
	sound->setIsLooped(looped);
}

bool irrklangProxy_ISound_isSoundFinished(irrklang::ISound* sound)
{
	return sound->isFinished();
}

void irrklangProxy_ISound_setSoundMinDistance(irrklang::ISound* sound, irrklang::ik_f32 min)
{
	sound->setMinDistance(min);
}

irrklang::ik_f32 irrklangProxy_ISound_getSoundMinDistance(irrklang::ISound* sound)
{
	return sound->getMinDistance();
}

void irrklangProxy_ISound_setSoundMaxDistance(irrklang::ISound* sound, irrklang::ik_f32 max)
{
	sound->setMaxDistance(max);
}

irrklang::ik_f32 irrklangProxy_ISound_getSoundMaxDistance(irrklang::ISound* sound)
{
	return sound->getMaxDistance();
}

void irrklangProxy_ISound_setSoundPosition(irrklang::ISound* sound, const irrklang::vec3df& position)
{
	sound->setPosition(position);
}

void irrklangProxy_ISound_getSoundPosition(irrklang::ISound* sound, irrklang::vec3df& result)
{
	result = sound->getPosition();
}

void irrklangProxy_ISound_setSoundVelocity(irrklang::ISound* sound, const irrklang::vec3df& vel)
{
	sound->setVelocity(vel);
}

void irrklangProxy_ISound_getSoundVelocity(irrklang::ISound* sound, irrklang::vec3df& result)
{
	result = sound->getVelocity();
}

irrklang::ik_u32 irrklangProxy_ISound_getPlayPosition(irrklang::ISound* sound)
{
	return sound->getPlayPosition();
}

bool irrklangProxy_ISound_setPlayPosition(irrklang::ISound* sound, irrklang::ik_u32 pos)
{
	return sound->setPlayPosition(pos);
}

bool irrklangProxy_ISound_setPlaybackSpeed(irrklang::ISound* sound, irrklang::ik_f32 speed)
{
	return sound->setPlaybackSpeed(speed);
}

irrklang::ik_f32 irrklangProxy_ISound_getPlaybackSpeed(irrklang::ISound* sound)
{
	return sound->getPlaybackSpeed();
}

irrklang::ik_u32 irrklangProxy_ISound_getSoundPlayLength(irrklang::ISound* sound)
{
	return sound->getPlayLength();
}

irrklang::ISoundEffectControl* irrklangProxy_ISound_getSoundEffectControl(irrklang::ISound* sound)
{
	return sound->getSoundEffectControl();
}

void irrklangProxy_ISound_setSoundStopEventReceiver(irrklang::ISound* sound, irrklang::ISoundStopEventReceiver* receiver, void* userData)
{
	sound->setSoundStopEventReceiver(receiver, userData);
}

#ifdef _MSC_VER
BOOL APIENTRY DllMain( HMODULE,
                       DWORD,
                       LPVOID
                     )
{
    return TRUE;
}
#endif