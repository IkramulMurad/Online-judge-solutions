#include <bits/stdc++.h>
 
using namespace std;
 
int n,c;
 
int f(int t){
    return c*t-n*t*t;
}
 
int solve(){
    if(n==0) return 0;
 
    int t1=c/(2*n);
 
    if(f(t1)>=f(t1+1)) return t1;
    return t1+1;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
 
        scanf("%d %d",&n,&c);
        printf("Case %d: %d\n",t,solve());
    }
    return 0;
}
