#include <bits/stdc++.h>

using namespace std;

void generate(int a[], int n, int m){
    a[0]=1;
    a[1]=2;
    a[2]=3;
    for(int i=3; i<n; ++i){
        a[i]=(a[i-1]+a[i-2]+a[i-3])%m+1;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);

        int nums[n];
        generate(nums,n,m);

        int freq[n+5];
        memset(freq, 0, sizeof freq);

        int ans=n+5, kount=0;
        int hi, lo;
        hi=lo=0;

        while(hi<n){
            int x=nums[hi++];
            ++freq[x];

            if(x<=k and freq[x]==1) ++kount;
            while(lo<hi and kount==k){
                ans=min(ans, hi-lo);
                int y=nums[lo++];
                --freq[y];

                if(y<=k and freq[y]==0) --kount;
            }
        }

        if(ans<=n){
            printf("Case %d: %d\n",t,ans);
        }
        else printf("Case %d: sequence nai\n",t);
    }
    return 0;
}
