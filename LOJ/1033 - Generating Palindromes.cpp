#include <bits/stdc++.h>

using namespace std;

int solve(){
    string s,t;
    cin>>s;

    t=s;
    reverse(t.begin(),t.end());

    int n=s.size(), m=n;
    int dp[n+1][m+1];

    for(int i=0; i<=n; ++i) dp[i][0]=0;
    for(int i=0; i<=m; ++i) dp[0][i]=0;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }

    return n-dp[n][m];
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int t=1; t<=tc; ++t){
        int ans=solve();
        printf("Case %d: %d\n",t,ans);
    }

    return 0;
}
