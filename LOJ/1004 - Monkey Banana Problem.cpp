#include <bits/stdc++.h>
 
using namespace std;
 
int dp[205][105];
int a[205][105];
int n,m;
 
bool isValidJ(int i,int j){
    if(i<n&&j<=i) return 1;
    if(i>=n&&j<=m-i-1) return 1;
    return 0;
}
 
int cal(int i,int j){
    if(i<0||i>=m||j<0) return 0;
    if(isValidJ(i,j)==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i<n-1){
        dp[i][j]=max(a[i][j]+cal(i+1,j),a[i][j]+cal(i+1,j+1));
    }
    else{
        dp[i][j]=max(a[i][j]+cal(i+1,j-1),a[i][j]+cal(i+1,j));
    }
    //cout<<i<<","<<j<<":"<<dp[i][j]<<endl;
    return dp[i][j];
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
 
        scanf("%d",&n);
        m=2*n-1;
 
        for(int i=0;i<m;i++){
            int x;
            if(i<n)x=i+1;
            else x=m-i;
            for(int j=0;j<x;j++){
                scanf("%d",&a[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans=cal(0,0);
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
