#include "R_Math.h"

#include <stdio.h>
namespace R_MATH {
template <typename T>
inline bool is_zero(T input) {
    return input == 0;
}

template <>
inline bool is_zero<float>(float input) {
    return abs(input) < (static_cast<float>(FLOAT_EPSILON));
}

template <typename T>
inline bool is_in_range(T input, T input_min, T input_max) {
    return input >= input_min && input <= input_max;
};

template <typename T>
inline float degree_to_radian(T input) {
    return mul(static_cast<float>(input), static_cast<float>(DEGREE_TO_RADIAN));
}
template <typename T>
inline float radian_to_degree(T input) {
    return mul(static_cast<float>(input), static_cast<float>(RADIAN_TO_DEGREE));
}

template <typename T>
inline T abs(T input) {
    return input > 0 ? input : sub(static_cast<float>(0), input);
}

template <typename T>
inline T limit(T input, T input_min, T input_max) {
    return input < input_min ? input_min
                             : (input > input_max ? input_max : input);
}

template <typename T>
T sin(T input) {
    int Iterator = 1, Negation = 1;
    float Res;
    float Index = input;
    float Fact = static_cast<float>(1.0);
    float TaylorExpansion = input;
    int cnt = 0;
    do {
        Fact = mul(Fact, (float)mul(add(Iterator, 1), add(Iterator, 2)));
        Index = mul(Index, (float)mul(input, input));
        Negation = -Negation;
        Res = div(mul(Index, (float)Negation), Fact);
        TaylorExpansion = add(TaylorExpansion, Res);
        Iterator = add(Iterator, 2);
        ++cnt;
    } while (abs(Res) > 1e-7);
    printf("%d\n", cnt);
    return TaylorExpansion;
}

template <typename T>
T cos(T input) {
    int Iterator = 0, Negation = 1;
    float Res;
    float Index = static_cast<float>(1.0);
    float Fact = static_cast<float>(1.0);
    float TaylorExpansion = static_cast<float>(1.0);
    do {
        Fact = mul(Fact, (float)mul(add(Iterator, 1), add(Iterator, 2)));
        Index = mul(Index, mul(input, input));
        Negation = -Negation;
        Res = div(mul(Index, (float)Negation), Fact);
        TaylorExpansion = add(TaylorExpansion, Res);
        Iterator = add(Iterator, 2);
    } while (abs(Res) > 1e-7);
    return TaylorExpansion;
}

template <typename T>
T tan(T input) {
    return div(sin(input), cos(input));
}

template <typename T>
T arcsin(T input) {}

template <typename T>
T arccos(T input) {}

template <typename T>
T arctan(T input) {
    const long angle[] = {11520, 6801, 3593, 1824, 916, 458, 229, 115,
                          57,    29,   14,   7,    4,   2,   1};

    long Iterator = 1;
    long x = (long)(add(add(add(add(add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 3,
                                    add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 1)
                                    << 3,
                                add(add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 3,
                                    add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 1)
                                    << 1)
                                << 3,
                            add(add(add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 3,
                                    add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 1)
                                    << 3,
                                add(add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 3,
                                    add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 1)
                                    << 1)
                                << 1)
                            << 3,
                        add(add(add(add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 3,
                                    add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 1)
                                    << 3,
                                add(add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 3,
                                    add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 1)
                                    << 1)
                                << 3,
                            add(add(add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 3,
                                    add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 1)
                                    << 3,
                                add(add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 3,
                                    add(add(input << 3, input << 1) << 3,
                                        add(input << 3, input << 1) << 1)
                                        << 1)
                                    << 1)
                                << 1)
                            << 1));
    long y = 1e6;
}

template <typename T>
T exp(T input) {}

template <typename T>
T sqart(T input) {}

template <typename T>
inline T max(T input1, T input2) {}

template <typename T>
inline T max(T input1, T input2, T input3) {
    return max(max(input1, input2), input3);
}

template <typename T>
inline T min(T input1, T input2) {}

template <typename T>
inline T min(T input1, T input2, T input3) {
    return min(min(input1, input2), input3);
}

template <typename T1, typename T2>
T1 power(T1 input, T2 num) {}

template <typename T>
T sum(T* input, int num) {}

template <typename T>
T sqasum(T* input, int num) {}

template <typename T>
T mean(T* input, int num) {}

template <typename T>
T wmean(T input1, T input2, T weight1) {}

template <typename T>
T sqamean(T* input, int num) {}

template <typename T1, typename T2>
void swap(T1* input1, T2* input2) {}

template <typename T>
T arctan2(T input1, T input2) {}

template <typename T>
T sat(T input1, T input2) {}

template <typename T>
float sign(T input2) {}
};  // namespace R_MATH
using namespace R_MATH;

signed main() { printf("%.6lf\n", sin(PI / 3)); }