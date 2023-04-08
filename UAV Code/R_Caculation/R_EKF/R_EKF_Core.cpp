#include "R_EKF_Core.h"

#define sq(input) (input*input)

inline R_EKF_Core::R_EKF_Core()
{}

inline void R_EKF_Core::initialize()
{}

void R_EKF_Core::predict_state(R_Acc_Output acc,R_Gyro_Output gyro)
{
    R_Float acc_x = acc.acc_x;
    R_Float acc_y = acc.acc_y;
    R_Float acc_z = acc.acc_z;
    R_Float omega_x = gyro.omega_x;
    R_Float omega_y = gyro.omega_y;
    R_Float omega_z = gyro.omega_z;

    R_Float temp1 = sq(q1) + sq(q2) - sq(q3) - sq(q4);

    velocity_n = velocity_n + dt*g_n + temp1*(acc_x*dt - acc_bias_x*dt - (da_prev_z*(acc_y*dt - acc_bias_y*dt))/12 + (da_prev_y*(acc_z*dt - acc_bias_z*dt))/12 + (dv_prev_y*(dt*omega_z - dt*omega_bias_z - (da_prev_y*(dt*omega_x - dt*omega_bias_x))/12 + (da_prev_x*(dt*omega_y - dt*omega_bias_y))/12))/12 - (dv_prev_z*(dt*omega_y - dt*omega_bias_y + (da_prev_z*(dt*omega_x - dt*omega_bias_x))/12 - (da_prev_x*(dt*omega_z - dt*omega_bias_z))/12))/12 - ((acc_y*dt - acc_bias_y*dt)*(dt*omega_z - dt*omega_bias_z - (da_prev_y*(dt*omega_x - dt*omega_bias_x))/12 + (da_prev_x*(dt*omega_y - dt*omega_bias_y))/12))/2 + ((acc_z*dt - acc_bias_z*dt)*(dt*omega_y - dt*omega_bias_y + (da_prev_z*(dt*omega_x - dt*omega_bias_x))/12 - (da_prev_x*(dt*omega_z - dt*omega_bias_z))/12))/2) + (2*q1*q3 + 2*q2*q4)*(acc_z*dt - acc_bias_z*dt - (da_prev_y*(acc_x*dt - acc_bias_x*dt))/12 + (da_prev_x*(acc_y*dt - acc_bias_y*dt))/12 + (dv_prev_x*(dt*omega_y - dt*omega_bias_y + (da_prev_z*(dt*omega_x - dt*omega_bias_x))/12 - (da_prev_x*(dt*omega_z - dt*omega_bias_z))/12))/12 - (dv_prev_y*(dt*omega_x - dt*omega_bias_x - (da_prev_z*(dt*omega_y - dt*omega_bias_y))/12 + (da_prev_y*(dt*omega_z - dt*omega_bias_z))/12))/12 - ((acc_x*dt - acc_bias_x*dt)*(dt*omega_y - dt*omega_bias_y + (da_prev_z*(dt*omega_x - dt*omega_bias_x))/12 - (da_prev_x*(dt*omega_z - dt*omega_bias_z))/12))/2 + ((acc_y*dt - acc_bias_y*dt)*(dt*omega_x - dt*omega_bias_x - (da_prev_z*(dt*omega_y - dt*omega_bias_y))/12 + (da_prev_y*(dt*omega_z - dt*omega_bias_z))/12))/2) - (2*q1*q4 - 2*q2*q3)*(acc_y*dt - acc_bias_y*dt + (da_prev_z*(acc_x*dt - acc_bias_x*dt))/12 - (da_prev_x*(acc_z*dt - acc_bias_z*dt))/12 - (dv_prev_x*(dt*omega_z - dt*omega_bias_z - (da_prev_y*(dt*omega_x - dt*omega_bias_x))/12 + (da_prev_x*(dt*omega_y - dt*omega_bias_y))/12))/12 + (dv_prev_z*(dt*omega_x - dt*omega_bias_x - (da_prev_z*(dt*omega_y - dt*omega_bias_y))/12 + (da_prev_y*(dt*omega_z - dt*omega_bias_z))/12))/12 + ((acc_x*dt - acc_bias_x*dt)*(dt*omega_z - dt*omega_bias_z - (da_prev_y*(dt*omega_x - dt*omega_bias_x))/12 + (da_prev_x*(dt*omega_y - dt*omega_bias_y))/12))/2 - ((acc_z*dt - acc_bias_z*dt)*(dt*omega_x - dt*omega_bias_x - (da_prev_z*(dt*omega_y - dt*omega_bias_y))/12 + (da_prev_y*(dt*omega_z - dt*omega_bias_z))/12))/2);
    velocity_e = velocity_e + dt*g_e + temp1*(acc_y*dt - acc_bias_y*dt + (da_prev_z*(acc_x*dt - acc_bias_x*dt))/12 - (da_prev_x*(acc_z*dt - acc_bias_z*dt))/12 - (dv_prev_x*(dt*omega_z - dt*omega_bias_z - (da_prev_y*(dt*omega_x - dt*omega_bias_x))/12 + (da_prev_x*(dt*omega_y - dt*omega_bias_y))/12))/12 + (dv_prev_z*(dt*omega_x - dt*omega_bias_x - (da_prev_z*(dt*omega_y - dt*omega_bias_y))/12 + (da_prev_y*(dt*omega_z - dt*omega_bias_z))/12))/12 + ((acc_x*dt - acc_bias_x*dt)*(dt*omega_z - dt*omega_bias_z - (da_prev_y*(dt*omega_x - dt*omega_bias_x))/12 + (da_prev_x*(dt*omega_y - dt*omega_bias_y))/12))/2 - ((acc_z*dt - acc_bias_z*dt)*(dt*omega_x - dt*omega_bias_x - (da_prev_z*(dt*omega_y - dt*omega_bias_y))/12 + (da_prev_y*(dt*omega_z - dt*omega_bias_z))/12))/2) - (2*q1*q2 - 2*q3*q4)*(acc_z*dt - acc_bias_z*dt - (da_prev_y*(acc_x*dt - acc_bias_x*dt))/12 + (da_prev_x*(acc_y*dt - acc_bias_y*dt))/12 + (dv_prev_x*(dt*omega_y - dt*omega_bias_y + (da_prev_z*(dt*omega_x - dt*omega_bias_x))/12 - (da_prev_x*(dt*omega_z - dt*omega_bias_z))/12))/12 - (dv_prev_y*(dt*omega_x - dt*omega_bias_x - (da_prev_z*(dt*omega_y - dt*omega_bias_y))/12 + (da_prev_y*(dt*omega_z - dt*omega_bias_z))/12))/12 - ((acc_x*dt - acc_bias_x*dt)*(dt*omega_y - dt*omega_bias_y + (da_prev_z*(dt*omega_x - dt*omega_bias_x))/12 - (da_prev_x*(dt*omega_z - dt*omega_bias_z))/12))/2 + ((acc_y*dt - acc_bias_y*dt)*(dt*omega_x - dt*omega_bias_x - (da_prev_z*(dt*omega_y - dt*omega_bias_y))/12 + (da_prev_y*(dt*omega_z - dt*omega_bias_z))/12))/2) + (2*q1*q4 + 2*q2*q3)*(acc_x*dt - acc_bias_x*dt - (da_prev_z*(acc_y*dt - acc_bias_y*dt))/12 + (da_prev_y*(acc_z*dt - acc_bias_z*dt))/12 + (dv_prev_y*(dt*omega_z - dt*omega_bias_z - (da_prev_y*(dt*omega_x - dt*omega_bias_x))/12 + (da_prev_x*(dt*omega_y - dt*omega_bias_y))/12))/12 - (dv_prev_z*(dt*omega_y - dt*omega_bias_y + (da_prev_z*(dt*omega_x - dt*omega_bias_x))/12 - (da_prev_x*(dt*omega_z - dt*omega_bias_z))/12))/12 - ((acc_y*dt - acc_bias_y*dt)*(dt*omega_z - dt*omega_bias_z - (da_prev_y*(dt*omega_x - dt*omega_bias_x))/12 + (da_prev_x*(dt*omega_y - dt*omega_bias_y))/12))/2 + ((acc_z*dt - acc_bias_z*dt)*(dt*omega_y - dt*omega_bias_y + (da_prev_z*(dt*omega_x - dt*omega_bias_x))/12 - (da_prev_x*(dt*omega_z - dt*omega_bias_z))/12))/2);
 




}

void R_EKF_Core::claculate_optimse(R_Acc_Output acc,R_Gyro_Output gyro)
{}

void R_EKF_Core::predict_covariances()
{}




