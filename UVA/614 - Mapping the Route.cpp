#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

const int mx = 15;
int path[mx][mx], g[mx][mx];
bool visited[mx][mx];
bool found;
int x[] = {0, -1, 0, 1};
int y[] = {-1, 0, 1, 0};
int n, m, si, sj, ti, tj;

class Maze{
public:
    Maze(int n, int m) : r(2*n + 1), c(4*m + 1){
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                maze[i] += ' ';
            }
        }
    }

    void write(){
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                cout << maze[i][j];
            }
            cout << endl;
        }
    }

    void fillWall(){
        //fill with '+'
        for(int i = 0; i < r; i += 2){
            for(int j = 0; j < c; j += 4){
                maze[i][j] = '+';
            }
        }

        //fill with '|'
        for(int i = 1; i < r; i += 2){
            for(int j = 0; j < c; j += 4*m){
                maze[i][j] = '|';
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(g[i][j] == 1 or g[i][j] == 3){
                    maze[2*i + 1][4*j + 4] = '|';
                }
            }
        }

        //fill with '-;
        for(int i = 0; i < r; i += 2*n){
            for(int j = 0; j < c; ++j){
                if(j % 4 == 0) continue;
                maze[i][j] = '-';
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(g[i][j] == 2 or g[i][j] == 3){
                    int ii = 2*i + 2, jj = 4*j + 1;
                    for(int k = 0; k < 3; ++k){
                        maze[ii][jj++] = '-';
                    }
                }
            }
        }
    }

    void fillQ(){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(visited[i][j] and path[i][j] == -1){
                    int ii = 2*i + 1, jj = 4*j + 1;
                    for(int k = 0; k < 3; ++k){
                        maze[ii][jj++] = '?';
                    }
                }
            }
        }
    }

    void fillNum(){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(path[i][j] != -1){
                    stringstream ss;
                    ss << path[i][j];
                    string num = ss.str();
                    int ii = 2*i + 1, jj = 4*j + 3;
                    for(int k = num.size() - 1; k >= 0; --k){
                        maze[ii][jj--] = num[k];
                    }
                }
            }
        }
    }
private:
    int r, c;
    string maze[50];
};

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    found = false;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
            path[i][j] = -1;
        }
    }
}

bool scan(){
    cin >> n >> m >> si >> sj >> ti >> tj;
    if(!n and !m and !si and !sj and !ti and !tj) return false;

    --si; --sj; --ti; --tj;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> g[i][j];
        }
    }

    return true;
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

bool boundary(int i, int j, int bi, int bj){
    if(i + x[0] == bi and j + y[0] == bj){
        //west
        return (g[bi][bj] == 1 or g[bi][bj] == 3);
    }
    if(i + x[1] == bi and j + y[1] == bj){
        //north
        return (g[bi][bj] == 2 or g[bi][bj] == 3);
    }
    if(i + x[2] == bi and j + y[2] == bj){
        //east
        return (g[i][j] == 1 or g[i][j] == 3);
    }
    if(i + x[3] == bi and j + y[3] == bj){
        //south
        return (g[i][j] == 2 or g[i][j] == 3);
    }
    return false;
}

void dfs(int ui, int uj, int val, bool& inpath){
    visited[ui][uj] = true;
    bool flag = false;

    if(ui == ti and uj == tj) flag = found =true;

    for(int k = 0; k < 4; ++k){
        int vi = ui + x[k], vj = uj + y[k];
        if(valid(vi, vj) and !visited[vi][vj] and !found and !boundary(ui, uj, vi, vj)){
            dfs(vi, vj, val + 1, flag);
        }
    }

    if(flag){
        inpath = true;
        path[ui][uj] = val;
    }
}

void solve(){
    bool flag = false;
    dfs(si, sj, 1, flag);
}

void print(int t){
    Maze a(n, m);
    a.fillWall();
    a.fillQ();
    a.fillNum();

    cout << "Maze " << t << endl << endl;
    a.write();
    cout << endl;
    cout << endl;
}

int main()
{
    //file();

    int t = 1;
    while(scan()){
        reset();
        solve();
        print(t++);
    }

    return 0;
}
