#include <iostream>
#include <cstdio>
using namespace std;

class Language{
public:
    Language(int _sz = 0):sz(_sz){}
    int sz;
    char type;

    void print(){
        cout << type << ": " << sz << endl;
    }

    bool operator<(const Language& b){
        if(sz == b.sz)
            return type > b.type;
        return sz < b.sz;
    }

    Language& operator=(const Language& b){
        sz = b.sz;
        type = b.type;
        return *this;
    }
};

const int mx = 105;
char g[mx][mx];
bool visited[mx][mx];
int n, m, idx;
Language place[mx];
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    idx = 0;
    for(int i = 0; i < mx; ++i){
        place[i].sz = 0;
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

void scan(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> g[i];
    }
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

void dfs(int i, int j, char type){
    visited[i][j] = true;

    for(int k = 0; k < 4; ++k){
        int ii = i + x[k];
        int jj = j + y[k];

        if(valid(ii, jj) and !visited[ii][jj] and g[ii][jj] == type){
            dfs(ii, jj, type);
        }
    }
}

int found(char type){
    int ret = -1;
    for(int i = 0; i < idx; ++i){
        if(place[i].type == type){
            ret = i;
        }
    }
    return ret;
}

void increment(char type){
    int index = found(type);
    if(index != -1){
        ++place[index].sz;
    }
    else{
        place[idx].type = type;
        ++place[idx].sz;
        ++idx;
    }
}

void solve(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j]){
                dfs(i, j, g[i][j]);
                increment(g[i][j]);
            }
        }
    }
}

void bblsort(){
    for(int i = 0; i < idx; ++i){
        for(int j = 1; j < idx; ++j){
            if(place[j] < place[j - 1]){
                Language tmp = place[j];
                place[j] = place[j - 1];
                place[j - 1] = tmp;
            }
        }
    }
}

void print(int t){
    cout << "World #" << t << endl;

    bblsort();
    for(int i = idx - 1; i >= 0; --i){
        place[i].print();
    }
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
        print(t);
    }

    return 0;
}
