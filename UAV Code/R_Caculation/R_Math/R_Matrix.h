#pragma once

#ifndef R_MATRIX_H
#define R_MATRIX_H

#include "R_Math.h"

template<typename T,int M,int N>class R_Matrix
{
    public:
        T content[M][N];
        inline R_Matrix(const T input[M][N]);
        ~R_Matrix();
        inline void operator=(R_Matrix<T,M,N> input);
        R_Matrix<T,M,N> operator+(R_Matrix<T,M,N> input);
        R_Matrix<T,M,N> operator-(R_Matrix<T,M,N> input);
        void operator+=(R_Matrix<T,M,N> input);
        void operator-=(R_Matrix<T,M,N> input);
        template<int K> R_Matrix<T,M,K> operator*(R_Matrix<T,N,K> input);
        constexpr R_Matrix<T,M,N> num_prod(T input);
        constexpr void scale(T input);
        R_Matrix<T,N,M> transpose();
        inline bool is_zero();
};

class R_Matrix3d
{
    public:
        R_Float content[3][3];
        inline R_Matrix3d(const R_Float input[3][3]);
        ~R_Matrix3d();
        inline void operator=(R_Matrix3d input);
        R_Matrix3d operator+(R_Matrix3d input);
        R_Matrix3d operator-(R_Matrix3d input);
        void operator+=(R_Matrix3d input);
        void operator-=(R_Matrix3d input);
        template<int K> R_Matrix<R_Float,3,K> operator*(R_Matrix<R_Float,3,K> input);
        constexpr R_Matrix3d num_prod(R_Float input);
        constexpr void scale(R_Float input);
        R_Matrix3d transpose();
        inline bool is_zero();
};

#endif