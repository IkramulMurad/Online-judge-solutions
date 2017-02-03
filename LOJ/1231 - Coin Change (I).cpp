#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int m=100000007;
int n;
int a[56],c[56];
int dp[56][1234];

LL cal(int i, int amount){
    if(amount==0) return 1;
    if(amount<0) return 0;
    if(i>=n) return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];

    LL ret1,ret2;
    ret1=ret2=0;

    for(int j=1; j<=c[i]; ++j){
        ret1=(ret1+cal(i+1,amount-j*a[i]))%m;
    }

    ret2=cal(i+1,amount)%m;

    return dp[i][amount]=(ret1 + ret2)%m;
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int t=1; t<=tc; ++t){
        int amount;
        scanf("%d %d",&n,&amount);

        for(int i=0; i<n; ++i) scanf("%d",a+i);
        for(int i=0; i<n; ++i) scanf("%d",c+i);
        memset(dp,-1,sizeof dp);

        printf("Case %d: %lld\n",t,cal(0,amount));
    }

    return 0;
}
