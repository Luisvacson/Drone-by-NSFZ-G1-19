#pragma once

#ifndef R_MATRIX_H
#define R_MATRIX_H

#include "R_Math.h"

namespace R_MATRIX
{
    template<typename T,int M,int N>class r_matrix
    {
        public:
            T content[M][N];

            inline r_matrix(const T input[M][N]);
            ~r_matrix();
            inline void copy(r_matrix<T,M,N> input);
            r_matrix<T,M,N> operator+(r_matrix<T,M,N> input);
            r_matrix<T,M,N> operator-(r_matrix<T,M,N> input);
            void operator+=(r_matrix<T,M,N> input);
            void operator-=(r_matrix<T,M,N> input);
            template<int K> r_matrix<T,M,K> operator*(r_matrix<T,N,K> input);
            constexpr r_matrix<T,M,N> num_prod(T input);
            constexpr void scale(T input);
            r_matrix<T,N,M> transpose();
            inline bool is_zero();
    };

    template<typename T>class r_matrix3d:
    {
        public:
            T content[3][3];

            inline r_matrix3d(const T input[3][3]);
            ~r_matrix3d();
            inline void copy(r_matrix3d<T> input);
            r_matrix3d<T> operator+(r_matrix3d<T> input);
            r_matrix3d<T> operator-(r_matrix3d<T> input);
            void operator+=(r_matrix3d<T> input);
            void operator-=(r_matrix3d<T> input);
            template<int K> r_matrix<T,3,K> operator*(r_matrix<T,3,K> input);
            constexpr r_matrix3d<T> num_prod(T input);
            constexpr void scale(T input);
            r_matrix3d<T> transpose();
            inline bool is_zero();
    };
};

#endif