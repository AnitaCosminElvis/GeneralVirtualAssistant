#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QAudioRecorder>
#include <QDir>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>

#include "../Data/Defines.h"

class AudioRecorder
{
public:
    AudioRecorder();
    int Initialize();

    int StartRecording();
    void StopRecording();

private:
    void LoadAudioSettings();
    void SetupAudioSettings();



private:
    QAudioRecorder*                 audioRecorder   = nullptr;
    QAudioEncoderSettings           settings;
    QString                         audioCodec      = "audio/pcm";
    QString                         fileContainer   = "audio/x-wav";
    int                             sampleRate      = 16000;
    int                             bitRate         = 128000;
    int                             channelCount    = 1;
};

#endif // AUDIORECORDER_H
