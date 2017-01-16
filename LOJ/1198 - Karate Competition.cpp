#include <bits/stdc++.h>
 
using namespace std;
 
int n,a[55],b[55],dp[55][55];
 
int cal(int i,int j){
    if(i>=n or j>=n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]>b[j]) return dp[i][j]=2+cal(i+1,j+1);
    if(a[i]==b[j]) return dp[i][j]=max(1+cal(i+1,j+1),cal(i+1,j));
    return dp[i][j]=cal(i+1,j);
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        scanf("%d",&n);
 
        for(int i=0; i<n; ++i) scanf("%d",a+i);
        for(int i=0; i<n; ++i) scanf("%d",b+i);
 
        sort(a,a+n);
        sort(b,b+n);
 
        memset(dp,-1,sizeof(dp));
        int ans=cal(0,0);
 
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
