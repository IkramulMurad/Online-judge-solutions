#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
const int mx = 105;
const int inf = 1e9;
vector <vector <int> > g(mx);
int l[mx], r[mx];
bool visited[mx];
int gm[mx][mx];
int n;
string s[mx];
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < n and s[i][j] != '#');
}

int bfs(int si, int sj, int ti, int tj){
    int ans = inf;
    
    queue <iii> q;
    q.push(iii(0, ii(si, sj)));

    bool visited[mx][mx];
    memset(visited, false, sizeof(visited));
    visited[si][sj] = true;

    while(!q.empty()){
        int d = q.front().first;
        int ui = q.front().second.first;
        int uj = q.front().second.second;
        q.pop();

        for(int k = 0; k < 4; ++k){
            int vi = ui + x[k];
            int vj = uj + y[k];
            if(vi == ti and vj == tj){
                return d + 1;
            }
            if(valid(vi, vj) and !visited[vi][vj]){
                q.push(iii(d + 1, ii(vi, vj)));
                visited[vi][vj] = true;
            }
        }
    }
    return ans;
}

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

void makeGraph(int mid, int totalGhost, int totalHuman){
    for(int i = 0; i < mx; ++i) g[i].clear();

    for(int i = 0; i < totalGhost; ++i){
        for(int j = 0; j < totalHuman; ++j){
            if(gm[i][j] <= mid){
                g[i].push_back(totalGhost + j);
            }
        }
    }
}

int binSearch(int lo, int hi, int totalGhost, int totalHuman){
    int ret = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        makeGraph(mid, totalGhost, totalHuman);
        int ans = bpm(totalGhost);

        if(ans >= totalHuman){
            ret = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return ret;
}

int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) cin >> s[i];

        vector <pair <int, int> > ghost, human;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(s[i][j] == 'G'){
                    ghost.push_back(ii(i, j));
                }
                if(s[i][j] == 'H'){
                    human.push_back(ii(i, j));
                }
            }
        }

        int mxDist = 0;
        for(int i = 0; i < ghost.size(); ++i){
            for(int j = 0; j < human.size(); ++j){
                gm[i][j] = bfs(ghost[i].first, ghost[i].second, human[j].first, human[j].second);
                if(gm[i][j] != inf){
                    gm[i][j] = 2 * gm[i][j] + 2;
                    mxDist = max(mxDist, gm[i][j]);
                }
            }
        }

        int ans = binSearch(0, mxDist, (int)ghost.size(), (int)human.size());
        if(ans != -1) printf("Case %d: %d\n", t, ans);
        else printf("Case %d: Vuter Dol Kupokat\n", t);
    }

    return 0;
}
