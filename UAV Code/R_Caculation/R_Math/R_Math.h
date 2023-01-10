#pragma once

#ifndef R_MATH_H
#define R_MATH_H

class R_Float
{
    private:
        float content;
    public:
        inline R_Float(float input);
        inline R_Float operator+(R_Float input);
        inline R_Float operator-(R_Float input);
        inline R_Float operator*(R_Float input);
        inline R_Float operator/(R_Float input);
        inline R_Float operator+=(R_Float input);
        inline R_Float operator-=(R_Float input);
        inline R_Float operator*=(R_Float input);
        inline R_Float operator/=(R_Float input);
        inline bool operator==(R_Float input);
        inline void operator=(R_Float input);
};

template <typename T>
inline constexpr T add(T input1, T input2) {
    return input1 + input2;
};
template <typename T>
inline constexpr T sub(T input1, T input2) {
    return input1 - input2;
};
template <typename T>
inline constexpr T mul(T input1, T input2) {
    return input1 * input2;
};
template <typename T>
inline constexpr T div(T input1, T input2) {
    return input1 / input2;
};

#ifdef R_USE_FPU
template <>
inline constexpr float add<float>(float input1, float input2){};
template <>
inline constexpr float sub<float>(float input1, float input2){};
template <>
inline constexpr float mul<float>(float input1, float input2){};
template <>
inline constexpr float div<float>(float input1, float input2){};
#endif

#define FLOAT_EPSILON (0.0001)
#define PI (3.1415926)
#define HALF_PI (1.5707963)
#define DOUBLE_PI (6.2831853)
#define DEGREE_TO_RADIAN (0.0174532)
#define RADIAN_TO_DEGREE (57.2957795)

namespace R_MATH {
template <typename T>
inline constexpr bool is_zero(T input);
template <typename T>
inline constexpr bool is_in_range(T input, T input_min, T input_max);
template <typename T>
inline constexpr float degree_to_radian(T input);
template <typename T>
inline constexpr float radian_to_degree(T input);
template <typename T>
inline constexpr T abs(T input);
template <typename T>
inline constexpr T limit(T input, T input_min, T input_max);
template <typename T>
constexpr T sin(T input);
template <typename T>
constexpr T cos(T input);
template <typename T>
constexpr T tan(T input);
template <typename T>
constexpr T arcsin(T input);
template <typename T>
constexpr T arccos(T input);
template <typename T>
constexpr T arctan(T input);
template <typename T>
constexpr T exp(T input);
template <typename T>
constexpr T sqart(T input);
template <typename T>
inline constexpr T max(T input1, T input2);
template <typename T>
inline constexpr T max(T input1, T input2, T input3);
template <typename T>
inline constexpr T min(T input1, T input2);
template <typename T>
inline constexpr T min(T input1, T input2, T input3);
template <typename T1, typename T2>
constexpr T1 power(T1 input, T2 num);
template <typename T>
constexpr T sum(T* input, int num);
template <typename T>
constexpr T sqasum(T* input, int num);
template <typename T>
constexpr T mean(T* input, int num);
template <typename T>
constexpr T wmean(T input1, T input2, T weight1);
template <typename T>
constexpr T sqamean(T* input, int num);
template <typename T1, typename T2>
void swap(T1* input1, T2* input2);
template <typename T>
constexpr T arctan2(T input1, T input2);
template <typename T>
constexpr T sat(T input1, T input2);
template <typename T>
constexpr float sign(T input2);
};  // namespace R_MATH

#endif