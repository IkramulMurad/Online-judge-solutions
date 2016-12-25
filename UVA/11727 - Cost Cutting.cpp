#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc,c=1;
    cin>>tc;
    while(tc--){
        int x,y,z;
        cin>>x>>y>>z;

        int mx,mn;
        mx=max(x,max(y,z));
        mn=min(x,min(y,z));

        printf("Case %d: ",c++);

        if(x!=mx and x!=mn) cout<<x<<endl;
        else if(y!=mx and y!=mn) cout<<y<<endl;
        else cout<<z<<endl;
    }
    return 0;
}
