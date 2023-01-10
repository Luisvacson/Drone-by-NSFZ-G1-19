#pragma once

#ifndef R_MATH_H
#define R_MATH_H

template<typename T>class R_Number
{
    private:
        T content;
    public:
        inline R_Number(T input);
        inline R_Number<T> operator+(R_Number<T> input);
        inline R_Number<T> operator-(R_Number<T> input);
        inline R_Number<T> operator*(R_Number<T> input);
        inline R_Number<T> operator/(R_Number<T> input);
        friend inline R_Number<T> operator+(T input1,R_Number<T> input2);
        friend inline R_Number<T> operator-(T input1,R_Number<T> input2);
        friend inline R_Number<T> operator*(T input1,R_Number<T> input2);
        friend inline R_Number<T> operator/(T input1,R_Number<T> input2);
        inline R_Number<T> operator+=(R_Number<T> input);
        inline R_Number<T> operator-=(R_Number<T> input);
        inline R_Number<T> operator*=(R_Number<T> input);
        inline R_Number<T> operator/=(R_Number<T> input);
        inline bool operator>(R_Number<T> input);
        inline bool operator<(R_Number<T> input);
        inline bool operator>=(R_Number<T> input);
        inline bool operator<=(R_Number<T> input);
        inline bool operator!=(R_Number<T> input);
        inline bool operator==(R_Number<T> input);
        friend inline bool operator>(T input1,R_Number<T> input2);
        friend inline bool operator<(T input1,R_Number<T> input2);
        friend inline bool operator>=(T input1,R_Number<T> input2);
        friend inline bool operator<=(T input1,R_Number<T> input2);
        friend inline bool operator!=(T input1,R_Number<T> input2);
        friend inline bool operator==(T input1,R_Number<T> input2);
        inline void operator=(R_Number<T> input);
        inline void operator=(T input);
};

//template <typename T>
//inline T add(T input1, T input2) {
//    return input1 + input2;
//};
//template <typename T>
//inline T sub(T input1, T input2) {
//    return input1 - input2;
//};
//template <typename T>
//inline T mul(T input1, T input2) {
//    return input1 * input2;
//};
//template <typename T>
//inline T div(T input1, T input2) {
//    return input1 / input2;
//};
//
//#ifdef R_USE_FPU
//template <>
//inline float add<float>(float input1, float input2){};
//template <>
//inline float sub<float>(float input1, float input2){};
//template <>
//inline float mul<float>(float input1, float input2){};
//template <>
//inline float div<float>(float input1, float input2){};
//#endif

#define FLOAT_EPSILON (0.0001)
#define PI (3.1415926)
#define HALF_PI (1.5707963)
#define DOUBLE_PI (6.2831853)
#define DEGREE_TO_RADIAN (0.0174532)
#define RADIAN_TO_DEGREE (57.2957795)

namespace R_MATH {
template <typename T>
inline bool is_zero(R_Number<T> input);
template <typename T>
inline bool is_in_range(R_Number<T> input, R_Number<T> input_min, R_Number<T> input_max);
template <typename T>
inline R_Number<float> degree_to_radian(R_Number<T> input);
template <typename T>
inline R_Number<float> radian_to_degree(R_Number<T> input);
template <typename T>
inline R_Number<T> abs(R_Number<T> input);
template <typename T>
inline R_Number<T> limit(R_Number<T> input, R_Number<T> input_min, R_Number<T> input_max);
template <typename T>
T sin(T input);
template <typename T>
T cos(T input);
template <typename T>
T tan(T input);
template <typename T>
T arcsin(T input);
template <typename T>
T arccos(T input);
template <typename T>
T arctan(T input);
template <typename T>
R_Number<T> exp(R_Number<T> input);
template <typename T>
R_Number<T> sqart(R_Number<T> input);
template <typename T>
inline R_Number<T> max(R_Number<T> input1, R_Number<T> input2);
template <typename T>
inline R_Number<T> max(R_Number<T> input1, R_Number<T> input2, R_Number<T> input3);
template <typename T>
inline R_Number<T> min(R_Number<T> input1, R_Number<T> input2);
template <typename T>
inline R_Number<T> min(R_Number<T> input1, R_Number<T> input2, R_Number<T> input3);
template <typename T1, typename T2>
R_Number<T1> power(R_Number<T1> input, R_Number<T2> num);
template <typename T>
R_Number<T> sum(R_Number<T>* input, int num);
template <typename T>
R_Number<T> sqasum(R_Number<T>* input, int num);
template <typename T>
R_Number<T> mean(R_Number<T>* input, int num);
template <typename T>
R_Number<T> wmean(R_Number<T> input1, R_Number<T> input2, R_Number<T> weight1);
template <typename T>
R_Number<T> sqamean(R_Number<T>* input, int num);
template <typename T>
void swap(R_Number<T>* input1, R_Number<T>* input2);
template <typename T>
R_Number<T> arctan2(R_Number<T> input1, R_Number<T> input2);
template <typename T>
R_Number<T> sat(R_Number<T> input1, R_Number<T> input2);
template <typename T>
R_Number<float> sign(R_Number<T> input2);
};  // namespace R_MATH

#endif