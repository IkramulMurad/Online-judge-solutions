#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int k;
        scanf("%d",&k);
        int n=k+k;
        int ans=0,prev,flag=0;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            if(!flag){
               prev=x;
               flag=1;
            }
            else{
                ans+=x-prev-1;
                flag=0;
            }
        }
        if(ans&1) printf("Case %d: Alice\n",t);
        else printf("Case %d: Bob\n",t);
    }
    return 0;
}
