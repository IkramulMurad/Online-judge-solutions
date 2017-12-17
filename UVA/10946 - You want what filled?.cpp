#include <iostream>
#include <cstdio>
using namespace std;

class Hole{
public:
    int sz;
    char type;

    void print(){
        cout << type << " " << sz << endl;
    }

    bool operator<(const Hole& b){
        if(sz == b.sz)
            return type > b.type;
        return sz < b.sz;
    }

    Hole& operator=(const Hole& b){
        sz = b.sz;
        type = b.type;
        return *this;
    }
};

const int mx = 55;
char g[mx][mx];
bool visited[mx][mx];
int n, m, idx;
Hole place[3000];
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    idx = 0;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 0; i < n; ++i){
        cin >> g[i];
    }
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

void dfs(int i, int j, int& kount, char type){
    visited[i][j] = true;
    ++kount;

    for(int k = 0; k < 4; ++k){
        int ii = i + x[k];
        int jj = j + y[k];

        if(valid(ii, jj) and !visited[ii][jj] and g[ii][jj] == type){
            dfs(ii, jj, kount, type);
        }
    }
}

void solve(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j] and g[i][j] != '.'){
                int kount = 0;
                dfs(i, j, kount, g[i][j]);

                place[idx].sz = kount;
                place[idx++].type = g[i][j];
            }
        }
    }
}

void bblsort(){
    for(int i = 0; i < idx; ++i){
        for(int j = 1; j < idx; ++j){
            if(place[j] < place[j - 1]){
                Hole tmp = place[j];
                place[j] = place[j - 1];
                place[j - 1] = tmp;
            }
        }
    }
}

void print(int t){
    cout << "Problem " << t << ":" << endl;

    bblsort();
    for(int i = idx - 1; i >= 0; --i){
        place[i].print();
    }
}

int main()
{
    //file();

    int t = 0;
    while(cin >> n >> m and (n or m)){
        reset();
        scan();
        solve();
        print(++t);
    }

    return 0;
}
