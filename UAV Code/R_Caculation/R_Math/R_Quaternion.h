#pragma once

#ifndef R_QUATERNION_H
#define R_QUATERNION_H

#include "R_Math.h"
#include "R_Matrix.h"
#include "R_Eulerangle.h"

namespace R_Quaternion
{
    class R_Quaternion
    {
        public:
            R_Float q1;
            R_Float q2;
            R_Float q3;
            R_Float q4;

            R_Quaternion(){}
            R_Quaternion(R_Float input1,R_Float input2,R_Float input3,R_Float input4);
            inline R_Quaternion operator+(R_Quaternion input);
            inline R_Quaternion operator-(R_Quaternion input);
            inline R_Quaternion operator*(R_Quaternion input);
            inline R_Quaternion operator*(R_Float input);
            inline void operator+=(R_Quaternion input);
            inline void operator-=(R_Quaternion input);
            inline void operator*=(R_Quaternion input);
            inline void operator*=(R_Float input);
            inline void operator=(R_Quaternion input);
            inline R_Float norm();
            inline void normalize();
            inline R_MATRIX::r_matrix3d Quaternion_to_DCM();
            inline R_Eulerangle::R_Eulerangle Quaternion_to_Eulerangle();
    };
};

#endif