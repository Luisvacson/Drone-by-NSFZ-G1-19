#include "R_LPF.h"
#include "R_Math.h"

namespace R_LPF
{
    inline constexpr float calculate_lpf_alpha(float delta_time,float frequency)
    {
        float rc=div(1.0f,mul(stastic_cast<float>(DOUBLE_PI),frequency));
        return div(delta_time,add(delta_time,rc));
    }
};