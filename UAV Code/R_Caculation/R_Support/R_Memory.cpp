#include "R_Memory.hpp"

namespace R_Memory
{
    inline void memcpy(void* target,void* source,int size)
    {
        unsigned char* ttarget=(unsigned char *)target;
        unsigned char* tsource=(unsigned char *)source;
        for(int i=0;i<size;i++)
        {
            ttarget[i]=tsource[i];
        }
    }

    inline void memcpy(void* target,const void* source,int size)
    {
        unsigned char* ttarget=(unsigned char *)target;
        unsigned char* tsource=(unsigned char *)source;
        for(int i=0;i<size;i++)
        {
            ttarget[i]=tsource[i];
        }
    }

    template<typename T>
    inline void memset(T* target,T value,int n)
    {
        for(int i=0;i<n;i++)
        {
            target[i]=value;
        }
    }

    template<typename T>
    inline void memset(T* target,const T value,int n)
    {
        for(int i=0;i<n;i++)
        {
            target[i]=value;
        }
    }
};

