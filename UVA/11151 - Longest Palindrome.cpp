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
