#include "audiorecorder.h"
#include "../Utils/JSONHandler.h"

AudioRecorder::AudioRecorder()
{
    m_audioRecorder = new QAudioRecorder();
}

int AudioRecorder::Initialize()
{

    LoadAudioSettings();
    SetupAudioSettings();

    return 1;
}

void AudioRecorder::LoadAudioSettings()
{
    JSONHandler jsonParser;
    QString path = QDir::currentPath() + DATA_PATH + AUDIO_SET_PATH;

    if (jsonParser.LoadJSONFromSettingsFile(path)){

        QString audioCodec = jsonParser.GetValueByJSONPath({"audioCodec"});
        if (!audioCodec.isEmpty()) m_audioCodec = audioCodec;

        QString sampleRate = jsonParser.GetValueByJSONPath({"sampleRate"});
        if (!sampleRate.isEmpty()) m_sampleRate = sampleRate.toInt();

        QString channelCount = jsonParser.GetValueByJSONPath({"channelCount"});
        if (!channelCount.isEmpty()) m_channelCount = channelCount.toInt();

        QString bitRate = jsonParser.GetValueByJSONPath({"bitRate"});
        if (!bitRate.isEmpty()) m_bitRate = bitRate.toInt();

        QString fileContainer = jsonParser.GetValueByJSONPath({"fileContainer"});
        if (!fileContainer.isEmpty()) m_fileContainer = fileContainer;
    }
}

void AudioRecorder::SetupAudioSettings()
{
    m_settings.setCodec(m_audioCodec);
    m_settings.setSampleRate(m_sampleRate);
    m_settings.setChannelCount(m_channelCount);
    m_settings.setBitRate(m_bitRate);
    m_settings.setQuality(QMultimedia::EncodingQuality::VeryHighQuality);
    m_settings.setEncodingMode( QMultimedia::ConstantBitRateEncoding);
    m_audioRecorder->setEncodingSettings(m_settings, QVideoEncoderSettings(), m_fileContainer);
    QString path = QDir::currentPath() + DATA_PATH +RECORD_PATH;

    m_audioRecorder->setOutputLocation(QUrl::fromLocalFile(path));
}

int AudioRecorder::StartRecording()
{
    if (m_audioRecorder->state() == QMediaRecorder::StoppedState){
        m_audioRecorder->record();
        return 1;
    }else{
        return 0;
    }
}

void AudioRecorder::StopRecording()
{
    m_audioRecorder->stop();
}
