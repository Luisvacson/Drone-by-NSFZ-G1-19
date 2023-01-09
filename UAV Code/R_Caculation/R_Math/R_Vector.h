#pragma once

#ifndef R_VECTOR_H
#define R_VECTOR_H

#include "R_Math.h"
#include "R_Memory.h"

namespace R_VECTOR
{
    template<typename T,int N>class r_vector
    {
        public:
            T content[N];

            inline r_vector(const T input[N]);
            ~r_vector();
            inline void copy(r_vector<T,N> input);
            r_vector<T,N> operator+(r_vector<T,N> input);
            r_vector<T,N> operator-(r_vector<T,N> input);
            r_vector<T,N> operator-(void);
            void operator+=(r_vector<T,N> input);
            void operator-=(r_vector<T,N> input);
            constexpr r_vector<T,N> num_prod(T input);
            constexpr void scale(T input);
            float dot_prod(r_vector<T,N> input);
            r_vector<T,N> cross_prod(r_vector<T,N> input);
            inline T norm();
            void normalize();
            float exp_error(r_vector<T,N> input);
            inline bool is_zero();
            constexpr r_vector<T,N> satgd(T input);
            r_vector<T,N> dcv();
    };

    template<typename T>class r_vector3d
    {
        public:
            T content[3];

            inline r_vector3d(const T input[3]);
            ~r_vector3d();
            inline void copy(r_vector3d<T> input);
            r_vector3d<T> operator+(r_vector3d<T> input);
            r_vector3d<T> operator-(r_vector3d<T> input);
            r_vector3d<T> operator-(void);
            void operator+=(r_vector3d<T> input);
            void operator-=(r_vector3d<T> input);
            constexpr r_vector3d<T> Num_prod(T input);
            constexpr void scale(T input);
            float dot_prod(r_vector3d<T> input);
            r_vector3d<T> cross_prod(r_vector3d<T> input);
            inline T norm();
            void normalize();
            float exp_error(r_vector3d<T> input);
            inline bool is_zero();
            constexpr r_vector3d<T> satgd(T input);
            r_vector3d<T> dcv();
    };
};

#endif