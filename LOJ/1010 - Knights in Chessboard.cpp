#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t,ans,sum;
    cin>>t;
    for(int i=1;i<=t;i++){
        int m,n;
        scanf("%d %d",&m,&n);
        if(n==1||m==1) printf("Case %d: %d\n",i,n*m);
        else if(n==2||m==2){
            ans=(n*m);
            sum=(ans/8)*4;
            if(ans%8==2) sum+=2;
            else if(ans%8>2) sum+=4;
            printf("Case %d: %d\n",i,sum);
        }
        else{
            if((n*m)%2)ans=((n*m)/2)+1;
            else ans=((n*m)/2);
            printf("Case %d: %d\n",i,ans);
        }
    }
    return 0;
}
