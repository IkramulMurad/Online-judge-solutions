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

    //dp[n][m] doesn't always contain palindrome
    //first half of dp[n][m] is the palindromic sequence
    //print twice first half of dp[n][m]
    string ans=dp[n][m];
    int idx;

    for(idx=0; idx<ans.size()/2; ++idx) cout<<ans[idx];
    if(ans.size()&1) cout<<ans[idx];
    for(idx=ans.size()/2-1; idx>=0; --idx) cout<<ans[idx];
    cout<<endl;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    while(cin>>s){
        solve();
    }

    return 0;
}
