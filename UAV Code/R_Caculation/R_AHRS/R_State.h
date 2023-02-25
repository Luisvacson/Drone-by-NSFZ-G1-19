#ifndef R_STATE_H
#define R_STATE_H

#include "R_Math.h"

using namespace R_VECTOR;

struct R_EKF_State_Packed
{
    R_Quaternion attitude;
};

struct R_EKF_State_Unpacked
{
    
};

#endif