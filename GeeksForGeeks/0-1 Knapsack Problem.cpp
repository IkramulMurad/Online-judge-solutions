#include <bits/stdc++.h>

using namespace std;
const int mx=105;
int wt[mx],v[mx],dp[mx][mx];
int n,w;

int cal(int i, int taken){
    if(i>=n) return 0;
    if(dp[i][taken]!=-1) return dp[i][taken];

    int p1,p2;
    p1=p2=0;
    if(taken+wt[i]<=w) p1=v[i]+cal(i+1,taken+wt[i]);
    p2=cal(i+1,taken);

    return dp[i][taken]=max(p1,p2);
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        memset(dp,-1,sizeof dp);

        cin>>n>>w;
        for(int i=0; i<n; ++i) cin>>v[i];
        for(int i=0; i<n; ++i) cin>>wt[i];

        cout<<cal(0,0)<<endl;
    }

    return 0;
}
