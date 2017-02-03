#include <bits/stdc++.h>

using namespace std;

const int inf=1e9;
int n, a[105];
int dp[105][100005];

int cal(int i, int amount){
    if(amount<0) return inf;
    if(amount==0) return 0;
    if(i>=n) return inf;
    if(dp[i][amount]!=-1) return dp[i][amount];

    return dp[i][amount]=min(1+cal(i,amount-a[i]),cal(i+1,amount));
}

void solve(){
    int amount;
    cin>>n>>amount;

    for(int i=0; i<n; ++i) cin>>a[i];

    memset(dp,-1,sizeof dp);

    int ans=cal(0,amount);
    if(ans>=inf) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
