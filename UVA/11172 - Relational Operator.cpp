#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int a,b;
        cin>>a>>b;

        if(a<b)cout<<"<"<<endl;
        else if(a>b) cout<<">"<<endl;
        else if(a==b) cout<<"="<<endl;
    }
    return 0;
}
