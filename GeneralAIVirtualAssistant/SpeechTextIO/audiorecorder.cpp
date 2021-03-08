#include "audiorecorder.h"


AudioRecorder::AudioRecorder()
{
    audioRecorder = new QAudioRecorder();
}

int AudioRecorder::Initialize()
{

    LoadAudioSettings();
    SetupAudioSettings();

    return 1;
}

void AudioRecorder::LoadAudioSettings()
{
    std::unique_ptr<QFile>  file(new QFile(QDir::currentPath() + DATA_PATH + AUDIO_SET_PATH));

    if (!file->open(QIODevice::ReadWrite)) return;

    QJsonDocument doc = QJsonDocument::fromJson(file->readAll());
    QJsonObject jObj = doc.object();

    if (jObj.contains("audioCodec") && jObj["audioCodec"].isString()) {
        audioCodec = jObj["audioCodec"].toString();
    }


    if (jObj.contains("sampleRate") && jObj["sampleRate"].isString()) {
        sampleRate = jObj["sampleRate"].toInt();
    }

    if (jObj.contains("channelCount") && jObj["channelCount"].isString()) {
        channelCount = jObj["channelCount"].toInt();
    }

    if (jObj.contains("bitRate") && jObj["bitRate"].isString()) {
        bitRate = jObj["bitRate"].toInt();
    }

    if (jObj.contains("fileContainer") && jObj["fileContainer"].isString()) {
        fileContainer = jObj["fileContainer"].toString();
    }
}

void AudioRecorder::SetupAudioSettings()
{
    settings.setCodec(audioCodec);
    settings.setSampleRate(sampleRate);
    settings.setChannelCount(channelCount);
    settings.setBitRate(bitRate);
    settings.setQuality(QMultimedia::EncodingQuality::VeryHighQuality);
    settings.setEncodingMode( QMultimedia::ConstantBitRateEncoding);
    audioRecorder->setEncodingSettings(settings, QVideoEncoderSettings(), fileContainer);
    QString path = QDir::currentPath() + DATA_PATH +RECORD_PATH;

    audioRecorder->setOutputLocation(QUrl::fromLocalFile(path));
}

int AudioRecorder::StartRecording()
{
    if (audioRecorder->state() == QMediaRecorder::StoppedState){
        audioRecorder->record();
        return 1;
    }else{
        return 0;
    }
}

void AudioRecorder::StopRecording()
{
    audioRecorder->stop();
}
