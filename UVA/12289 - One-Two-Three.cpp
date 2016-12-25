#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        string s;
        cin>>s;

        if(s.size()==5) cout<<3<<endl;
        else if(s[0]=='o' or s[1]=='n') cout<<1<<endl;
        else cout<<2<<endl;
    }
    return 0;
}
