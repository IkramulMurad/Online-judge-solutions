#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL mid(LL r, LL g, LL b){
    LL a[]={r,g,b};
    sort(a,a+3);
    return a[1];
}

int main()
{
    int r,g,b;
    cin>>r>>g>>b;

    LL mn=min(min(r,g),b);
    LL md=mid(r,g,b);

    LL s=LL(r)+g+b;
    LL mx=s/3;

    LL ans=min(mx,mn+md);
    cout<<ans;

    return 0;
}
