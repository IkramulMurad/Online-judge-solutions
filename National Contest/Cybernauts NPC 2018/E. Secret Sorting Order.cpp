#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
const int rng = 28;
const int mx = 1505;
vector < set <int> > g(rng);
int f[rng];
bitset <rng> visited;
int ttime;

int getId(char c){
    return c - 'a';
}

struct Trie
{
    int root, sz;
    int tree[mx][rng];
    set <int> info[mx];

    Trie(){
        init();
    }

    void init(){
        root = sz = 0;
        resetRow(sz);
    }

    void resetRow(int r){
        info[r].clear();
        for(int c = 0; c < rng; ++c){
            tree[r][c] = -1;
        }
    }

    void insert(string s){
        int cur = root;
        for(int i = 0; i < s.size(); ++i){
            int nxt = getId(s[i]);
            if(tree[cur][nxt] == -1){
                tree[cur][nxt] = ++sz;
                resetRow(sz);

                for(auto x : info[cur]){
                    g[x].insert(nxt);
                }
                info[cur].insert(nxt);
            }
            cur = tree[cur][nxt];
        }
    }
};

void dfs(int u){
    visited[u] = true;
    for(auto v : g[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    f[u] = ttime++;
}


int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        int n;
        cin >> n;

        //clear all variables
        for(int i = 0; i < rng; ++i){
            g[i].clear();
        }

        Trie tree;
        tree.init();

        int used[rng] = {0};
        for(int i = 0; i < n; ++i){
            string s;
            cin >> s;

            for(int i = 0; i < s.size(); ++i){
                used[getId(s[i])] = 1;
            }

            //insert into the trie
            tree.insert(s);
        }

        ttime = 1;
        visited.reset();
        memset(f, -1, sizeof(f));
        for(int i = 0; i < rng; ++i){
            if(used[i] and !visited[i]){
                dfs(i);
            }
        }

        vector <ii> v;
        for(int i = 0; i < rng; ++i){
            if(f[i] > 0){
                v.push_back({f[i], i});
            }
        }

        sort(v.rbegin(), v.rend());
        for(int i = 0; i < v.size(); ++i){
            if(i) cout << " ";
            char c = v[i].second + 'a';
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
