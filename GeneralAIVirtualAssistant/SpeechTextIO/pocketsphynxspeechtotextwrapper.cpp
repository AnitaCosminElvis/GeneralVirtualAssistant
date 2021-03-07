#include "pocketsphynxspeechtotextwrapper.h"
#include <QDir>

PocketSphynxSpeechToTextWrapper::PocketSphynxSpeechToTextWrapper()
{
    sphinxLib = new QLibrary("C:/Users/selectuls/Documents/GeneralVA/GeneralAIVirtualAssistant/SpeechTextIO/bin/Release/Win32/sphinxbase");
    pocketLib = new QLibrary("C:/Users/selectuls/Documents/GeneralVA/GeneralAIVirtualAssistant/SpeechTextIO/bin/Release/Win32/pocketsphinx");

    cmd_ln_init = reinterpret_cast<pcmd_ln_init*> (sphinxLib->resolve("cmd_ln_init"));
    ps_args = reinterpret_cast<pps_args*> (pocketLib->resolve("ps_args"));
    ps_init = reinterpret_cast<pps_init*> (pocketLib->resolve("ps_init"));
    ps_start_utt = reinterpret_cast<pps_start_utt*> (pocketLib->resolve("ps_start_utt"));
    ps_process_raw = reinterpret_cast<pps_process_raw*> (pocketLib->resolve("ps_process_raw"));
    ps_end_utt = reinterpret_cast<pps_end_utt*> (pocketLib->resolve("ps_end_utt"));
    ps_get_hyp = reinterpret_cast<pps_get_hyp*> (pocketLib->resolve("ps_get_hyp"));
    ps_free = reinterpret_cast<pps_free*> (pocketLib->resolve("ps_free"));
    cmd_ln_free_r = reinterpret_cast<pcmd_ln_free_r*> (pocketLib->resolve("cmd_ln_free_r"));

    config = cmd_ln_init(NULL, ps_args(), TRUE,
                 "-hmm", MODELDIR "/en-us/en-us",
                 "-lm", MODELDIR "/en-us/en-us.lm.bin",
                 "-dict", MODELDIR "/en-us/cmudict-en-us.dict",
                 NULL);

    if (config == NULL) {
       qDebug("Failed to create config object, see log for details\n");
       return;
    }

    ps_decoder = ps_init(config);

    if (ps_decoder == NULL) {
       qDebug("Failed to create recognizer, see log for details\n");
       return;
    }
}

PocketSphynxSpeechToTextWrapper::~PocketSphynxSpeechToTextWrapper()
{
    ps_free(ps_decoder);
    cmd_ln_free_r(config);
}

int PocketSphynxSpeechToTextWrapper::Initialize(){
    return -1;
}


std::string PocketSphynxSpeechToTextWrapper::ConvertSpeechToText(const void *)
{
    FILE *fh = nullptr;
    char const *hyp = nullptr;
    int16 buf[512];
    int rv = 0;
    int32 score = 0;
    QString path = QDir::currentPath() + "/record.raw";

     fh = fopen("C:/Users/selectuls/Desktop/record.wav", "rb");
     if (fh == NULL) {
         qDebug("Unable to open input file goforward.raw\n");
         return "";
     }

     rv = ps_start_utt(ps_decoder);

     while (!feof(fh)) {
         size_t nsamp;
         nsamp = fread(buf, 2, 512, fh);
         rv = ps_process_raw(ps_decoder, buf, nsamp, FALSE, FALSE);
     }

     rv = ps_end_utt(ps_decoder);
     hyp = ps_get_hyp(ps_decoder, &score);
     qDebug("Recognized: %s\n", hyp);

     fclose(fh);

    if (hyp != nullptr){
        return std::string(hyp);
    }else{

        return "";
    }
}
