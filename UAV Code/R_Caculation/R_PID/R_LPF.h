#pragma once

#ifndef R_LPF_H
#define R_LPF_H

namespace R_LPF
{
    class R_LPF_Calculate
    {
        public:
            float alpha;
            float result;
            inline R_LPF_Calculate(float delta_time,float frequency);
            inline void Calculate(float sample);
    };
};

#endif