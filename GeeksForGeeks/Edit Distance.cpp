#include <bits/stdc++.h>

using namespace std;

int min(int a, int b, int c){
    return min(min(a,b),c);
}

void solve(){
    int n,m;
    cin>>n>>m;

    string s,t;
    cin>>s>>t;

    int dp[n+1][m+1];
    for(int i=0; i<=n; ++i) dp[i][0]=i;
    for(int i=0; i<=m; ++i) dp[0][i]=i;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else dp[i][j]=1+min(dp[i-1][j-1],
                                dp[i-1][j],
                                dp[i][j-1]);
        }
    }

    cout<<dp[n][m]<<endl;
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
