#include "R_PID.h"

namespace R_PID
{
    inline R_PID_Calculate::R_PID_Calculate(R_Float initial_kp, R_Float initial_ki, R_Float initial_kd, R_Float initial_kff, R_Float initial_imax, R_Float initial_E_frequency, R_Float initial_D_frequency, R_Float dt)
    {
        parameter.kp=initial_kp;
        parameter.ki=initial_ki;
        parameter.kd=initial_kd;
        kff=initial_kff;
        imax=initial_imax;
        E_frequency=initial_E_frequency;
        D_frequency=initial_D_frequency;
        delta_time=dt;
        E_filter.set(delta_time,E_frequency);
        D_filter.set(delta_time,D_frequency);
        integrator=(float)(0);
        derivative=(float)(0);
    }

    void R_PID_Calculate::update(R_Float _target,R_Float measurement)
    {
        target=_target;
        if(reset_filter_flag)
        {
            reset_filter_flag=false;
            error=target-measurement;
            derivative=0.0f;
        }
        else
        {
            R_Float last_error=error;
            error=E_filter.Calculate(target-measurement,error);
            R_Float _derivative=(error-last_error)/delta_time;
            derivative=D_filter.Calculate(_derivative,derivative);
        }
    }
};