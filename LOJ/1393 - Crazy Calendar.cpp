#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        int r,c;
        scanf("%d %d",&r,&c);
        int a[r][c];
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                scanf("%d",&a[i][j]);
            }
        }
        a[r-1][c-1]=0;
        long long ans=0;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                int d=(r-i-1)+(c-j-1);
                for(int k=0;k<d;++k){
                    ans^=a[i][j];
                }
            }
        }
        if(ans) printf("Case %d: win\n",t);
        else printf("Case %d: lose\n",t);
    }
    return 0;
}
