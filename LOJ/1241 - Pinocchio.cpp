#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,ans=0;
        scanf("%d",&n);
        int a[n];
        for(int j=0;j<n;j++){
           scanf("%d",&a[j]);
        }
        int d;
        d=a[0]-2;
        ans+=d/5;
        if(d%5)
           ans++;
        for(int j=0;j<n-1;j++){
            d=a[j+1]-a[j];
            ans+=d/5;
            if(d%5)
              ans++;
        }
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
