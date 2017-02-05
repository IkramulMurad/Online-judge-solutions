#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int a[]={1,5,10,25,50};
LL dp[5][30001];

LL cal(int i, int amount){
    if(amount==0) return 1;
    if(amount<0) return 0;
    if(i>=5) return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];

    return dp[i][amount]=cal(i,amount-a[i])+cal(i+1,amount);
}

int main()
{
    memset(dp,-1,sizeof dp);
    int amount;
    while(cin>>amount){
        LL ans=cal(0,amount);
        if(ans==1){
            printf("There is only 1 way");
        }
        else{
            printf("There are %lld ways",ans);
        }
        printf(" to produce %d cents change.\n",amount);

    }
    return 0;
}
