#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL dp[105];
const int m=1e9+7;

LL cal(int amount, int rng){
    if(amount==0) return 1;
    if(dp[amount]!=-1) return dp[amount];

    LL ans=0;
    for(int i=1; i<=min(amount,rng); ++i){
        ans=(ans+cal(amount-i,rng))%m;
    }
    return dp[amount]=ans;
}

int main()
{

    int n,k,d;
    cin>>n>>k>>d;

    memset(dp,-1,sizeof dp);
    LL ans=cal(n,k);

    memset(dp,-1,sizeof dp);
    ans-=cal(n,d-1);
    if(ans<0) ans+=m;
    
    cout<<ans<<endl;

    return 0;
}
