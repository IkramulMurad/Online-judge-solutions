#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n;
        scanf("%d",&n);
        int sq=sqrt(n);
        long long ans=n;
        int prev=n,rn=n-1;
        for(int i=2;i<=sq;i++){
            int num=prev-n/i;
            ans+=n/i;
            ans+=num*(i-1);
            rn=rn-num-1;
            if(i==sq){
                if(rn!=0){
                    int x=n/i-n/(i+1);
                    ans+=(x*i);
                }
            }
            prev=n/i;
        }
        if(n==2){
            ans=3;
        }
        else if(n==3){
            ans=5;
        }
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
