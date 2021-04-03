#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QAudioRecorder>
#include <QDir>
#include <QUrl>
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
    QAudioRecorder*                 m_audioRecorder   = nullptr;
    QAudioEncoderSettings           m_settings;
    QString                         m_audioCodec      = "audio/pcm";
    QString                         m_fileContainer   = "audio/x-wav";
    int                             m_sampleRate      = 16000;
    int                             m_bitRate         = 196000;
    int                             m_channelCount    = 1;
};

#endif // AUDIORECORDER_H
