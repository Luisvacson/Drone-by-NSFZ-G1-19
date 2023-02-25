#include "R_Quaternion.h"

R_Quaternion::R_Quaternion(R_Float input1,R_Float input2,R_Float input3,R_Float input4)
{
    q1=input1;
    q2=input2;
    q3=input3;
    q4=input4;
}

inline void R_Quaternion::operator=(R_Quaternion input)
{
    q1=input.q1;
    q2=input.q2;
    q3=input.q3;
    q4=input.q4;
}