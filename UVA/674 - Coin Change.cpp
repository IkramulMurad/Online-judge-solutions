#include <bits/stdc++.h>

using namespace std;

int a[]={1,5,10,25,50};
int dp[10][8000];

int cal(int i, int amount){
    if(amount<0) return 0;
    if(amount==0) return 1;
    if(i>=5) return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];

    return dp[i][amount]=cal(i,amount-a[i]) + cal(i+1,amount);
}

int main()
{
    memset(dp,-1,sizeof dp);

    int n;
    while(cin>>n){
        cout<<cal(0,n)<<endl;
    }

    return 0;
}
