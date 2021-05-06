#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QAudioRecorder>
#include <QDir>
#include <QUrl>
#include <QVariantMap>
#include <memory>

#include "../Data/Defines.h"

class AudioRecorderWrapper
{
public:
    AudioRecorderWrapper();
    int Initialize();

    int StartRecording();
    void StopRecording();

private:
    void LoadAudioSettings();
    void SetupAudioSettings();

private:
    std::unique_ptr<QAudioRecorder> m_audioRecorder;
    QAudioEncoderSettings           m_settings;
    QString                         m_audioCodec      = "audio/pcm";
    QString                         m_fileContainer   = "audio/x-wav";
    int                             m_sampleRate      = 16000;
    int                             m_bitRate         = 128000;
    int                             m_channelCount    = 1;
};

#endif // AUDIORECORDER_H
