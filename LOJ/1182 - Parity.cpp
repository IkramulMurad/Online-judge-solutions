#include <bits/stdc++.h>
 
using namespace std;
int getType(int n){
    int kount=0;
    while(n>0){
        if(n%2==1)kount++;
        n/=2;
    }
    if(kount%2==0) return 0;
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,flag;
        scanf("%d",&n);
        flag=getType(n);
        if(flag==0) printf("Case %d: even\n",i);
        else printf("Case %d: odd\n",i);
    }
    return 0;
}
