#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,b,h,w;
    while(cin>>n>>b>>h>>w){
        int mn=b+1;
        //bool stayHome=true;

        for(int i=0; i<h; ++i){
            int p;
            cin>>p;
            for(int j=0; j<w; ++j){
                int bed;
                cin>>bed;
                if(bed>=n){
                    mn=min(mn,n*p);
                }
            }
        }

        if(mn<=b) cout<<mn<<endl;
        else cout<<"stay home"<<endl;
    }
    return 0;
}
