#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int f[100005];
int a[100005];
LL dp[100005];

LL cal(int i, int n){
    if(i>n) return 0;
    if(dp[i]!=-1) return dp[i];

    return dp[i]=max((LL)i*f[i]+cal(i+2,n),cal(i+1,n));
}

int main()
{
    int n;
    cin>>n;
    memset(f,0,sizeof f);
    memset(dp,-1,sizeof dp);

    int mn=1e5+5, mx=0;
    for(int i=0; i<n; ++i){
        cin>>a[i];
        f[a[i]]++;

        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }

    LL ans=cal(mn,mx);
    cout<<ans;

    return 0;
}
