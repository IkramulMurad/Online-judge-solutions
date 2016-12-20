#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        if(n==0 and m==0) break;

        int head[n],knight[m];
        for(int i=0; i<n; ++i) scanf("%d",head+i);
        for(int i=0; i<m; ++i) scanf("%d",knight+i);

        sort(head,head+n);
        sort(knight,knight+m);

        long long ans=0;
        int kount=0;
        for(int i=0,j=0; i<n and j<m; ++i,++j){
            while(j<m and knight[j]<head[i]){
                ++j;
            }
            if(j<m and knight[j]>=head[i]){
                ans+=knight[j];
                ++kount;
            }
        }
        if(kount==n) printf("%lld\n",ans);
        else printf("Loowater is doomed!\n");
    }
    return 0;
}
