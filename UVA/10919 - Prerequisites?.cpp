#include <bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int sub,cat;
    while(cin>>sub>>cat){
        int a[sub];
        for(int i=0; i<sub; ++i) cin>>a[i];
        sort(a,a+sub);

        bool no=false;
        for(int i=0; i<cat; ++i){
            int x,y,kount=0;
            cin>>x>>y;
            for(int j=0; j<x; ++j){
                int z;
                cin>>z;
                if(binary_search(a,a+sub,z)) ++kount;
            }
            if(kount<y) no=true;
        }
        if(no) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}
