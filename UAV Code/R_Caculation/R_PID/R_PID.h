#pragma once

#ifndef R_PID_H
#define R_PID_H

#include "R_LPF.h"

namespace R_PID
{
    typedef struct _R_PID_Parameter
    {
        float kp;
        float ki;
        float kd;
    }R_PID_Parameter;

    class R_PID_Calculate
    {
        public:
            R_PID_Parameter parameter;
            float kff;
            float imax;
            float E_frequency;
            float D_frequency;
            R_LPF::R_LPF_Calculate low_pass_filter;

            float target;
            float delta_time;
            float error;
            float derivative;
            float integrator;
    };
};

#endif