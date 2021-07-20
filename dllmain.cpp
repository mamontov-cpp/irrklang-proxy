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

const char* irrklangProxy::SoundEngine::getDriverName(irrklang::ISoundEngine* engine)
{
	return engine->getDriverName();
}

irrklang::ISound* irrklangProxy::SoundEngine::play2DFileName(
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

irrklang::ISound* irrklangProxy::SoundEngine::play2DSoundSource(
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

irrklang::ISound* irrklangProxy::SoundEngine::play3DFileName(
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


irrklang::ISound* irrklangProxy::SoundEngine::play3DSoundSource(
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


void irrklangProxy::SoundEngine::stopAllSounds(irrklang::ISoundEngine* engine)
{
	engine->stopAllSounds();
}


void  irrklangProxy::SoundEngine::setAllSoundsPaused(irrklang::ISoundEngine* engine, bool bPaused)
{
	engine->setAllSoundsPaused(bPaused);
}

irrklang::ISoundSource* irrklangProxy::SoundEngine::getSoundSourceByName(irrklang::ISoundEngine* engine, const char* soundName, bool addIfNotFound)
{
	return engine->getSoundSource(soundName, addIfNotFound);
}

irrklang::ISoundSource* irrklangProxy::SoundEngine::getSoundSourceByIndex(irrklang::ISoundEngine* engine, int index)
{
	return engine->getSoundSource(index);
}

int irrklangProxy::SoundEngine::getSoundSourceCount(irrklang::ISoundEngine* engine)
{
	return engine->getSoundSourceCount();
}

irrklang::ISoundSource*  irrklangProxy::SoundEngine::addSoundSourceFromFile(irrklang::ISoundEngine* engine, const char* fileName, irrklang::E_STREAM_MODE mode, bool preload)
{
	return engine->addSoundSourceFromFile(fileName, mode, preload);
}

irrklang::ISoundSource* irrklangProxy::SoundEngine::addSoundSourceFromMemory(irrklang::ISoundEngine* engine, void* memory, int sizeInBytes, const char* soundName, bool copyMemory)
{
	return engine->addSoundSourceFromMemory(memory, sizeInBytes, soundName, copyMemory);
}

irrklang::ISoundSource*  irrklangProxy::SoundEngine::addSoundSourceFromPCMData(
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

irrklang::ISoundSource* irrklangProxy::SoundEngine::addSoundSourceAlias(irrklang::ISoundEngine* engine, irrklang::ISoundSource* baseSource, const char* soundName)
{
	return engine->addSoundSourceAlias(baseSource, soundName);
}

void irrklangProxy::SoundEngine::removeSoundSource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source)
{
	engine->removeSoundSource(source);
}

void irrklangProxy::SoundEngine::removeSoundSourceByName(irrklang::ISoundEngine* engine, const char* name)
{
	engine->removeSoundSource(name);
}

void irrklangProxy::SoundEngine::removeAllSoundSources(irrklang::ISoundEngine* engine)
{
	engine->removeAllSoundSources();
}

void irrklangProxy::SoundEngine::setSoundVolume(irrklang::ISoundEngine* engine, float volume)
{
	engine->setSoundVolume(volume);
}

float irrklangProxy::SoundEngine::getSoundVolume(irrklang::ISoundEngine* engine)
{
	return engine->getSoundVolume();
}

void irrklangProxy::SoundEngine::setListenerPosition(
	irrklang::ISoundEngine* engine,
	const irrklang::vec3df& pos,
	const irrklang::vec3df& lookdir,
	const irrklang::vec3df& velPerSecond,
	const irrklang::vec3df& upVector
)
{
	engine->setListenerPosition(pos, lookdir, velPerSecond, upVector);
}

void irrklangProxy::SoundEngine::updateSoundEngine(irrklang::ISoundEngine* engine)
{
	engine->update();
}


void irrklangProxy::SoundEngine::grabSoundEngine(irrklang::ISoundEngine* engine)
{
	engine->grab();
}

void irrklangProxy::SoundEngine::dropSoundEngine(irrklang::ISoundEngine* engine)
{
	engine->drop();
}

bool irrklangProxy::SoundEngine::isCurrentlyPlayingByName(irrklang::ISoundEngine* engine, const char* soundName)
{
	return engine->isCurrentlyPlaying(soundName);
}

bool irrklangProxy::SoundEngine::isCurrentlyPlayingBySource(irrklang::ISoundEngine* engine, irrklang::ISoundSource* source)
{
	return engine->isCurrentlyPlaying(source);
}

void registerAudioStreamLoader(irrklang::ISoundEngine* engine, irrklang::IAudioStreamLoader* loader)
{
	engine->registerAudioStreamLoader(loader);
}

bool irrklangProxy::SoundEngine::isMultiThreaded(irrklang::ISoundEngine* engine)
{
	return engine->isMultiThreaded();
}

void irrklangProxy::SoundEngine::setDefault3DSoundMinDistance(irrklang::ISoundEngine* engine, float minDistance)
{
	engine->setDefault3DSoundMinDistance(minDistance);
}

float irrklangProxy::SoundEngine::getDefault3DSoundMinDistance(irrklang::ISoundEngine* engine)
{
	return engine->getDefault3DSoundMinDistance();
}

void irrklangProxy::SoundEngine::setDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine, float maxDistance)
{
	engine->setDefault3DSoundMaxDistance(maxDistance);
}

float irrklangProxy::SoundEngine::getDefault3DSoundMaxDistance(irrklang::ISoundEngine* engine)
{
	return engine->getDefault3DSoundMaxDistance();
}

void irrklangProxy::SoundEngine::setRolloffFactor(irrklang::ISoundEngine* engine, float rolloff)
{
	engine->setRolloffFactor(rolloff);
}

void irrklangProxy::SoundEngine::setDopplerEffectParameters(irrklang::ISoundEngine* engine, float dopplerFactor, float distanceFactor)
{
	engine->setDopplerEffectParameters(dopplerFactor, distanceFactor);
}

bool irrklangProxy::SoundEngine::loadPlugins(irrklang::ISoundEngine* engine, const char* path)
{
	return engine->loadPlugins(path);
}

const irrklang::SInternalAudioInterface* irrklangProxy::SoundEngine::getInternalAudioInterface(irrklang::ISoundEngine* engine)
{
	return &(engine->getInternalAudioInterface());
}

int irrklangProxy::SoundDeviceList::getDeviceCount(irrklang::ISoundDeviceList* list)
{
	return list->getDeviceCount();
}

const char*  irrklangProxy::SoundDeviceList::getDeviceID(irrklang::ISoundDeviceList* list, int index)
{
	return list->getDeviceID(index);
}

const char* KDECL irrklangProxy::SoundDeviceList::getDeviceDescription(irrklang::ISoundDeviceList* list, int index)
{
	return list->getDeviceDescription(index);
}

void irrklangProxy::SoundDeviceList::grabSoundDeviceList(irrklang::ISoundDeviceList* list)
{
	list->grab();
}

void irrklangProxy::SoundDeviceList::dropSoundDeviceList(irrklang::ISoundDeviceList* list)
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

