#include <bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int h,w;
    while(cin>>h>>w and h){
        int ans,prv,cur;
        for(int i=0; i<w; ++i){
            cin>>cur;
            if(!i) ans=h-cur;
            else{
                if(prv>cur) ans+=prv-cur;
            }
            prv=cur;
        }
        cout<<ans<<endl;
    }
    return 0;
}
