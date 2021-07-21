#include "irrklang-proxy.h"
#define WIN32_LEAN_AND_MEAN
#ifdef _WIN32
#include <Windows.h>
#endif

irrklang::ISoundEngine* irrklangProxy::createIrrKlangDevice(irrklang::E_SOUND_OUTPUT_DRIVER driver,
		int options,
		const char* deviceID ,
		const char* sdk_version_do_not_use
)
{
	return irrklang::createIrrKlangDevice(driver, options, deviceID, sdk_version_do_not_use);
}

irrklang::ISoundDeviceList* irrklangProxy::createSoundDeviceList(
	irrklang::E_SOUND_OUTPUT_DRIVER driver ,
	const char* sdk_version_do_not_use
)
{
	return irrklang::createSoundDeviceList(driver, sdk_version_do_not_use);
}

irrklang::IAudioRecorder* irrklangProxy::createIrrKlangAudioRecorder(
	irrklang::ISoundEngine* irrKlangDeviceForPlayback,
	irrklang::E_SOUND_OUTPUT_DRIVER driver,
	const char* deviceID,
	const char* sdk_version_do_not_use
)
{
	return irrklang::createIrrKlangAudioRecorder(irrKlangDeviceForPlayback, driver, deviceID, sdk_version_do_not_use);
}

irrklang::ISoundDeviceList* irrklangProxy::createAudioRecorderDeviceList(
	irrklang::E_SOUND_OUTPUT_DRIVER driver,
	const char* sdk_version_do_not_use
)
{
	return irrklang::createAudioRecorderDeviceList(driver, sdk_version_do_not_use);
}

bool irrklangProxy::makeUTF8fromUTF16string(
	const wchar_t* pInputString, char* pOutputBuffer, int outputBufferSize
)
{
	return irrklang::makeUTF8fromUTF16string(pInputString, pOutputBuffer, outputBufferSize);
}

void irrklangProxy::grabRefCounted(irrklang::IRefCounted* p)
{
	p->grab();
}

void irrklangProxy::dropRefCounted(irrklang::IRefCounted* p)
{
	p->drop();
}

void irrklangProxy::grabVirtualRefCounted(irrklang::IVirtualRefCounted* p)
{
	p->grab();
}

void irrklangProxy::dropVirtualRefCounted(irrklang::IVirtualRefCounted* p)
{
	p->drop();
}

irrklang::SAudioStreamFormat irrklangProxy::SAudioStreamFormat::makeDefaultFormat()
{
	return { 2, -1, 44100, irrklang::ESF_U8 };
}

irrklang::SAudioStreamFormat irrklangProxy::SAudioStreamFormat::makeFormat(
	int channelCount,
	int frameCount,
	int sampleRate,
	irrklang::ESampleFormat sampleFormat
)
{
	return { channelCount, frameCount, sampleRate, sampleFormat };
}

void irrklangProxy::SAudioStreamFormat::setChannelCount(irrklang::SAudioStreamFormat& format, int channelCount)
{
	format.ChannelCount = channelCount;
}


int irrklangProxy::SAudioStreamFormat::getChannelCount(const irrklang::SAudioStreamFormat& format)
{
	return format.ChannelCount;
}

void irrklangProxy::SAudioStreamFormat::setFrameCount(irrklang::SAudioStreamFormat& format, int frameCount)
{
	format.FrameCount = frameCount;
}

int irrklangProxy::SAudioStreamFormat::getFrameCount(const irrklang::SAudioStreamFormat& format)
{
	return format.FrameCount;
}

void irrklangProxy::SAudioStreamFormat::setSampleRate(irrklang::SAudioStreamFormat& format, int sampleRate)
{
	format.SampleRate = sampleRate;
}

int irrklangProxy::SAudioStreamFormat::getSampleRate(const irrklang::SAudioStreamFormat& format)
{
	return format.SampleRate;
}

void irrklangProxy::SAudioStreamFormat::setSampleFormat(irrklang::SAudioStreamFormat& format, irrklang::ESampleFormat sampleFormat)
{
	format.SampleFormat = sampleFormat;
}

irrklang::ESampleFormat irrklangProxy::SAudioStreamFormat::getSampleFormat(const irrklang::SAudioStreamFormat& format)
{
	return format.SampleFormat;
}

irrklang::ik_s32 irrklangProxy::SAudioStreamFormat::getSampleSize(const irrklang::SAudioStreamFormat& format)
{
	return format.getSampleSize();
}

