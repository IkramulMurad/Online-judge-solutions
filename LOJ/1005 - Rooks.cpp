#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ULL;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        int n,k;
        scanf("%d %d",&n,&k);
        if(k>n){
            printf("Case %d: 0\n",t);
        }
        else{
            ULL ans=1;
            ULL a[k];
            for(ULL i=0;i<k;++i){
                a[i]=i+1;
            }
            for(ULL i=n;i>(n-k);--i){
                ULL x=i*i;
                for(int j=0;j<k;++j){
                    if(a[j]==1) continue;
                    ULL g=__gcd(ans,a[j]);
                    ans/=g;
                    a[j]/=g;
                    if(a[j]==1) continue;
                    ULL d=__gcd(x,a[j]);
                    x/=d;
                    a[j]/=d;
                }
                ans*=x;
            }
            printf("Case %d: %llu\n",t,ans);
        }
    }
    return 0;
}
