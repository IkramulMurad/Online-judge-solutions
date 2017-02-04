#include <bits/stdc++.h>

using namespace std;

int n,m;
int s[123],t[123];
int idx=0;

void scan(){
    for(int i=0; i<n; ++i) cin>>s[i];
    for(int i=0; i<m; ++i) cin>>t[i];
}

void fill_first_row_col(int lcs[][123]){
    for(int i=0; i<=n; ++i) lcs[i][0]=0;
    for(int i=0; i<=m; ++i) lcs[0][i]=0;
}

void solve(){
    scan();

    int lcs[123][123];
    fill_first_row_col(lcs);

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s[i-1]==t[j-1]){
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else{
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }

    cout<<"Twin Towers #"<<++idx<<endl;
    cout<<"Number of Tiles : "<<lcs[n][m]<<endl;
    cout<<endl;
}

int main()
{

    while(cin>>n>>m and (n or m)){
        solve();
    }
    return 0;
}