irrklang::ik_s32 irrklangProxy::SAudioStreamFormat::getFrameSize(const irrklang::SAudioStreamFormat& format)
{
	return format.getFrameSize();
}

irrklang::ik_s32 irrklangProxy::SAudioStreamFormat::getSampleDataSize(const irrklang::SAudioStreamFormat& format)
{
	return format.getSampleDataSize();
}

irrklang::ik_s32 irrklangProxy::SAudioStreamFormat::getBytesPerSecond(const irrklang::SAudioStreamFormat& format)
{
	return format.getBytesPerSecond();
}

void* irrklangProxy::SInternalAudioInterface::getIDirectSound(const irrklang::SInternalAudioInterface& i)
{
	return i.pIDirectSound;
}

void* irrklangProxy::SInternalAudioInterface::getIDirectSound8(const irrklang::SInternalAudioInterface& i)
{
	return i.pIDirectSound8;
}

void* irrklangProxy::SInternalAudioInterface::getWinMM_HWaveOut(const irrklang::SInternalAudioInterface& i)
{
	return i.pWinMM_HWaveOut;
}

void* irrklangProxy::SInternalAudioInterface::getALSA_SND_PCM(const irrklang::SInternalAudioInterface& i)
{
	return i.pALSA_SND_PCM;
}

irrklang::ik_u32 irrklangProxy::SInternalAudioInterface::getCoreAudioDeviceID(const irrklang::SInternalAudioInterface& i)
{
	return i.pCoreAudioDeciceID;
}

void irrklangProxy::IAudioStream::grabAudioStream(irrklang::IAudioStream* stream)
{
	stream->grab();
}

void irrklangProxy::IAudioStream::dropAudioStream(irrklang::IAudioStream* stream)
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

