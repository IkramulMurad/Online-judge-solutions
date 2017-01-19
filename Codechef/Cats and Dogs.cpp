#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int tc;
    cin>>tc;
    while(tc--){
        int c,d,l;
        cin>>c>>d>>l;
 
        if(l%4){
            cout<<"no"<<endl;
            continue;
        }
 
        LL mx=LL(d)*4+LL(c)*4;
 
        LL mn=LL(d)*4;
        LL cat=LL(c-2*d)*4;
        mn=max(mn,mn+cat);
 
        if(l>mx or l<mn) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}
