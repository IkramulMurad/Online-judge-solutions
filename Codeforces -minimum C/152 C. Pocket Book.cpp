#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL mod=1e9+7;

int main()
{
    int n,m;
    cin>>n>>m;

    string s[n];
    for(int i=0; i<n; ++i){
        cin>>s[i];
    }

    LL ans=1;
    for(int i=0; i<m; ++i){
        set<char> st;
        for(int j=0; j<n; ++j){
            st.insert(s[j][i]);
        }
        int d=st.size();
        ans=(ans*d)%mod;
    }

    cout<<ans;

    return 0;
}
