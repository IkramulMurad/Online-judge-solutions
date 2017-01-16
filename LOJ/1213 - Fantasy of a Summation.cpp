#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
template<class T>
void fastIn(T& x){
    x=0;
    register int c;
    bool neg=false;
 
    c=getchar();
    if(c=='-'){
        neg=true;
        c=getchar();
    }
    while(c>47 and c<58){
        x=(x<<1)+(x<<3)+c-48;
        c=getchar();
    }
    if(neg) x*=-1;
}
 
LL bigmod(LL b, LL p, LL mod){
    LL res=1;
    while(p>0){
        if(p&1){
            res=(res*b)%mod;
            --p;
            continue;
        }
        b=(b*b)%mod;
        p>>=1;
    }
    return res;
}
 
int main()
{
    int tc;
    fastIn(tc);
    for(int t=1; t<=tc; ++t){
        LL n,k,mod;
        fastIn(n); fastIn(k); fastIn(mod);
        LL a[n];
        fastIn(a[0]);
        for(int i=1; i<n; ++i){
            fastIn(a[i]);
            a[i]+=a[i-1];
        }
 
        LL qsum=a[n-1]%mod;
        LL ans=(qsum*k)%mod;
 
        ans=(ans*bigmod(n,k-1,mod))%mod;
 
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
