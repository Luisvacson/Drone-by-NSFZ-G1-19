#include "R_LPF.h"
#include "R_Math.h"

namespace R_LPF
{
    inline void R_LPF_Calculate::set(R_Float delta_time,R_Float frequency)
    {
        R_Float rc=1.0f/((float)DOUBLE_PI*frequency);
        alpha=delta_time/(delta_time+rc);
    }
    inline R_Float R_LPF_Calculate::Calculate(R_Float sample,R_Float last_result)
    {
        return (alpha*sample)+(((float)1-alpha)*last_result);
    }
};