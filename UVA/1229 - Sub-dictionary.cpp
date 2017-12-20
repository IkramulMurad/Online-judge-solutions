#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;

const int mx = 105;
unordered_map<string, vector<string> > g(mx), tg(mx);
unordered_map<string, bool> visited(mx);
vector<string> stk(mx);
int top;
pair<int, vector<string> > sub[mx];
unordered_map<string, int> scc(mx);
vector<string> ans;
int n, total;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    top = total = 0;
    visited.clear();
    g.clear();
    tg.clear();
    scc.clear();
    ans.clear();
    for(int i = 0; i < mx; ++i){
        sub[i].second.clear();
    }
}

void scan(){
    for(int i = 0; i < n; ++i){
        string s;
        getline(cin, s);

        string u, v;
        stringstream in(s);

        in >> u;
        while(in >> v){
            g[u].push_back(v);
            tg[v].push_back(u);
        }
    }
}

void dfs(string u){
    visited[u] = true;

    for(auto v : g[u]){
        if(!visited[v]){
            dfs(v);
        }
    }

    stk[top++] = u;
}

void dfs2(string u, int& kount){
    visited[u] = true;
    sub[total].second.push_back(u);
    scc[u] = total;
    ++kount;

    for(auto v : tg[u]){
        if(!visited[v]){
            dfs2(v, kount);
        }
    }
}

void dfs3(string u, vector<string>& tmp){
    visited[u] = true;
    tmp.push_back(u);

    for(auto v : g[u]){
        if(!visited[v]){
            dfs3(v, tmp);
        }
    }
}

void solve(){
    for(auto it = g.begin(); it != g.end(); ++it){
        string u = it->first;
        if(!visited[u]){
            dfs(u);
        }
    }

    visited.clear();
    for(int i = top - 1; i >= 0; --i){
        string u = stk[i];
        if(!visited[u]){
            int kount = 0;
            dfs2(u, kount);

            sub[total].first = kount;
            ++total;
        }
    }

    visited.clear();
    for(int i = 0; i < total; ++i){
        if(sub[i].first > 1){
            string u = sub[i].second[0];

            if(!visited[u]){
                dfs3(u, ans);
            }
        }
    }
}

void print(){
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); ++i){
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

int main()
{
    //file();

    while(cin >> n and n){
        getchar();
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
