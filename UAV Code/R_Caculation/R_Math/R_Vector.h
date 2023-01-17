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
            inline void operator=(r_vector<T,N> input);
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

    class r_vector3d
    {
        public:
            R_Float content[3];

            inline r_vector3d(const R_Float input[3]);
            ~r_vector3d();
            inline void operator=(r_vector3d input);
            r_vector3d operator+(r_vector3d input);
            r_vector3d operator-(r_vector3d input);
            r_vector3d operator-(void);
            void operator+=(r_vector3d input);
            void operator-=(r_vector3d input);
            constexpr r_vector3d Num_prod(R_Float input);
            constexpr void scale(R_Float input);
            float dot_prod(r_vector3d input);
            r_vector3d cross_prod(r_vector3d input);
            inline R_Float norm();
            void normalize();
            float exp_error(r_vector3d input);
            inline bool is_zero();
            constexpr r_vector3d satgd(R_Float input);
            r_vector3d dcv();
    };
};

#endif