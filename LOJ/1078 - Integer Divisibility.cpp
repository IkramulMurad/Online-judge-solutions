#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n,d;
        scanf("%d %d",&n,&d);
        int y=d%n,x=y,i=1;
        while(x!=0){
            x=((10*x)%n+y)%n;
            i++;
        }
        printf("Case %d: %d\n",t,i);
    }
    return 0;
}
