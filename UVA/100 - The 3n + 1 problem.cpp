#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int cal(LL n){
    int kount=1;
    while(n!=1){
        if(n&1) n=3*n+1;
        else n/=2;
        ++kount;
    }
    return kount;
}

int main()
{
    int a,b;
    while(~scanf("%d %d",&a,&b)){
        int j,k;
        if(a>b){
            j=b;
            k=a;
        }
        else{
            j=a;
            k=b;
        }
        int ans=0;
        for(int i=j; i<=k; ++i){
            ans=max(ans,cal(i));
        }
        printf("%d %d %d\n",a,b,ans);
    }
    return 0;
}
