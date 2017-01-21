#include <bits/stdc++.h>

using namespace std;

int main()
{

//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int z,i,m,l,t=0;
    while(cin>>z>>i>>m>>l and z and i and m and l){
        bool isTaken[m]={0};
        int ans=0;
        l=((z*l)+i)%m;
        while(!isTaken[l]){
            isTaken[l]=1;
            l=((z*l)+i)%m;
            ++ans;
        }
        cout<<"Case "<<++t<<": ";
        cout<<ans<<endl;
    }

    return 0;
}
