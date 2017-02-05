#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL dp[12][30005];
int a[]={5,10,20,50,100,200,500,1000,2000,5000,10000};

LL cal(int i, int amount){
    if(amount<0) return 0;
    if(amount==0) return 1;
    if(i>10) return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];

    return dp[i][amount]=cal(i,amount-a[i])+cal(i+1,amount);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    memset(dp,-1,sizeof dp);

    double amount;
    while(cin>>amount and amount){
        printf("%6.2f",amount);
        int x=(amount+0.001)*100; //not adding 0.001 leads WA
        printf("%17lld\n",cal(0,x));
    }

    return 0;
}
