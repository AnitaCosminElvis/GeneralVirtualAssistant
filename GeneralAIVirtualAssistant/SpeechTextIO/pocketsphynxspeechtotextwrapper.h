#ifndef POCKETSPHYNXSPEECHTOTEXTWRAPPER_H
#define POCKETSPHYNXSPEECHTOTEXTWRAPPER_H

#include <string>
#include "ISpeechToText.h"
#include "Data/Defines.h"
#include "bin/include/pocketsphinx.h"
#include <sphinxbase/err.h>
#include <sphinxbase/ad.h>
#include <QLibrary>

typedef cmd_ln_t*       pcmd_ln_init(cmd_ln_t *inout_cmdln, arg_t const *defn, int32 strict, ...);
typedef arg_t const*    pps_args(void);
typedef ps_decoder_t*   pps_init(cmd_ln_t *config);
typedef int             pps_start_utt(ps_decoder_t *ps);
typedef int             pps_process_raw(ps_decoder_t *ps,
                                        int16 const *data,
                                        size_t n_samples,
                                        int no_search,
                                        int full_utt);
typedef int             pps_end_utt(ps_decoder_t *ps);
typedef char const*     pps_get_hyp(ps_decoder_t *ps, int32 *out_best_score);
typedef int             pps_free(ps_decoder_t *ps);
typedef int             pcmd_ln_free_r(cmd_ln_t *cmdln);

class PocketSphynxSpeechToTextWrapper: public ISpeechToText
{
public:
    PocketSphynxSpeechToTextWrapper();
    ~PocketSphynxSpeechToTextWrapper();

    int Initialize() override;
    std::string ConvertSpeechToText() override;
private:
    QLibrary*           sphinxLib = nullptr;
    QLibrary*           pocketLib = nullptr;
    ps_decoder_t*       ps_decoder = nullptr;
    cmd_ln_t*           config = nullptr;
    pcmd_ln_init*       cmd_ln_init = nullptr;
    pps_args*           ps_args = nullptr;
    pps_init*           ps_init = nullptr;
    pps_start_utt*      ps_start_utt = nullptr;
    pps_process_raw*    ps_process_raw = nullptr;
    pps_end_utt*        ps_end_utt = nullptr;
    pps_get_hyp*        ps_get_hyp = nullptr;
    pps_free*           ps_free = nullptr;
    pcmd_ln_free_r*     cmd_ln_free_r = nullptr;
};

#endif // POCKETSPHYNXSPEECHTOTEXTWRAPPER_H
