#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
vector <vector <int> > g(mx);
bool setter[mx];
int f[mx];
bitset <mx> visited;
int n, m, k;
int mxDist;

void dfs(int u, int dist, int &farthest){
    visited[u] = true;
    if(setter[u] and dist >= mxDist){
        farthest = u;
        mxDist = dist;
    }

    for(auto v : g[u]){
        if(!visited[v]){
            dfs(v, dist + 1, farthest);
        }
    }
}

void dfs(int u, int dist){
    visited[u] = true;
    f[u]++;
    
    for(auto v : g[u]){
        if(!visited[v] and dist < k){
            dfs(v, dist + 1);
        }
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        cin >> n >> m >> k;

        for(int i = 0; i < mx; ++i){
            g[i].clear();
        }
        
        for(int i = 1; i < n; ++i){
            int u, v;
            cin >> u >> v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        int startingNode;
        memset(setter, false, sizeof(setter));
        for(int i = 0; i < m; ++i){
            int x;
            cin >> x;
            setter[x] = true;
            startingNode = x;
        }

        int farthestLeft, farthestRight;

        mxDist = 0;
        visited.reset();
        dfs(startingNode, 0, farthestLeft);

        mxDist = 0;
        visited.reset();
        dfs(farthestLeft, 0, farthestRight);

        //cout << "left: " << farthestLeft << ", right: " << farthestRight << endl;

        memset(f, 0, sizeof(f));

        visited.reset();
        dfs(farthestLeft, 0);
        
        visited.reset();
        dfs(farthestRight, 0);

        int ans = 0;
        for(int i = 1; i <= n; ++i){
            //cout << f[i] << " ";
            if(f[i] > 1){
                ++ans;
            }
        }
        //cout << endl;

        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
