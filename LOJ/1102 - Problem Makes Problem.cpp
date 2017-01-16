#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
const int m=1000000007;
const int mx=2e6+5;
LL f[mx];
 
void cal(){
    f[0]=1;
    for(LL i=1;i<mx;++i){
        f[i]=(f[i-1]*i)%m;
    }
}
 
LL mod_pow(LL b,LL p){
    LL res=1;
    while(p){
        if(p&1){
            res=(res*b)%m;
        }
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}
 
LL nCr(LL n,LL r){
    LL low=(mod_pow(f[r],m-2)*mod_pow(f[n-r],m-2))%m;
    LL ans=(f[n]*low)%m;
    return ans;
}
 
int main()
{
    cal();
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        LL ans,n,k;
        scanf("%lld %lld",&n,&k);
        ans=nCr(n+k-1,k-1);
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
