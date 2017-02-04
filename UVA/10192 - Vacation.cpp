#include <bits/stdc++.h>

using namespace std;

int idx=0;

void solve(string s, string t){
    int n=s.size(), m=t.size();

    int lcs[n+1][m+1];
    for(int i=0; i<=n; ++i) lcs[i][0]=0;
    for(int i=0; i<=m; ++i) lcs[0][i]=0;

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

    cout<<"Case #"<<++idx<<": you can visit at most "<<lcs[n][m]<<" cities."<<endl;

}

int main()
{
    //freopen("in.txt","r",stdin);
    string s,t;
    while(getline(cin,s) and getline(cin,t)){
        if(s[0]=='#') break;

        solve(s,t);
    }

    return 0;
}
