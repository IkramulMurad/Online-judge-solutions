#include <bits/stdc++.h>

using namespace std;

string dp[1004][1004];
string s;

void solve(){
    string t=s;
    reverse(t.begin(),t.end());

    int n=s.size(), m=n;

    for(int i=0; i<=n; ++i) dp[i][0]="";
    for(int i=0; i<=m; ++i) dp[0][i]="";

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+s[i-1];
            }
            else{
                if(dp[i-1][j].size()>dp[i][j-1].size()){
                    dp[i][j]=dp[i-1][j];
                }
                else if(dp[i-1][j].size()<dp[i][j-1].size()){
                    dp[i][j]=dp[i][j-1];
                }
                else if(dp[i-1][j].size()==dp[i][j-1].size()){
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
    }
    cout<<dp[n][m]<<endl;
}

int main()
{
    while(cin>>s){
        solve();
    }

    return 0;
}
