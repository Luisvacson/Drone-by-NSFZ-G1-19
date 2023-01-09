#pragma once

namespace R_Memory
{
    inline void memcpy(void* target,void* source,int size);
    inline void memcpy(void* target,const void* source,int size);
    template<typename T>inline void memset(T* target,T value,int n);
    template<typename T>inline void memset(T* target,const T value,int n);
};