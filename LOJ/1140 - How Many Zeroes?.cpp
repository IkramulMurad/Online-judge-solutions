#include <bits/stdc++.h>
 
using namespace std;
 
long long getAns(long long x){
    if(x<0) return 0;
    long long ans=x/10+1,y=x,den=10,rng,q,r;
    x/=10;
    while(x>=10){
        rng=den;
        den*=10;
        q=y/den;
        r=y%den;
        if(r<rng)
            ans+=((q-1)*rng)+(r+1);
        else
            ans+=(q*rng);
        x/=10;
    }
    return ans;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        long long m,n;
        scanf("%lld %lld",&m,&n);
        long long ans=getAns(n)-getAns(m-1);
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
