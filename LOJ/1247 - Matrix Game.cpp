#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int m,n;
        scanf("%d %d",&m,&n);
        int a[m][n];
        long long sum[m];
        memset(sum,0,sizeof(sum));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
                sum[i]+=a[i][j];
            }
        }
        int ans=sum[0];
        for(int i=1;i<m;i++){
            ans^=sum[i];
        }
        printf("Case %d: ",t);
        if(ans)printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
