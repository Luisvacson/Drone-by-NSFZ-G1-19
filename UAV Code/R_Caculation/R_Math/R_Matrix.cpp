//#pragma GCC optimize("O2")

#include "R_Matrix.h"

template<typename T,int M,int N>
inline R_Matrix<T,M,N>::R_Matrix(const T input[M][N])
{}
template<typename T,int M,int N>
R_Matrix<T,M,N>::~R_Matrix()
{}
template<typename T,int M,int N>
inline void R_Matrix<T,M,N>::operator=(R_Matrix<T,M,N> input)
{
    int i,j;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            content[i][j]=input.content[i][j];
        }
    }
}

template<typename T,int M,int N>
R_Matrix<T,M,N> R_Matrix<T,M,N>::operator+(R_Matrix<T,M,N> input)
{}

template<typename T,int M,int N>
R_Matrix<T,M,N> R_Matrix<T,M,N>::operator-(R_Matrix<T,M,N> input)
{}
template<typename T,int M,int N>
void R_Matrix<T,M,N>::operator+=(R_Matrix<T,M,N> input)
{}
template<typename T,int M,int N>
void R_Matrix<T,M,N>::operator-=(R_Matrix<T,M,N> input)
{}

template<typename T,int M,int N>
template<int K> 
R_Matrix<T,M,K> R_Matrix<T,M,N>::operator*(R_Matrix<T,N,K> input)
{}

template<typename T,int M,int N>
constexpr R_Matrix<T,M,N> R_Matrix<T,M,N>::num_prod(T input)
{}

template<typename T,int M,int N>
constexpr void R_Matrix<T,M,N>::scale(T input)
{}

template<typename T,int M,int N>
R_Matrix<T,N,M> R_Matrix<T,M,N>::transpose()
{}

template<typename T,int M,int N>
inline bool R_Matrix<T,M,N>::is_zero()
{}

inline R_Matrix3d::R_Matrix3d(const R_Float input[3][3])
{}
R_Matrix3d::~R_Matrix3d()
{}
inline void R_Matrix3d::operator=(R_Matrix3d input)
{
    content[0][0]=input.content[0][0];
    content[0][1]=input.content[0][1];
    content[0][2]=input.content[0][2];
    content[1][0]=input.content[1][0];
    content[1][1]=input.content[1][1];
    content[1][2]=input.content[1][2];
    content[2][0]=input.content[2][0];
    content[2][1]=input.content[2][1];
    content[2][2]=input.content[2][2];
}
R_Matrix3d R_Matrix3d::operator+(R_Matrix3d input)
{}
R_Matrix3d R_Matrix3d::operator-(R_Matrix3d input)
{}
void R_Matrix3d::operator+=(R_Matrix3d input)
{}
void R_Matrix3d::operator-=(R_Matrix3d input)
{}
template<int K> 
R_Matrix<R_Float,3,K> R_Matrix3d::operator*(R_Matrix<R_Float,3,K> input)
{}
constexpr R_Matrix3d R_Matrix3d::num_prod(R_Float input)
{}
constexpr void R_Matrix3d::scale(R_Float input)
{}
R_Matrix3d R_Matrix3d::transpose()
{}
inline bool R_Matrix3d::is_zero()
{}