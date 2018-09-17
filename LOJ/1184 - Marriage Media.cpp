#include <bits/stdc++.h>
using namespace std;

const int mx = 105;
vector <vector <int> > g(mx);
int l[mx], r[mx];
bool visited[mx];

struct Info{
    int height, age;
    bool status;

    bool possible(Info &b){
        return (abs(height - b.height) <= 12 and abs(age - b.age) <= 5 and status == b.status);
    }
};

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
        if(dfs(i)) ++total;
    }
    return total;
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n, m;
        scanf("%d %d", &n, &m);

        Info chart[n + m];
        for(int i = 0; i < n + m; ++i){
            cin >> chart[i].height >> chart[i].age >> chart[i].status;
        }

        for(int i = 0; i < mx; ++i) g[i].clear();

        for(int i = 0; i < n; ++i){
            for(int j = n; j < n + m; ++j){
                if(chart[i].possible(chart[j])){
                    g[i].push_back(j);
                }
            }
        }

        int ans = bpm(n);
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
