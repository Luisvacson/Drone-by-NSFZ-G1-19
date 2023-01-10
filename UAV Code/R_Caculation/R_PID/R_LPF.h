#pragma once

#ifndef R_LPF_H
#define R_LPF_H

#include "R_Math.h"
namespace R_LPF
{
    class R_LPF_Calculate
    {
        public:
            R_Float alpha;
            inline R_LPF_Calculate(){}
            inline void set(R_Float delta_time,R_Float frequency);
            inline R_Float Calculate(R_Float sample,R_Float last_result);
    };
};

#endif