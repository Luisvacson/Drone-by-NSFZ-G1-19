#ifndef R_STATE_H
#define R_STATE_H

#include "R_Math.h"

struct R_EKF_State_Packed
{
    R_Quaternion attitude;
    R_Vector3d velocity;
    R_Vector3d position;
    R_Vector3d omega_bias;
    R_Vector3d acc_bias;
    R_Vector3d mag;
    R_Vector3d mag_bias;
    R_Float baro_bias;
};

struct R_EKF_State_Unpacked
{
    R_Float q1;
    R_Float q2;
    R_Float q3;
    R_Float q4;
    R_Float velocity_n;
    R_Float velocity_e;
    R_Float velocity_d;
    R_Float position_n;
    R_Float position_e;
    R_Float position_d;
    R_Float omega_bias_x;
    R_Float omega_bias_y;
    R_Float omega_bias_z;
    R_Float acc_bias_x;
    R_Float acc_bias_y;
    R_Float acc_bias_z;
    R_Float mag_n;
    R_Float mag_e;
    R_Float mag_d;
    R_Float mag_bias_x;
    R_Float mag_bias_y;
    R_Float mag_bias_z;
    R_Float baro_bias;
};

struct R_EKF_State_Output
{
    R_Eulerangle attitude;
    R_Vector3d velocity;
    R_Vector3d position;
};

#endif