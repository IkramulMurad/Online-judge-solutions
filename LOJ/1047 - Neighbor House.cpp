#include <bits/stdc++.h>
 
using namespace std;
 
int a[21][3];
int n;
const int mx=1e8;
int dp[21][3];
 
int mini(int a,int b,int c){
    int x=min(a,b);
    x=min(x,c);
    return x;
}
 
int cal(int i,int j){
    if(i<0||j<0||i>=n||j>=3) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int x;
    if(j==0){
        dp[i][j]=a[i][j]+min(cal(i+1,j+1),cal(i+1,j+2));
        x=dp[i][j];
    }
    else if(j==1){
        dp[i][j]=a[i][j]+min(cal(i+1,j-1),cal(i+1,j+1));
        x=dp[i][j];
    }
    else if(j==2){
        dp[i][j]=a[i][j]+min(cal(i+1,j-1),cal(i+1,j-2));
        x=dp[i][j];
    }
    return dp[i][j];
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                scanf("%d",&a[i][j]);
            }
        }
        int x=mini(cal(0,0),cal(0,1),cal(0,2));
        printf("Case %d: %d\n",t,x);
    }
    return 0;
}
