#include <bits/stdc++.h>

using namespace std;

int n;
int a[1234];

void solve(){
    int lis[n];
    int rlis[n];

    fill(lis,lis+n,1);
    fill(rlis,rlis+n,1);

    //LIS
    for(int i=1; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(a[j]<a[i]){
                lis[i]=max(lis[i],1+lis[j]);
            }
        }
    }

    //Reverse LIS
    for(int i=n-2; i>=0; --i){
        for(int j=n-1; j>i; --j){
            if(a[j]<a[i]){
                rlis[i]=max(rlis[i],1+rlis[j]);
            }
        }
    }

    //LBS is the max lis[i]+rlis[i]-1;
    int lbs=0;
    for(int i=0; i<n; ++i){
        lbs=max(lbs,lis[i]+rlis[i]-1);
    }

    cout<<lbs<<endl;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--){
        cin>>n;
        for(int i=0; i<n; ++i) cin>>a[i];
        solve();
    }

    return 0;
}
