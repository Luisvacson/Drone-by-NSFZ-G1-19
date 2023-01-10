#include "R_Math.h"

namespace R_MATH {
template <typename T>
inline bool is_in_range(R_Number<T> input, R_Number<T> input_min, R_Number<T> input_max) {
    return input >= input_min && input <= input_max;
};

template <typename T>
inline R_Number<float> degree_to_radian(R_Number<T> input) {
    return (float)(input) * (float)(DEGREE_TO_RADIAN);
}
template <typename T>
inline R_Number<float> radian_to_degree(R_Number<T> input) {
    return (float)(input) * (float)(RADIAN_TO_DEGREE);
}

template <typename T>
inline R_Number<T> abs(R_Number<T> input) {
    return input > 0 ? input : ((T)(0)-input);
}

template <typename T>
inline R_Number<T> limit(R_Number<T> input, R_Number<T> input_min, R_Number<T> input_max) {
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
    do {
        Fact = mul(Fact, (float)mul(add(Iterator, 1), add(Iterator, 2)));
        Index = mul(Index, (float)mul(input, input));
        Negation = -Negation;
        Res = div(mul(Index, (float)Negation), Fact);
        TaylorExpansion = add(TaylorExpansion, Res);
        Iterator = add(Iterator, 2);
    } while (abs(Res) > 1e-7);
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
R_Number<T> exp(R_Number<T> input) {}

template <typename T>
R_Number<T> sqart(R_Number<T> input) {}

template <typename T>
inline R_Number<T> max(R_Number<T> input1, R_Number<T> input2) {}

template <typename T>
inline R_Number<T> max(R_Number<T> input1, R_Number<T> input2, R_Number<T> input3) {
    return max(max(input1, input2), input3);
}

template <typename T>
inline R_Number<T> min(R_Number<T> input1, R_Number<T> input2) {}

template <typename T>
inline R_Number<T> min(R_Number<T> input1, R_Number<T> input2, R_Number<T> input3) {
    return min(min(input1, input2), input3);
}

template <typename T1, typename T2>
R_Number<T1> power(R_Number<T1> input, R_Number<T2> num) {}

template <typename T>
R_Number<T> sum(R_Number<T>* input, int num) {}

template <typename T>
R_Number<T> sqasum(R_Number<T>* input, int num) {}

template <typename T>
R_Number<T> mean(R_Number<T>* input, int num) {}

template <typename T>
R_Number<T> wmean(R_Number<T> input1, R_Number<T> input2, R_Number<T> weight1) {}

template <typename T>
R_Number<T> sqamean(R_Number<T>* input, int num) {}

template <typename T>
void swap(R_Number<T>* input1, R_Number<T>* input2) {}

template <typename T>
R_Number<T> arctan2(R_Number<T> input1, R_Number<T> input2) {}

template <typename T>
R_Number<T> sat(R_Number<T> input1, R_Number<T> input2) {}

template <typename T>
R_Number<float> sign(R_Number<T> input2) {}
};  // namespace R_MATH