#pragma once

#ifndef R_LPF_H
#define R_LPF_H

namespace R_LPF
{
    inline constexpr float calculate_lpf_alpha(float delta_time,float frequency);
};

#endif