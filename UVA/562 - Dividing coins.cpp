#include <bits/stdc++.h>

using namespace std;

int dp[123][50005];
int a[123];
int n,total;

int cal(int i, int amount){
    if(i>=n) return abs(amount-(total-amount));
    if(dp[i][amount]!=-1) return dp[i][amount];

    //considering me as a first man
    //amount denotes my amount
    //total-amount denotes second man amount
    int ans1=cal(i+1,amount);       //not taking
    int ans2=cal(i+1,amount+a[i]);  //taking

    return dp[i][amount]=min(ans1,ans2);
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--){
        cin>>n;
        total=0;

        for(int i=0; i<n; ++i) cin>>a[i], total+=a[i];

        memset(dp,-1,sizeof dp);

        printf("%d\n",cal(0,0));
    }

    return 0;
}
