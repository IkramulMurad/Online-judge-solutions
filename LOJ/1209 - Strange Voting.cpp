#include <bits/stdc++.h>
using namespace std;

const int mx = 505;
vector <vector <int> > g(mx);
int l[mx], r[mx];
bool visited[mx];
int c[mx], nc[mx];
bool type[mx];

bool dfs(int u){
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i];
        if(!visited[v]){
            visited[v] = true;
            if(l[v] == -1 or dfs(l[v])){
                l[v] = u;
                r[u] = v;
                return true;
            }
        }
    }
    return false;
}

int bpm(int n){
    int total = 0;
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));

    for(int i = 0; i < n; ++i){
        memset(visited, false, sizeof(visited));
        if(type[i] and dfs(i)) ++total;
    }
    return total;
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n, m, v;
        scanf("%d %d %d", &n, &m, &v);

        memset(type, 0, sizeof(type));
        for(int i = 0; i < v; ++i){
            char typ, garbage;
            int choice, notChoice;
            cin >> typ >> choice >> garbage >> notChoice;

            if(typ == 'M') type[i] = 1;
            c[i] = choice; nc[i] = notChoice;
            //cerr << "type: " << typ << ", choice: " << choice << ", not choice: " << notChoice << endl;
        }

        for(int i = 0; i < mx; ++i) g[i].clear();

        for(int i = 0; i < v; ++i){
            for(int j = 0; j < v; ++j){
                if(type[i] and type[i] != type[j] and (c[i] == nc[j] or nc[i] == c[j])){
                    g[i].push_back(j);
                }
            }
        }

        int ans = v - bpm(v);
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
