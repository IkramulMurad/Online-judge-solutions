#include <bits/stdc++.h>

using namespace std;

int m,f[11],ans[1234];
bool flag=false;

void dfs(int i, int dif, int prv){
    if(i>=m){
        flag=true;
        cout<<"YES"<<endl;
        for(int i=0; i<m; ++i) cout<<ans[i]<<" ";
        cout<<endl;
    }
    for(int j=dif+1; !flag and j<=10; ++j){
        if(f[j] and j!=prv){
            ans[i]=j;
            dfs(i+1,j-dif,j);
        }
    }
}

int main()
{
    string s;
    cin>>s>>m;

    for(int i=0; i<s.size(); ++i){
        if(s[i]=='1') f[i+1]=1;
    }

    dfs(0,0,0);
    if(!flag) cout<<"NO"<<endl;

    return 0;
}
