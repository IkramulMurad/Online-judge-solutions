//recursive dp

#include <bits/stdc++.h>

using namespace std;

int dp[1004][1004];
string s;

int lps(int i, int j){
    if(i==j) return 1;
    if(j<i) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==s[j]){
        dp[i][j]=2+lps(i+1,j-1);
    }
    else{
        dp[i][j]=max(lps(i,j-1),lps(i+1,j));
    }
    return dp[i][j];
}

int main()
{
    int tc;
    cin>>tc;
    getchar();

    for(int t=1; t<=tc; ++t){
        getline(cin,s);
        memset(dp,-1,sizeof dp);
        cout<<lps(0,s.size()-1)<<endl;
    }

    return 0;
}

//iterative dp
#include <bits/stdc++.h>

using namespace std;

int dp[1004][1004];
string s;

void solve(){
    int n=s.size();
    if(n==0){
        cout<<0<<endl;
        return;
    }

    for(int i=0; i<n; ++i) dp[i][i]=1;

    for(int l=2; l<=n; ++l){
        for(int i=0; i<=n-l; ++i){
            int j=l-1+i;
            if(s[i]==s[j] and i+1==j){
                dp[i][j]=2;
            }
            else if(s[i]==s[j]){
                dp[i][j]=2+dp[i+1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }

    cout<<dp[0][n-1]<<endl;
}

int main()
{
    int tc;
    cin>>tc;
    getchar();

    for(int t=1; t<=tc; ++t){
        getline(cin,s);
        memset(dp,0,sizeof dp);
        solve();
    }

    return 0;
}
