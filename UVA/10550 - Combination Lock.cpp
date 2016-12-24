#include <iostream>

using namespace std;

int main()
{
    int p,a,b,c;
    while(cin>>p>>a>>b>>c){
        if(p==0 and a==0 and b==0 and c==0) break;
        int ans=1080;
        int s,d;

        s=p; d=a;
        if(s<d) s+=40;
        ans+=(s-d)*9;

        s=a; d=b;
        if(d<s) d+=40;
        ans+=(d-s)*9;

        s=b; d=c;
        if(s<d) s+=40;
        ans+=(s-d)*9;

        cout<<ans<<endl;
    }
    return 0;
}
