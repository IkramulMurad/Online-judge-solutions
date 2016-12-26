#include <bits/stdc++.h>

using namespace std;

int main()
{
    int b,d;
    while(cin>>b>>d){
        if(!b and !d) break;

        int x[b];
        for(int i=0; i<b; ++i){
            cin>>x[i];
        }

        int u,v,w, flag=0;
        for(int i=0; i<d; ++i){
            cin>>u>>v>>w;
            --u; --v;
            x[u]-=w;
            x[v]+=w;
        }

        for(int i=0; i<b; ++i){
            if(x[i]<0){
                flag=1;
                break;
            }
        }

        if(flag) cout<<'N'<<endl;
        else cout<<'S'<<endl;
    }
    return 0;
}
