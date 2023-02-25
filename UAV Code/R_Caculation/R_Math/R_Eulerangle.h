#pragma once

#ifndef R_Eulerangle_H
#define R_Eulerangle_H

#include "R_Math.h"


class R_Eulerangle
{
    public:
        R_Float pitch;
        R_Float roll;
        R_Float yaw;
        R_Eulerangle(){}
        R_Eulerangle(R_Float input1,R_Float input2,R_Float input3);
        inline void operator+(R_Eulerangle input);
        inline void operator+=(R_Eulerangle input);
        inline void operator=(R_Eulerangle input);
};

#endif