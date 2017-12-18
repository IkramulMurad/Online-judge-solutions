#include <iostream>
#include <cstdio>
using namespace std;
const int mx = 105;

class Cluster{
public:
    bool a[mx][mx];
    int height, width, size;

    Cluster& operator=(Cluster&);
    void make(int, int, int, int, int, bool [][mx], bool [][mx]);
    bool match(Cluster&);
    void reverse();
    void rotate();
    bool operator==(Cluster&);
};

Cluster& Cluster::operator=(Cluster& b){
    height = b.height;
    width = b.width;
    size = b.size;

    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            a[i][j] = b.a[i][j];
        }
    }

    return *this;
}

void Cluster::make(int mnx, int mny, int mxx, int mxy, int kount, bool g[mx][mx], bool visited[mx][mx]){
    size = kount;
    height = mxx - mnx + 1;
    width = mxy - mny + 1;

    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            if(visited[i + mnx][j + mny] and g[i + mnx][j + mny]){
                a[i][j] = g[i + mnx][j + mny];
                g[i + mnx][j + mny] = false;
            }
            else{
                a[i][j] = false;
            }
        }
    }
}

bool Cluster::match(Cluster& b){
    if(height != b.height or width != b.width or size != b.size) return false;

    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            if(a[i][j] != b.a[i][j]) return false;
        }
    }

    return true;
}

void Cluster::reverse(){
    Cluster tmp;
    tmp = *this;

    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            a[i][j] = tmp.a[i][width - j - 1];
        }
    }
}

void Cluster::rotate(){
    Cluster tmp;
    tmp = *this;

    height = tmp.width;
    width = tmp.height;

    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            a[i][j] = tmp.a[j][i];
        }
    }
}

bool Cluster::operator==(Cluster& b){
    for(int i = 0; i < 4; ++i){
        if(match(b)) return true;
        rotate();
        if(match(b)) return true;
        reverse();
    }
    return false;
}

bool g[mx][mx], r[mx][mx];
bool visited[mx][mx];
bool imp;
bool taken[3005];
Cluster place[3005];
int idx;
int n, m;
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void clr(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

void reset(){
    imp = false;
    idx = 0;

    clr();

    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            g[i][j] = r[i][j] = false;
        }
    }

    for(int i = 0; i < 3005; ++i){
        taken[i] = false;
    }
}

void scan(){
    int k;
    cin >> n >> m >> k;

    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < k; ++j){
            int u, v;
            cin >> u >> v;

            if(!i) g[u][v] = true;
            else r[u][v] = true;
        }
    }
}

int min(int x, int y){
    if(x < y) return x;
    return y;
}

int max(int x, int y){
    if(x > y) return x;
    return y;
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

void dfs(int i, int j, int& mnx, int& mny, int& mxx, int& mxy, int& kount, int type){
    visited[i][j] = true;

    ++kount;
    mnx = min(mnx, i); mny = min(mny, j);
    mxx = max(mxx, i); mxy = max(mxy, j);

    for(int k = 0; k < 4; ++k){
        int ii = i + x[k];
        int jj = j + y[k];

        bool gra;
        if(!type) gra = g[ii][jj];
        else gra = r[ii][jj];

        if(valid(ii, jj) and !visited[ii][jj] and gra){
            dfs(ii, jj, mnx, mny, mxx, mxy, kount, type);
        }
    }
}

bool found(Cluster clust){
    bool ret = false;
    for(int i = 0; i < idx; ++i){
        if(!taken[i] and place[i] == clust){
            taken[i] = true;
            ret = true;
            break;
        }
    }
    return ret;
}

void solve(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(g[i][j] and !visited[i][j]){
                int mnx = i, mny = j, mxx = i, mxy = j;
                int kount = 0;

                dfs(i, j, mnx, mny, mxx, mxy, kount, 0);
                place[idx++].make(mnx, mny, mxx, mxy, kount, g, visited);
            }
        }
    }

    clr();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(r[i][j] and !visited[i][j]){
                Cluster clust;
                int mnx = i, mny = j, mxx = i, mxy = j;
                int kount = 0;

                dfs(i, j, mnx, mny, mxx, mxy, kount, 1);
                clust.make(mnx, mny, mxx, mxy, kount, r, visited);

                if(!found(clust)){
                    imp = true;
                }
            }
        }
    }
}

void print(){
    if(imp) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main()
{
    //file();

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}
