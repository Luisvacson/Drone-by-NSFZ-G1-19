#include "R_Math.h"

namespace R_MATH {
template <typename T>
inline constexpr bool is_zero(T input) {
    return input == 0;
}

template <>
inline constexpr bool is_zero<float>(float input) {
    return abs(input) < (static_cast<float>(FLOAT_EPSILON));
}

template <typename T>
inline constexpr bool is_in_range(T input, T input_min, T input_max) {
    return input >= input_min && input <= input_max;
};

template <typename T>
inline constexpr float degree_to_radian(T input) {
    return mult(static_cast<float>(input),
                static_cast<float>(DEGREE_TO_RADIAN));
}
template <typename T>
inline constexpr float radian_to_degree(T input) {
    return mult(static_cast<float>(input),
                static_cast<float>(RADIAN_TO_DEGREE));
}

template <typename T>
inline constexpr T abs(T input) {
    return input > 0 ? input : sub(static_cast<float>(0), input);
}

template <typename T>
inline constexpr T limit(T input, T input_min, T input_max) {
    return input < input_min ? input_min
                             : (input > input_max ? input_max : input);
}

template <typename T>
constexpr T sin(T input) {
    int Iterator = 1, Negation = 1;
    float Res;
    float Index = input;
    float Fact = static_cast<float>(1.0);
    float TaylorExpansion = input;
    do {
        Fact = mul(Fact, mul(add(Iterator, 1), add(Iterator, 2)));
        Index = mul(Index, mul(input, input));
        Negation = -Negation;
        Res = div(mul(Index, Negation), Fact);
        TaylorExpansion = add(TaylorExpansion, Res);
        Iterator = add(Iterator, 2);
    } while (abs(Res) > 1e-7);
    return TaylorExpansion;
}

template <typename T>
constexpr T cos(T input) {
    int Iterator = 0, Negation = 1;
    float Res;
    float Index = static_cast<float>(1.0);
    float Fact = static_cast<float>(1.0);
    float TaylorExpansion = static_cast<float>(1.0);
    do {
        Fact = mul(Fact, mul(add(Iterator, 1), add(Iterator, 2)));
        Index = mul(Index, mul(input, input));
        Negation = -Negation;
        Res = div(mul(Index, Negation), Fact);
        TaylorExpansion = add(TaylorExpansion, Res);
        Iterator = add(Iterator, 2);
    } while (abs(Res) > 1e-7);
    return TaylorExpansion;
}

template <typename T>
constexpr T tan(T input) {
    return div(sin(input), cos(input));
}

template <typename T>
constexpr T arcsin(T input) {}

template <typename T>
constexpr T arccos(T input) {}

template <typename T>
constexpr T arctan(T input) {}

template <typename T>
constexpr T exp(T input) {}

template <typename T>
constexpr T sqart(T input) {}

template <typename T>
inline constexpr T max(T input1, T input2) {}

template <typename T>
inline constexpr T max(T input1, T input2, T input3) {
    return max(max(input1, input2), input3);
}

template <typename T>
inline constexpr T min(T input1, T input2) {}

template <typename T>
inline constexpr T min(T input1, T input2, T input3) {
    return min(min(input1, input2), input3);
}

template <typename T1, typename T2>
constexpr T1 power(T1 input, T2 num) {}

template <typename T>
constexpr T sum(T* input, int num) {}

template <typename T>
constexpr T sqasum(T* input, int num) {}

template <typename T>
constexpr T mean(T* input, int num) {}

template <typename T>
constexpr T wmean(T input1, T input2, T weight1) {}

template <typename T>
constexpr T sqamean(T* input, int num) {}

template <typename T1, typename T2>
void swap(T1* input1, T2* input2) {}

template <typename T>
constexpr T arctan2(T input1, T input2) {}

template <typename T>
constexpr T sat(T input1, T input2) {}

template <typename T>
constexpr float sign(T input2) {}
};  // namespace R_MATH