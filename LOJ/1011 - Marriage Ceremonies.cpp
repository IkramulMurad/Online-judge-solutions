#include <bits/stdc++.h>
 
using namespace std;
 
int n;
int a[20][20];
int dp[20][(1<<16)+2];
 
int on(int n, int pos){
    return n|(1<<pos);
}
 
int of(int n, int pos){
    return n&~(1<<pos);
}
 
bool check(int n, int pos){
    return bool(n&(1<<pos));
}
 
int cal(int mask, int pos){
    if(pos==n) return 0;
    if(dp[pos][mask]!=-1) return dp[pos][mask];
 
    int mx=0;
    for(int j=0; j<n; ++j){
        if(!check(mask,j)){
            mx=max(mx,a[pos][j]+cal(on(mask,j),pos+1));
            dp[pos][mask]=mx;
        }
    }
    return dp[pos][mask];
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        scanf("%d",&n);
 
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                scanf("%d",&a[i][j]);
            }
        }
 
        memset(dp,-1,sizeof dp);
 
        printf("Case %d: %d\n",t,cal(0,0));
    }
    return 0;
}
