#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int t=1; t<=tc; ++t){
        int n,m;
        scanf("%d %d",&n,&m);

        int a[n+1],c[n+1];
        for(int i=1; i<=n; ++i) scanf("%d",a+i);
        for(int i=1; i<=n; ++i) scanf("%d",c+i);

        int dp[m+1];
        memset(dp,0,sizeof dp);
        dp[0]=1;

        LL rng=0;
        for(int i=1; i<=n; ++i){
            rng+=a[i]*c[i];
            LL hi=min((LL)m,rng);

            int taken[hi+1];
            memset(taken,0,sizeof taken);
            for(int j=a[i]; j<=hi; ++j){
                //not taken yet and
                //it is possible to make and
                //coins are available
                if(!dp[j] and dp[j-a[i]] and taken[j-a[i]]<c[i]){
                    dp[j]=j;
                    taken[j]=1+taken[j-a[i]];
                }
            }
        }

        /*
        for(int i=0; i<=m; ++i) cerr<<dp[i]<<" ";
        cerr<<endl;
        */

        int kount=0;
        for(int i=1; i<=m; ++i){
            if(dp[i]) ++kount;
        }

        printf("Case %d: %d\n",t,kount);
    }

    return 0;
}
