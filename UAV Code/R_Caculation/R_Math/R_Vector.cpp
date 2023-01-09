//#pragma GCC optimize("O2")

#include "R_Vector.h"

namespace R_VECTOR
{
    template<typename T,int N>
    inline r_vector<T,N>::r_vector(const T input[N])
    {
        R_Memory::memcpy(content,input,sizeof(T)*N);
    }

    template<typename T,int N>
    r_vector<T,N>::~r_vector()
    {
        delete[] content;
    }

    template<typename T,int N>
    inline void r_vector<T,N>::copy(r_vector<T,N> input)
    {
        R_Memory::memcpy(content,input.content,sizeof(T)*N);
    }

    template<typename T,int N>
    r_vector<T,N> r_vector<T,N>::operator+(r_vector<T,N> input)
    {}

    template<typename T,int N>
    r_vector<T,N> r_vector<T,N>::operator-(r_vector<T,N> input)
    {}

    template<typename T,int N>
    r_vector<T,N> r_vector<T,N>::operator-(void)
    {}

    template<typename T,int N>
    void r_vector<T,N>::operator+=(r_vector<T,N> input)
    {}

    template<typename T,int N>
    void r_vector<T,N>::operator-=(r_vector<T,N> input)
    {}
    
    template<typename T,int N>
    constexpr r_vector<T,N> r_vector<T,N>::num_prod(T input)
    {}
    
    template<typename T,int N>
    constexpr void r_vector<T,N>::scale(T input)
    {}
    
    template<typename T,int N>
    float r_vector<T,N>::dot_prod(r_vector<T,N> input)
    {}
    
    template<typename T,int N>
    r_vector<T,N> r_vector<T,N>::cross_prod(r_vector<T,N> input)
    {}
    
    template<typename T,int N>
    inline T r_vector<T,N>::norm()
    {}
    
    template<typename T,int N>
    void r_vector<T,N>::normalize()
    {}
    
    template<typename T,int N>
    float r_vector<T,N>::exp_error(r_vector<T,N> input)
    {}
    
    template<typename T,int N>
    inline bool r_vector<T,N>::is_zero()
    {}
    
    template<typename T,int N>
    constexpr r_vector<T,N>::r_vector<T,N> satgd(T input)
    {}
    
    template<typename T,int N>
    r_vector<T,N>::r_vector<T,N> dcv()
    {}

    template<typename T>
    inline r_vector3d<T>::r_vector3d(const T input[3])
    {}

    template<typename T>
    r_vector3d<T>::~r_vector3d()
    {}

    template<typename T>
    inline void copy(r_vector3d<T> input)
    {
        content[0]=input.content[0];
        content[1]=input.content[1];
        content[2]=input.content[2];
    }

    template<typename T>
    r_vector3d<T> r_vector3d<T>::operator+(r_vector3d<T> input)
    {}

    template<typename T>
    r_vector3d<T> r_vector3d<T>::operator-(r_vector3d<T> input)
    {}

    template<typename T>
    r_vector3d<T> r_vector3d<T>::operator-(void)
    {}

    template<typename T>
    void r_vector3d<T>::operator+=(r_vector3d<T> input)
    {}

    template<typename T>
    void r_vector3d<T>::operator-=(r_vector3d<T> input)
    {}

    template<typename T>
    constexpr r_vector3d<T> r_vector3d<T>::Num_prod(T input)
    {}

    template<typename T>
    constexpr void r_vector3d<T>::scale(T input)
    {}

    template<typename T>
    float r_vector3d<T>::dot_prod(r_vector3d<T> input)
    {}

    template<typename T>
    r_vector3d<T> r_vector3d<T>::cross_prod(r_vector3d<T> input)
    {}

    template<typename T>
    inline T r_vector3d<T>::norm()
    {}

    template<typename T>
    void r_vector3d<T>::normalize()
    {}

    template<typename T>
    float r_vector3d<T>::exp_error(r_vector3d<T> input)
    {}

    template<typename T>
    inline bool r_vector3d<T>::is_zero()
    {}

    template<typename T>
    constexpr r_vector3d<T> r_vector3d<T>::satgd(T input)
    {}

    template<typename T>
    r_vector3d<T> r_vector3d<T>::dcv()
    {}
};