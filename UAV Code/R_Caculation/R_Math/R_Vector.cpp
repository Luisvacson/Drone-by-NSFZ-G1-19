//#pragma GCC optimize("O2")

#include "R_Vector.h"

template<typename T,int N>
inline R_Vector<T,N>::R_Vector(const T input[N])
{
    R_Memory::memcpy(content,input,sizeof(T)*N);
}
template<typename T,int N>
R_Vector<T,N>::~R_Vector()
{
    delete[] content;
}
template<typename T,int N>
inline void R_Vector<T,N>::operator=(R_Vector<T,N> input)
{
    R_Memory::memcpy(content,input.content,sizeof(T)*N);
}
template<typename T,int N>
R_Vector<T,N> R_Vector<T,N>::operator+(R_Vector<T,N> input)
{}
template<typename T,int N>
R_Vector<T,N> R_Vector<T,N>::operator-(R_Vector<T,N> input)
{}
template<typename T,int N>
R_Vector<T,N> R_Vector<T,N>::operator-(void)
{}
template<typename T,int N>
void R_Vector<T,N>::operator+=(R_Vector<T,N> input)
{}
template<typename T,int N>
void R_Vector<T,N>::operator-=(R_Vector<T,N> input)
{}

template<typename T,int N>
constexpr R_Vector<T,N> R_Vector<T,N>::num_prod(T input)
{}

template<typename T,int N>
constexpr void R_Vector<T,N>::scale(T input)
{}

template<typename T,int N>
float R_Vector<T,N>::dot_prod(R_Vector<T,N> input)
{}

template<typename T,int N>
R_Vector<T,N> R_Vector<T,N>::cross_prod(R_Vector<T,N> input)
{}

template<typename T,int N>
inline T R_Vector<T,N>::norm()
{}

template<typename T,int N>
void R_Vector<T,N>::normalize()
{}

template<typename T,int N>
float R_Vector<T,N>::exp_error(R_Vector<T,N> input)
{}

template<typename T,int N>
inline bool R_Vector<T,N>::is_zero()
{}

template<typename T,int N>
constexpr R_Vector<T,N>::R_Vector<T,N> satgd(T input)
{}

template<typename T,int N>
R_Vector<T,N>::R_Vector<T,N> dcv()
{}

inline R_Vector3d::R_Vector3d(const R_Float input[3])
{}

R_Vector3d::~R_Vector3d()
{}

inline void R_Vector3d::operator=(R_Vector3d input)
{
    content0=input.content0;
    content1=input.content1;
    content2=input.content2;
}
R_Vector3d R_Vector3d::operator+(R_Vector3d input)
{}
R_Vector3d R_Vector3d::operator-(R_Vector3d input)
{}

R_Vector3d R_Vector3d::operator-(void)
{}

void R_Vector3d::operator+=(R_Vector3d input)
{}

void R_Vector3d::operator-=(R_Vector3d input)
{}

constexpr R_Vector3d R_Vector3d::Num_prod(R_Float input)
{}
constexpr void R_Vector3d::scale(R_Float input)
{}
float R_Vector3d::dot_prod(R_Vector3d input)
{}
R_Vector3d R_Vector3d::cross_prod(R_Vector3d input)
{}

inline R_Float R_Vector3d::norm()
{}

void R_Vector3d::normalize()
{}
float R_Vector3d::exp_error(R_Vector3d input)
{}
inline bool R_Vector3d::is_zero()
{}
constexpr R_Vector3d R_Vector3d::satgd(R_Float input)
{}
R_Vector3d R_Vector3d::dcv()
{}