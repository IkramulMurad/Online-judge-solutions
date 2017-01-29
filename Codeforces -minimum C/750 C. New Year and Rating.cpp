#include <bits/stdc++.h>

using namespace std;

const int inf=2e9;

int main()
{
    int n;
    cin>>n;

    int hi,lo,s;
    hi=inf;
    lo=-inf;
    s=0;

    for(int i=0; i<n; ++i){
        int r,d;
        cin>>r>>d;
        if(d==1){
            lo=max(lo,1900-s);
        }
        else{
            hi=min(hi,1899-s);
        }
        s+=r;
    }

    if(hi<lo) cout<<"Impossible";
    else if(hi==inf) cout<<"Infinity";
    else cout<<hi+s;

    return 0;
}
