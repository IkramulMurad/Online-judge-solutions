#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int mx=1e4+5;
LL dp[mx];
int amount;
int n=21;
int a[21];

void gen(){
    for(int i=1; i<=21; ++i){
        a[i-1]=i*i*i;
    }
}

void solve(){
    dp[0]=1;

    for(int i=0; i<n; ++i){
        for(int j=a[i]; j<=mx; ++j){
            dp[j]+=dp[j-a[i]];
        }
    }
}

int main()
{
    gen();
    memset(dp,0,sizeof dp);
    solve();

    while(cin>>amount){
        cout<<dp[amount]<<endl;
    }

    return 0;
}
