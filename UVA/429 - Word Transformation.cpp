#include <bits/stdc++.h>

using namespace std;

map<string,vector<string> > g;
map<string,bool> visited;

int bfs(string u, string v){
    queue<pair<string,int> > q;
    q.push(make_pair(u,0));
    visited[u]=1;

    while(!q.empty()){
        string node=q.front().first;
        int val=q.front().second;

        q.pop();

        if(node==v) return val;

        vector<string> vg=g[node];
        for(int i=0; i<vg.size(); ++i){
            if(!visited[vg[i]]){
                visited[vg[i]]=1;
                q.push(make_pair(vg[i],val+1));
            }
        }
    }

    return 1; //for safety
}

bool satisfy(string s, string t){
    if(s.size()!=t.size()) return false;

    int kount=0;
    for(int i=0; i<s.size(); ++i){
        if(s[i]!=t[i]) ++kount;
    }

    if(kount>1) return false;
    return true;
}

int main()
{
    int tc;
    cin>>tc;

    for(int i=0; i<tc; ++i){
        g.clear();

        string x;
        vector<string> v;

        while(cin>>x and x!="*"){
            v.push_back(x);
        }

        for(int i=0; i<v.size()-1; ++i){
            for(int j=i+1; j<v.size(); ++j){
                if(satisfy(v[i],v[j])){
                    g[v[i]].push_back(v[j]);
                    g[v[j]].push_back(v[i]);
                }
            }
        }

        if(i) cout<<endl;

        getchar();
        string s;
        while(getline(cin,s) and s.size()){
            visited.clear();
            stringstream sin(s);
            string b,e;
            sin>>b>>e;

            cout<<b<<" "<<e<<" "<<bfs(b,e)<<endl;
        }
    }

    return 0;
}
