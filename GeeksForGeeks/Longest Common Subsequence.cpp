#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;

    string s,t;
    cin>>s>>t;

    int table[n+1][m+1];
    memset(table,0,sizeof table);

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s[i-1]==t[j-1]){ //string 0 based, table 1 based
                table[i][j]=1+table[i-1][j-1];
            }
            else table[i][j]=max(table[i][j-1],table[i-1][j]);
        }
    }

    cout<<table[n][m]<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
