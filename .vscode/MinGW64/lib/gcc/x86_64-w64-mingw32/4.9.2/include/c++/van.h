#include<bits/stdc++.h>
#define _inline __inline__ __attribute__((always_inline))
using namespace std;
struct ios{
    inline char gc(){
        static const int IN_LEN=1<<18|1;
        static char buf[IN_LEN],*s,*t;
        return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
    }
    template <typename _Tp> _inline ios & operator >> (_Tp &x){
        static char ch,sgn; ch=gc(),sgn=0;
        for(;!isdigit(ch);ch=gc()){if(ch==-1)return *this;sgn|=ch=='-';}
        for(x=0;isdigit(ch);ch=gc())x=x*10+(ch^'0');
        sgn&&(x=-x); return *this;
    }
}inc;
template<typename T> inline void print(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
inline int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
