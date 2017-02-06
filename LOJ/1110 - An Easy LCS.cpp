#include <bits/stdc++.h>

using namespace std;

string dp[123][123];

void clr(){
    for(int i=0; i<123; ++i){
        for(int j=0; j<123; ++j){
            dp[i][j]="";
        }
    }
}

void solve(int kase){
    string s,t;
    cin>>s>>t;

    clr();

    int n=s.size(), m=t.size();

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+s[i-1];
            }
            else{
                if(dp[i][j-1].size()>dp[i-1][j].size()){
                    dp[i][j]=dp[i][j-1];
                }
                else if(dp[i-1][j].size()>dp[i][j-1].size()){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
    }
    printf("Case %d: ",kase);
    if(dp[n][m].size()) cout<<dp[n][m]<<endl;
    else cout<<":("<<endl;
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int t=1; t<=tc; ++t){
        solve(t);
    }

    return 0;
}
