#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL mx=1e14+5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    int c[n];
    for(int i=0; i<n; ++i) cin>>c[i];

    string s[n],rs[n];
    for(int i=0; i<n; ++i){
        cin>>s[i];
        rs[i]=s[i];
        reverse(rs[i].begin(),rs[i].end());
    }

    LL dp[n][2];
    for(int i=0; i<n; ++i){
        dp[i][0]=dp[i][1]=mx;
    }

    dp[0][0]=0; dp[0][1]=c[0];
    for(int i=1; i<n; ++i){
        if(s[i-1]<=s[i]) dp[i][0]=min(dp[i][0], 0+dp[i-1][0]);
        if(rs[i-1]<=s[i]) dp[i][0]=min(dp[i][0], 0+dp[i-1][1]);

        if(s[i-1]<=rs[i]) dp[i][1]=min(dp[i][1], c[i]+dp[i-1][0]);
        if(rs[i-1]<=rs[i]) dp[i][1]=min(dp[i][1], c[i]+dp[i-1][1]);
    }

    LL ans=min(dp[n-1][0],dp[n-1][1]);
    if(ans>=mx) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}
