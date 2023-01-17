#include "R_Eulerangle.h"

namespace R_Eulerangle
{
    R_Eulerangle::R_Eulerangle(R_Float input1,R_Float input2,R_Float input3)
    {
        pitch=input1;
        roll=input2;
        yaw=input3;
    }
    inline void R_Eulerangle::operator=(R_Eulerangle input)
    {
        pitch=input.pitch;
        roll=input.roll;
        yaw=input.yaw;
    }
};