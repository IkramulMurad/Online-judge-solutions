#include <bits/stdc++.h>

using namespace std;

long long nCr(int n,int r){
    long long x=1;
    int rng;

    if(r>=n-r) rng=r;
    else rng=n-r;

    int a[n-rng];
    for(int i=0;i<(n-rng);i++) a[i]=rng+i+1;
    for(int i=1;i<=n-rng;i++) x*=i;

    for(int i=0;x!=1;i++){
        long long y=a[i];
        int g=__gcd(y,x);
        a[i]/=g;
        x/=g;
    }

    long long ans=1;
    for(int i=0;i<(n-rng);i++){
        ans*=a[i];
    }
    return ans;
}

int main()
{
    int n,m,t;
    unsigned long long ans=0;
    cin>>n>>m>>t;
    
    for(int i=4; i<=min(n,t-1); i++){
        int j=t-i;
        if(j<=m){
            ans+=nCr(n,i)*nCr(m,j);
        }
    }
    cout<<ans;
    return 0;
}
