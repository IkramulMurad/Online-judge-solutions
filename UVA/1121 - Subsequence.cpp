#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL mx=1e5+5;

LL a[mx], sum[mx];

LL cumSum(LL high, LL low){
    return sum[high]-sum[low-1];
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    LL n,m;

    while(cin>>n>>m){

        for(LL i=1; i<=n; ++i){
            cin>>a[i];
            cerr<<a[i]<<" ";
        }
        cerr<<endl;

        sum[0]=a[0]=0;
        for(LL i=1; i<=n; ++i){
            sum[i]=sum[i-1]+a[i];
            cerr<<sum[i]<<" ";
        }
        cerr<<endl;

        LL high, low;
        high=low=1;

        LL mn=mx;
        while(high<=n and low<=n){
            if(cumSum(high,low)>=m){
                mn=min(mn,high-low+1);
                ++low;
            }
            else{
                ++high;
            }
        }

        if(mn==mx) mn=0;
        cout<<mn<<endl;

    }

    return 0;
}
