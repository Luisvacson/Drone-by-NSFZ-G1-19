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
    inline void r_vector<T,N>::operator=(r_vector<T,N> input)
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

    
    inline r_vector3d::r_vector3d(const R_Float input[3])
    {}

    
    r_vector3d::~r_vector3d()
    {}

    
    inline void r_vector3d::operator=(r_vector3d input)
    {
        content[0]=input.content[0];
        content[1]=input.content[1];
        content[2]=input.content[2];
    }

    r_vector3d r_vector3d::operator+(r_vector3d input)
    {}

    r_vector3d r_vector3d::operator-(r_vector3d input)
    {}
    
    r_vector3d r_vector3d::operator-(void)
    {}
    
    void r_vector3d::operator+=(r_vector3d input)
    {}
    
    void r_vector3d::operator-=(r_vector3d input)
    {}
    
    constexpr r_vector3d r_vector3d::Num_prod(R_Float input)
    {}

    constexpr void r_vector3d::scale(R_Float input)
    {}

    float r_vector3d::dot_prod(r_vector3d input)
    {}

    r_vector3d r_vector3d::cross_prod(r_vector3d input)
    {}
    
    inline R_Float r_vector3d::norm()
    {}
    
    void r_vector3d::normalize()
    {}

    float r_vector3d::exp_error(r_vector3d input)
    {}

    inline bool r_vector3d::is_zero()
    {}

    constexpr r_vector3d r_vector3d::satgd(R_Float input)
    {}

    r_vector3d r_vector3d::dcv()
    {}
};