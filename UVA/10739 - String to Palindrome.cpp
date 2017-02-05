#include <bits/stdc++.h>

using namespace std;

int min(int a, int b, int c){
     return min(min(a,b),c);
}

/*
int editDistance(){
    string s,t;
    cin>>s;

    t=s;
    reverse(t.begin(), t.end());

    int n=s.size(), m=n;
    int dp[n+1][m+1];

    for(int i=0; i<=n; ++i) dp[i][0]=i;
    for(int i=0; i<=m; ++i) dp[0][i]=i;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
            }
        }
    }

    return dp[n][m]/2;

}
*/

int editDistance(){
    string s;
    cin>>s;

    int n=s.size();
    int dp[n][n];
    memset(dp,0,sizeof dp);

    for(int i=n-1; i>=0; --i){
        for(int j=i+1; j<n; ++j){
            if(s[i]==s[j]){
                dp[i][j]=dp[i+1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i][j-1], //insert
                               dp[i+1][j], //delete
                               dp[i+1][j-1]); //replace
            }
        }
    }

    //i start from bottom
    //j start from left
    //so answer is dp[top][right]
    return dp[0][n-1];
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; ++t){
        int ans=editDistance();
        printf("Case %d: %d\n",t,ans);
    }

    return 0;
}
