#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        long long ax,ay,bx,by;
        scanf("%lld %lld %lld %lld",&ax,&ay,&bx,&by);
        long long x,y;
        x=ax-bx;
        y=ay-by;
        if(x<0) x*=-1;
        if(y<0) y*=-1;
        long long ans=__gcd(x,y);
        printf("Case %d: %lld\n",t,ans+1);
    }
    return 0;
}
