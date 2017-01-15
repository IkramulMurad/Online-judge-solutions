#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int a,b,ans;
        scanf("%d %d",&a,&b);
        if(a<=b){
            ans=b*4+19;
            printf("Case %d: %d\n",i,ans);
        }
        else{
            ans=a*4+(a-b)*4+19;
            printf("Case %d: %d\n",i,ans);
        }
    }
    return 0;
}
