//#pragma GCC optimize("O2")

#include "R_Matrix.h"

namespace R_MATRIX
{
    template<typename T,int M,int N>
    inline r_matrix<T,M,N>::r_matrix(const T input[M][N])
    {}

    template<typename T,int M,int N>
    r_matrix<T,M,N>::~r_matrix()
    {}

    template<typename T,int M,int N>
    inline void r_matrix<T,M,N>::copy(r_matrix<T,M,N> input)
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
    r_matrix<T,M,N> r_matrix<T,M,N>::operator+(r_matrix<T,M,N> input)
    {}
    
    template<typename T,int M,int N>
    r_matrix<T,M,N> r_matrix<T,M,N>::operator-(r_matrix<T,M,N> input)
    {}

    template<typename T,int M,int N>
    void r_matrix<T,M,N>::operator+=(r_matrix<T,M,N> input)
    {}

    template<typename T,int M,int N>
    void r_matrix<T,M,N>::operator-=(r_matrix<T,M,N> input)
    {}
    
    template<typename T,int M,int N>
    template<int K> 
    r_matrix<T,M,K> r_matrix<T,M,N>::operator*(r_matrix<T,N,K> input)
    {}
    
    template<typename T,int M,int N>
    constexpr r_matrix<T,M,N> r_matrix<T,M,N>::num_prod(T input)
    {}
    
    template<typename T,int M,int N>
    constexpr void r_matrix<T,M,N>::scale(T input)
    {}
    
    template<typename T,int M,int N>
    r_matrix<T,N,M> r_matrix<T,M,N>::transpose()
    {}
    
    template<typename T,int M,int N>
    inline bool r_matrix<T,M,N>::is_zero()
    {}
    
    template<typename T>
    inline r_matrix3d<T>::r_matrix3d(const T input[3][3])
    {}

    template<typename T>
    r_matrix3d<T>::~r_matrix3d()
    {}

    template<typename T>
    inline void copy(r_matrix3d<T> input)
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

    template<typename T>
    r_matrix3d<T> r_matrix3d<T>::operator+(r_matrix3d<T> input)
    {}

    template<typename T>
    r_matrix3d<T> r_matrix3d<T>::operator-(r_matrix3d<T> input)
    {}

    template<typename T>
    void r_matrix3d<T>::operator+=(r_matrix3d<T> input)
    {}

    template<typename T>
    void r_matrix3d<T>::operator-=(r_matrix3d<T> input)
    {}

    template<typename T>
    template<int K> 
    r_matrix<T,3,K> r_matrix3d<T>::operator*(r_matrix<T,3,K> input)
    {}

    template<typename T>
    constexpr r_matrix3d<T> r_matrix3d<T>::num_prod(T input)
    {}

    template<typename T>
    constexpr void r_matrix3d<T>::scale(T input)
    {}

    template<typename T>
    r_matrix3d<T> r_matrix3d<T>::transpose()
    {}

    template<typename T>
    inline bool r_matrix3d<T>::is_zero()
    {}

};