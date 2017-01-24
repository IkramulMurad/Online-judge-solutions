#include <iostream>

using namespace std;

typedef long long LL;

int main()
{
    LL n;
    cin>>n;
    LL a[n+1]={0};
    for(LL i=1; i<=n; ++i) cin>>a[i], a[i]+=a[i-1];

    LL last=a[n];
    LL ans=0;

    if(n<3){
        cout<<0<<endl;
        return 0;
    }

    if(last%3==0){
        LL first=last/3;
        LL second=first+first;

        LL kount=0;
        for(int i=1; i<n; ++i){
            if(a[i]==first) ++kount;
            if(a[i]==second) ans+=kount;
        }
    }
    if(last==0){
        LL kount=0;
        for(LL i=1; i<=n; ++i){
            if(!a[i]) ++kount;
        }
        LL x=kount-2;
        ans=(x*(x+1))/2;
    }
    cout<<ans;

    return 0;
}
