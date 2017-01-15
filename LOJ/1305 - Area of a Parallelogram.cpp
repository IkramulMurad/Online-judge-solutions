#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int ax,ay,bx,by,cx,cy,dx,dy,d;
        scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);
        dx=cx+(ax-bx);
        dy=cy+(ay-by);
        d=abs(ax*(by-cy)+bx*(cy-ay)+cx*(ay-by));
        printf("Case %d: %d %d %d\n",i,dx,dy,d);
    }
    return 0;
}
