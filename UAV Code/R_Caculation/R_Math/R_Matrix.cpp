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
    inline void r_matrix<T,M,N>::operator=(r_matrix<T,M,N> input)
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
    
    inline r_matrix3d::r_matrix3d(const R_Float input[3][3])
    {}

    r_matrix3d::~r_matrix3d()
    {}

    inline void r_matrix3d::operator=(r_matrix3d input)
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

    r_matrix3d r_matrix3d::operator+(r_matrix3d input)
    {}

    r_matrix3d r_matrix3d::operator-(r_matrix3d input)
    {}

    void r_matrix3d::operator+=(r_matrix3d input)
    {}

    void r_matrix3d::operator-=(r_matrix3d input)
    {}

    template<int K> 
    r_matrix<R_Float,3,K> r_matrix3d::operator*(r_matrix<R_Float,3,K> input)
    {}

    constexpr r_matrix3d r_matrix3d::num_prod(R_Float input)
    {}

    constexpr void r_matrix3d::scale(R_Float input)
    {}

    r_matrix3d r_matrix3d::transpose()
    {}

    inline bool r_matrix3d::is_zero()
    {}

};