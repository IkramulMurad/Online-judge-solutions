#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int mx=1000+5;
int p[mx],w[mx],dp[mx][34];
int n;

LL cal(int i, int amount){
    if(amount==0) return 0;
    if(i>=n) return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];

    LL p1,p2;
    p1=p2=0;

    if(amount>=w[i]) p1=p[i]+cal(i+1,amount-w[i]);
    p2=cal(i+1,amount);

    return dp[i][amount]=max(p1,p2);
}

void solve(){
    cin>>n;
    for(int i=0; i<n; ++i) cin>>p[i]>>w[i];
    memset(dp,-1,sizeof dp);

    int k;
    cin>>k;

    LL ans=0;

    for(int i=0; i<k; ++i){
        int amount;
        cin>>amount;

        ans+=cal(0,amount);
    }

    cout<<ans<<endl;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--){
        solve();
    }

    return 0;
}
