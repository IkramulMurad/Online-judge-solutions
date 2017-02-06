#include <bits/stdc++.h>

using namespace std;

const int m=100000007;

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int t=1; t<=tc; ++t){
        int n,k;
        scanf("%d %d",&n,&k);

        int a[n+1];
        for(int i=1; i<=n; ++i) scanf("%d",a+i);

        int dp[n+1][k+1];
        for(int i=0; i<=n; ++i) dp[i][0]=1;
        for(int i=0; i<=k; ++i) dp[0][i]=0;

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=k; ++j){
                if(j>=a[i]){
                    dp[i][j]=(dp[i-1][j]+dp[i][j-a[i]])%m;
                }
                else dp[i][j]=dp[i-1][j];
            }
        }

        printf("Case %d: %d\n",t,dp[n][k]);
    }

    return 0;
}