irrklang::IAudioStream*  irrklangProxy::IAudioStream::makeAudioStream(
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
irrklang::SAudioStreamFormat irrklangProxy::IAudioStream::getFormat(irrklang::IAudioStream* stream)
{
	return stream->getFormat();
}

bool irrklangProxy::IAudioStream::setPosition(irrklang::IAudioStream* stream, irrklang::ik_s32 pos)
{
	return stream->setPosition(pos);
}

bool irrklangProxy::IAudioStream::getIsSeekingSupported(irrklang::IAudioStream* stream)
{
	return stream->getIsSeekingSupported();
}

irrklang::ik_s32 irrklangProxy::IAudioStream::readFrames(irrklang::IAudioStream* stream, void* target, irrklang::ik_s32 frameCountToRead)
{
	return stream->readFrames(target, frameCountToRead);
}

void irrklangProxy::IAudioStreamLoader::grabAudioStreamLoader(irrklang::IAudioStreamLoader* stream)
{
	stream->grab();
}

void irrklangProxy::IAudioStreamLoader::dropAudioStreamLoader(irrklang::IAudioStreamLoader* stream)
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

irrklang::IAudioStreamLoader* irrklangProxy::IAudioStreamLoader::makeAudioStreamLoader(
		void* user_data, 
		irrklangProxy::dtorFn dtor, 
		irrklangProxy::IAudioStreamLoader::isALoadableFileExtensionFn isALoadableFileExtensionVal, 
		irrklangProxy::IAudioStreamLoader::createAudioStreamFn createAudioStreamVal
)
{
	return new irrklangProxy::IAudioStreamLoaderWrapper(user_data, dtor, isALoadableFileExtensionVal, createAudioStreamVal);
}

bool irrklangProxy::IAudioStreamLoader::isALoadableFileExtension(irrklang::IAudioStreamLoader* stream, const irrklang::ik_c8* fileName)
{
	return stream->isALoadableFileExtension(fileName);
}

irrklang::IAudioStream* irrklangProxy::IAudioStreamLoader::createAudioStream(irrklang::IAudioStreamLoader* stream, irrklang::IFileReader* reader)
{
	return stream->createAudioStream(reader);
}

void irrklangProxy::IFileReader::grabFileReader(irrklang::IFileReader* reader)
{
	reader->grab();
}

void irrklangProxy::IFileReader::dropFileReader(irrklang::IFileReader* reader)
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


irrklang::IFileReader* irrklangProxy::IFileReader::makeFileReader(
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

irrklang::ik_s32  irrklangProxy::IFileReader::read(irrklang::IFileReader* reader, void* buffer, irrklang::ik_u32 sizeToRead)
{
	return reader->read(buffer, sizeToRead);
}

bool irrklangProxy::IFileReader::seek(irrklang::IFileReader* reader, irrklang::ik_s32 finalPos, bool relativeMovement)
{
	return reader->seek(finalPos, relativeMovement);
}

irrklang::ik_s32 irrklangProxy::IFileReader::getSize(irrklang::IFileReader* reader)
{
	return reader->getSize();
}

irrklang::ik_s32 irrklangProxy::IFileReader::getPos(irrklang::IFileReader* reader)
{
	return reader->getPos();
}

const irrklang::ik_c8* irrklangProxy::IFileReader::getFileName(irrklang::IFileReader* reader)
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

irrklang::IFileFactory* irrklangProxy::IFileFactory::makeFileFactory(
	void* user_data, 
	irrklangProxy::dtorFn dtor, 
	irrklangProxy::IFileFactory::createFileReaderFn createFileReaderVal
)
{
	return new irrklangProxy::IFileFactoryWrapper(user_data, dtor, createFileReaderVal);
}

void irrklangProxy::IFileFactory::grabFileFactory(irrklang::IFileFactory* factory)
{
	factory->grab();
}

void irrklangProxy::IFileFactory::dropFileFactory(irrklang::IFileFactory* factory)
{
	factory->drop();
}

irrklang::IFileReader*  irrklangProxy::IFileFactory::createFileReader(irrklang::IFileFactory* factory, const irrklang::ik_c8* filename)
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

irrklang::ISoundMixedOutputReceiver* irrklangProxy::ISoundMixedOutputReceiver::makeSoundMixedOutputReceiver(
	void* user_data, 
	irrklangProxy::dtorFn dtor, 
	irrklangProxy::ISoundMixedOutputReceiver::onAudioDataReadyFn onAudioDataReadyVal
)
{
	return new irrklangProxy::ISoundMixedOutputReceiverWrapper(user_data, dtor, onAudioDataReadyVal);
}

void irrklangProxy::ISoundMixedOutputReceiver::onAudioDataReady(irrklang::ISoundMixedOutputReceiver* receiver, const void* data, int byteCount, int playbackrate)
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

irrklang::ICapturedAudioDataReceiver* irrklangProxy::ICapturedAudioDataReceiver::makeCapturedAudioDataReceiver(
	void* user_data,
	irrklangProxy::dtorFn dtor,
	irrklangProxy::ICapturedAudioDataReceiver::onReceiveAudioDataStreamChunkFn onReceiveAudioDataStreamChunkVal
)
{
	return new irrklangProxy::ICapturedAudioDataReceiverWrapper(user_data, dtor, onReceiveAudioDataStreamChunkVal);
}

void irrklangProxy::ICapturedAudioDataReceiver::grabCapturedAudioDataReceiver(irrklang::ICapturedAudioDataReceiver* receiver)
{
	receiver->grab();
}

void irrklangProxy::ICapturedAudioDataReceiver::dropCapturedAudioDataReceiver(irrklang::ICapturedAudioDataReceiver* receiver)
{
	receiver->drop();
}

void irrklangProxy::ICapturedAudioDataReceiver::onReceiveAudioDataStreamChunk(irrklang::ICapturedAudioDataReceiver* receiver, unsigned char* audioData, unsigned long lengthInBytes)
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

irrklang::ISoundStopEventReceiver* irrklangProxy::ISoundStopEventReceiver::makeSoundStopEventReceiver(
	void* user_data,
	irrklangProxy::dtorFn dtor,
	irrklangProxy::ISoundStopEventReceiver::onSoundStoppedFn onSoundStoppedVal
)
{
	return new irrklangProxy::ISoundStopEventReceiverWrapper(user_data, dtor, onSoundStoppedVal);
}

void irrklangProxy::ISoundStopEventReceiver::onSoundStopped(irrklang::ISoundStopEventReceiver* receiver, irrklang::ISound* sound, irrklang::E_STOP_EVENT_CAUSE reason, void* userData)
{
	receiver->OnSoundStopped(sound, reason, userData);
}

const char* irrklangProxy::ISoundEngine::getDriverName(irrklang::ISoundEngine* engine)
{
	return engine->getDriverName();
}

irrklang::ISound* irrklangProxy::ISoundEngine::play2DFileName(
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

irrklang::ISound* irrklangProxy::ISoundEngine::play2DSoundSource(
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

irrklang::ISound* irrklangProxy::ISoundEngine::play3DFileName(
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


irrklang::ISound* irrklangProxy::ISoundEngine::play3DSoundSource(
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


void irrklangProxy::ISoundEngine::stopAllSounds(irrklang::ISoundEngine* engine)
{
	engine->stopAllSounds();
}


void  irrklangProxy::ISoundEngine::setAllSoundsPaused(irrklang::ISoundEngine* engine, bool bPaused)
{
	engine->setAllSoundsPaused(bPaused);
}

irrklang::ISoundSource* irrklangProxy::ISoundEngine::getSoundSourceByName(irrklang::ISoundEngine* engine, const char* soundName, bool addIfNotFound)
{
	return engine->getSoundSource(soundName, addIfNotFound);
}

irrklang::ISoundSource* irrklangProxy::ISoundEngine::getSoundSourceByIndex(irrklang::ISoundEngine* engine, int index)
{
	return engine->getSoundSource(index);
}

int irrklangProxy::ISoundEngine::getSoundSourceCount(irrklang::ISoundEngine* engine)
{
	return engine->getSoundSourceCount();
}

irrklang::ISoundSource*  irrklangProxy::ISoundEngine::addSoundSourceFromFile(irrklang::ISoundEngine* engine, const char* fileName, irrklang::E_STREAM_MODE mode, bool preload)
{
	return engine->addSoundSourceFromFile(fileName, mode, preload);
}

irrklang::ISoundSource* irrklangProxy::ISoundEngine::addSoundSourceFromMemory(irrklang::ISoundEngine* engine, void* memory, int sizeInBytes, const char* soundName, bool copyMemory)
{
	return engine->addSoundSourceFromMemory(memory, sizeInBytes, soundName, copyMemory);
}

irrklang::ISoundSource*  irrklangProxy::ISoundEngine::addSoundSourceFromPCMData(
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

irrklang::ISoundSource* irrklangProxy::ISoundEngine::addSoundSourceAlias(irrklang::ISoundEngine* engine, irrklang::ISoundSource* baseSource, const char* soundName)
{
	return engine->addSoundSourceAlias(baseSource, soundName);
}

void irrklangProxy::ISoundEngine::removeSoundSource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source)
{
	engine->removeSoundSource(source);
}

void irrklangProxy::ISoundEngine::removeSoundSourceByName(irrklang::ISoundEngine* engine, const char* name)
{
	engine->removeSoundSource(name);
}

void irrklangProxy::ISoundEngine::removeAllSoundSources(irrklang::ISoundEngine* engine)
{
	engine->removeAllSoundSources();
}

void irrklangProxy::ISoundEngine::setSoundVolume(irrklang::ISoundEngine* engine, float volume)
{
	engine->setSoundVolume(volume);
}

float irrklangProxy::ISoundEngine::getSoundVolume(irrklang::ISoundEngine* engine)
{
	return engine->getSoundVolume();
}

void irrklangProxy::ISoundEngine::setListenerPosition(
	irrklang::ISoundEngine* engine,
	const irrklang::vec3df& pos,
	const irrklang::vec3df& lookdir,
	const irrklang::vec3df& velPerSecond,
	const irrklang::vec3df& upVector
)
{
	engine->setListenerPosition(pos, lookdir, velPerSecond, upVector);
}

void irrklangProxy::ISoundEngine::updateSoundEngine(irrklang::ISoundEngine* engine)
{
	engine->update();
}


void irrklangProxy::ISoundEngine::grabSoundEngine(irrklang::ISoundEngine* engine)
{
	engine->grab();
}

void irrklangProxy::ISoundEngine::dropSoundEngine(irrklang::ISoundEngine* engine)
{
	engine->drop();
}

bool irrklangProxy::ISoundEngine::isCurrentlyPlayingByName(irrklang::ISoundEngine* engine, const char* soundName)
{
	return engine->isCurrentlyPlaying(soundName);
}

bool irrklangProxy::ISoundEngine::isCurrentlyPlayingBySource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source)
{
	return engine->isCurrentlyPlaying(source);
}

void irrklangProxy::ISoundEngine::registerAudioStreamLoader(irrklang::ISoundEngine* engine, irrklang::IAudioStreamLoader* loader)
{
	engine->registerAudioStreamLoader(loader);
}

bool irrklangProxy::ISoundEngine::isMultiThreaded(irrklang::ISoundEngine* engine)
{
	return engine->isMultiThreaded();
}

void irrklangProxy::ISoundEngine::addFileFactory(irrklang::ISoundEngine* engine,irrklang::IFileFactory* fileFactory)
{
	engine->addFileFactory(fileFactory);
}

void irrklangProxy::ISoundEngine::setDefault3DSoundMinDistance(irrklang::ISoundEngine* engine, float minDistance)
{
	engine->setDefault3DSoundMinDistance(minDistance);
}

float irrklangProxy::ISoundEngine::getDefault3DSoundMinDistance(irrklang::ISoundEngine* engine)
{
	return engine->getDefault3DSoundMinDistance();
}

void irrklangProxy::ISoundEngine::setDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine, float maxDistance)
{
	engine->setDefault3DSoundMaxDistance(maxDistance);
}

float irrklangProxy::ISoundEngine::getDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine)
{
	return engine->getDefault3DSoundMaxDistance();
}

void irrklangProxy::ISoundEngine::setRolloffFactor(irrklang::ISoundEngine* engine, float rolloff)
{
	engine->setRolloffFactor(rolloff);
}

void irrklangProxy::ISoundEngine::setDopplerEffectParameters(irrklang::ISoundEngine* engine, float dopplerFactor, float distanceFactor)
{
	engine->setDopplerEffectParameters(dopplerFactor, distanceFactor);
}

bool irrklangProxy::ISoundEngine::loadPlugins(irrklang::ISoundEngine* engine, const char* path)
{
	return engine->loadPlugins(path);
}

const irrklang::SInternalAudioInterface* irrklangProxy::ISoundEngine::getInternalAudioInterface(irrklang::ISoundEngine* engine)
{
	return &(engine->getInternalAudioInterface());
}

bool irrklangProxy::ISoundEngine::setMixedDataOutputReceiver(irrklang::ISoundEngine* engine, irrklang::ISoundMixedOutputReceiver* receiver)
{
	return engine->setMixedDataOutputReceiver(receiver);
}

int irrklangProxy::ISoundDeviceList::getDeviceCount(irrklang::ISoundDeviceList* list)
{
	return list->getDeviceCount();
}

const char*  irrklangProxy::ISoundDeviceList::getDeviceID(irrklang::ISoundDeviceList* list, int index)
{
	return list->getDeviceID(index);
}

const char* KDECL irrklangProxy::ISoundDeviceList::getDeviceDescription(irrklang::ISoundDeviceList* list, int index)
{
	return list->getDeviceDescription(index);
}

void irrklangProxy::ISoundDeviceList::grabSoundDeviceList(irrklang::ISoundDeviceList* list)
{
	list->grab();
}

void irrklangProxy::ISoundDeviceList::dropSoundDeviceList(irrklang::ISoundDeviceList* list)
{
	list->drop();
}

bool irrklangProxy::IAudioRecorder::startRecordingBufferedAudio(irrklang::IAudioRecorder* recorder, irrklang::ik_s32 sampleRate , irrklang::ESampleFormat sampleFormat, irrklang::ik_s32 channelCount)
{
	return recorder->startRecordingBufferedAudio(sampleRate, sampleFormat, channelCount);
}

bool irrklangProxy::IAudioRecorder::startRecordingCustomHandledAudio(irrklang::IAudioRecorder* recorder, irrklang::ICapturedAudioDataReceiver* receiver, irrklang::ik_s32 sampleRate, irrklang::ESampleFormat sampleFormat, irrklang::ik_s32 channelCount)
{
	return recorder->startRecordingCustomHandledAudio(receiver, sampleRate, sampleFormat, channelCount);
}

void irrklangProxy::IAudioRecorder::stopRecordingAudio(irrklang::IAudioRecorder* recorder)
{
	recorder->stopRecordingAudio();
}

irrklang::ISoundSource* irrklangProxy::IAudioRecorder::addSoundSourceFromRecordedAudio(irrklang::IAudioRecorder* recorder, const char* soundName)
{
	return recorder->addSoundSourceFromRecordedAudio(soundName);
}

void irrklangProxy::IAudioRecorder::clearRecordedAudioDataBuffer(irrklang::IAudioRecorder* recorder)
{
	recorder->clearRecordedAudioDataBuffer();
}

bool irrklangProxy::IAudioRecorder::isRecording(irrklang::IAudioRecorder* recorder)
{
	return recorder->isRecording();
}

irrklang::SAudioStreamFormat irrklangProxy::IAudioRecorder::getAudioFormat(irrklang::IAudioRecorder* recorder)
{
	return recorder->getAudioFormat();
}

void* irrklangProxy::IAudioRecorder::getRecordedAudioData(irrklang::IAudioRecorder* recorder)
{
	return recorder->getRecordedAudioData();
}

const char* irrklangProxy::IAudioRecorder::getDriverName(irrklang::IAudioRecorder* recorder)
{
	return recorder->getDriverName();
}


BOOL APIENTRY DllMain( HMODULE,
                       DWORD,
                       LPVOID
                     )
{
    return TRUE;
}

