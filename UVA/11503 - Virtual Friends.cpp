#include <bits/stdc++.h>

using namespace std;

const int mx=2e5+5;
int parent[mx];
int a[mx];

int find_parent(int n){
    if(parent[n]==n) return n;
    return parent[n]=find_parent(parent[n]);
}

void joint(int u, int v){
    int x=find_parent(u);
    int y=find_parent(v);

    if(x!=y){
        parent[x]=y;

        int j=a[x], k=a[y];
        a[y]+=j;
        a[x]+=k;
        cout<<a[y]<<endl;
    }
    else{
        cout<<a[x]<<endl;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;

    while(tc--){
        int n;
        cin>>n;

        for(int i=0; i<mx; ++i) parent[i]=i, a[i]=1;

        map<string,int> mp;
        for(int i=0; i<n; ++i){
            string s,t;
            cin>>s>>t;

            if(!mp[s]) mp[s]=i+1;
            if(!mp[t]) mp[t]=i+n+1;

            joint(mp[s],mp[t]);
        }

    }

    return 0;
}
