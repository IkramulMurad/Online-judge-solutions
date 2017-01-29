#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    int a[n];
    memset(a,0,sizeof a);

    for(int i=0; i<q; ++i){
        int t,k,d;
        cin>>t>>k>>d;
        int x=t+d;
        int j=0;
        int ans=0;
        for(int z=0; z<n; ++z){
            if(a[z]<=t) ++j;
        }
        if(j<k){
            cout<<"-1"<<endl;
            continue;
        }
        j=0;
        for(int z=0; z<n and j<k; ++z){
            if(a[z]<=t){
                a[z]=x;
                ans+=z+1;
                ++j;
            }

        }
        cout<<ans<<endl;

    }
    return 0;
}
