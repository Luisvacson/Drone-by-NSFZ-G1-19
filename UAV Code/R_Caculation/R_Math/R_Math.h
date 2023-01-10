#pragma once

#ifndef R_MATH_H
#define R_MATH_H

template <typename T>
inline T add(T input1, T input2) {
    return input1 + input2;
};
template <typename T>
inline T sub(T input1, T input2) {
    return input1 - input2;
};
template <typename T>
inline T mul(T input1, T input2) {
    return input1 * input2;
};
template <typename T>
inline T div(T input1, T input2) {
    return input1 / input2;
};

#ifdef R_USE_FPU
template <>
inline float add<float>(float input1, float input2){};
template <>
inline float sub<float>(float input1, float input2){};
template <>
inline float mul<float>(float input1, float input2){};
template <>
inline float div<float>(float input1, float input2){};
#endif

#define FLOAT_EPSILON (0.0001)
#define PI (3.1415926)
#define HALF_PI (1.5707963)
#define DOUBLE_PI (6.2831853)
#define DEGREE_TO_RADIAN (0.0174532)
#define RADIAN_TO_DEGREE (57.2957795)

namespace R_MATH {
template <typename T>
inline bool is_zero(T input);
template <typename T>
inline bool is_in_range(T input, T input_min, T input_max);
template <typename T>
inline float degree_to_radian(T input);
template <typename T>
inline float radian_to_degree(T input);
template <typename T>
inline T abs(T input);
template <typename T>
inline T limit(T input, T input_min, T input_max);
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
T exp(T input);
template <typename T>
T sqart(T input);
template <typename T>
inline T max(T input1, T input2);
template <typename T>
inline T max(T input1, T input2, T input3);
template <typename T>
inline T min(T input1, T input2);
template <typename T>
inline T min(T input1, T input2, T input3);
template <typename T1, typename T2>
T1 power(T1 input, T2 num);
template <typename T>
T sum(T* input, int num);
template <typename T>
T sqasum(T* input, int num);
template <typename T>
T mean(T* input, int num);
template <typename T>
T wmean(T input1, T input2, T weight1);
template <typename T>
T sqamean(T* input, int num);
template <typename T1, typename T2>
void swap(T1* input1, T2* input2);
template <typename T>
T arctan2(T input1, T input2);
template <typename T>
T sat(T input1, T input2);
template <typename T>
float sign(T input2);
};  // namespace R_MATH

#endif