#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int ax,ay,bx,by;
        scanf("%d %d %d %d",&ax,&ay,&bx,&by);
        int x,y;
        x=abs(bx-ax)%2;
        y=abs(by-ay)%2;
        if(x!=y) printf("Case %d: impossible\n",i);
        else{
            int m,n;
            m=abs(bx-ax);
            n=abs(by-ay);
            if(m==n) printf("Case %d: 1\n",i);
            else printf("Case %d: 2\n",i);
        }
    }
    return 0;
}
