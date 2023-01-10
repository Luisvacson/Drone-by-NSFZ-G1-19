#pragma once

#ifndef R_PID_H
#define R_PID_H

#include "R_LPF.h"
#include "R_Math.h"

namespace R_PID
{
    typedef struct _R_PID_Parameter
    {
        R_Float kp;
        R_Float ki;
        R_Float kd;
    }R_PID_Parameter;

    class R_PID_Calculate
    {
        public:
            R_PID_Parameter parameter;
            R_Float kff;
            R_Float imax;
            R_Float E_frequency;
            R_Float D_frequency;
            R_LPF::R_LPF_Calculate E_filter;
            R_LPF::R_LPF_Calculate D_filter;

            bool reset_filter_flag=false;

            R_Float target;
            R_Float delta_time;
            R_Float error;
            R_Float derivative;
            R_Float integrator;

            inline R_PID_Calculate(R_Float initial_kp, R_Float initial_ki, R_Float initial_kd, R_Float initial_kff, R_Float initial_imax, R_Float initial_E_frequency, R_Float initial_D_frequency, R_Float dt);
            inline R_Float update(R_Float _target,R_Float measurement,bool limit);
            inline void reset_filter(){reset_filter_flag=true;}
            inline void reset_integrator(){integrator=0;}
    };
};

#endif