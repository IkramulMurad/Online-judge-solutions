#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long LL;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int n;
        scanf("%d",&n);
        int sq=sqrt(n);
        LL ans=0;
        for(int i=2; i<=sq; ++i){
            LL isum,rsum,in,rng=n/i;
            isum=(rng*(rng+1))/2;
            rsum=((i-1)*i)/2;
            in=(rng-i)*i;
            ans+=isum-rsum+in;
        }
        printf("Case %d: %llu\n",t,ans);
    }
    return 0;
}
