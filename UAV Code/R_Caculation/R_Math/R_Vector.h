#pragma once

#ifndef R_VECTOR_H
#define R_VECTOR_H

#include "R_Math.h"
#include "R_Memory.h"

template<typename T,int N>class R_Vector
{
    public:
        T content[N];
        inline R_Vector(const T input[N]);
        ~R_Vector();
        inline void operator=(R_Vector<T,N> input);
        R_Vector<T,N> operator+(R_Vector<T,N> input);
        R_Vector<T,N> operator-(R_Vector<T,N> input);
        R_Vector<T,N> operator-(void);
        void operator+=(R_Vector<T,N> input);
        void operator-=(R_Vector<T,N> input);
        constexpr R_Vector<T,N> num_prod(T input);
        constexpr void scale(T input);
        float dot_prod(R_Vector<T,N> input);
        R_Vector<T,N> cross_prod(R_Vector<T,N> input);
        inline T norm();
        void normalize();
        float exp_error(R_Vector<T,N> input);
        inline bool is_zero();
        constexpr R_Vector<T,N> satgd(T input);
        R_Vector<T,N> dcv();
};

class R_Vector3d
{
    public:
        R_Float content0;
        R_Float content1;
        R_Float content2;
        inline R_Vector3d(const R_Float input[3]);
        ~R_Vector3d();
        inline void operator=(R_Vector3d input);
        R_Vector3d operator+(R_Vector3d input);
        R_Vector3d operator-(R_Vector3d input);
        R_Vector3d operator-(void);
        void operator+=(R_Vector3d input);
        void operator-=(R_Vector3d input);
        constexpr R_Vector3d Num_prod(R_Float input);
        constexpr void scale(R_Float input);
        float dot_prod(R_Vector3d input);
        R_Vector3d cross_prod(R_Vector3d input);
        inline R_Float norm();
        void normalize();
        float exp_error(R_Vector3d input);
        inline bool is_zero();
        constexpr R_Vector3d satgd(R_Float input);
        R_Vector3d dcv();
};

#endif