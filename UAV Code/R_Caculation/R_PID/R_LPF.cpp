#include "R_LPF.h"
#include "R_Math.h"

namespace R_LPF
{
    inline R_LPF_Calculate::R_LPF_Calculate(float delta_time,float frequency)
    {
        float rc=div(1.0f,mul((float)DOUBLE_PI,frequency));
        alpha=div(delta_time,add(delta_time,rc));
    }
    inline void R_LPF_Calculate::Calculate(float sample)
    {
        result=add(mul(alpha,sample),mul(sub((float)1,alpha),result));
    }
};