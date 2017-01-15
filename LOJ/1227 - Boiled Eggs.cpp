#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,p,q;
        cin>>n>>p>>q;
        int a[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        int kount=0;
        for(int k=0;k<p;k++){
            if(q<a[k])break;
            if(n==kount)break;
            kount++;
            q-=a[k];
        }
        printf("Case %d: %d\n",i,kount);
    }
    return 0;
}
