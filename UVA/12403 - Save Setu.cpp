#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q,ans=0;
    cin>>q;
    while(q--){
        string s;
        cin>>s;

        if(s=="donate"){
            int x;
            cin>>x;
            ans+=x;
        }

        else cout<<ans<<endl;
    }
    return 0;
}
