#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n;
        scanf("%d",&n);
        int ans=0,b[n],w[n];
        for(int i=0;i<n;i++){
            scanf("%d",&w[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
        }
        for(int i=0;i<n;i++){
            ans^=b[i]-w[i]-1;
        }
        if(ans) printf("Case %d: white wins\n",t);
        else printf("Case %d: black wins\n",t);
    }
    return 0;
}
