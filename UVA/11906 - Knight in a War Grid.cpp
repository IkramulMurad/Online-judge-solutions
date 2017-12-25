#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 105;
int visited[mx][mx];
int r, c, m, n, rng;
int dx[] = {-1, 1, -1, 1, -1, 1, -1, 1};
int dy[] = {-1, -1, 1, 1, -1, -1, 1, 1};
int x[8];
int y[8];

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = 0;
        }
    }
}

void prepare(){
    if(!m or !n){
        rng = 4;

        x[0] = -(m | n); x[1] = (m | n);
        y[2] = -(m | n); y[3] = (m | n);
        x[2] = x[3] = y[0] = y[1] = 0;
    }
    else{
        if(m == n) rng = 4;
        else rng = 8;

        for(int i = 0; i < rng; ++i){
            if(i < 4){
                x[i] = dx[i] * m;
                y[i] = dy[i] * n;
            }
            else{
                x[i] = dx[i] * n;
                y[i] = dy[i] * m;
            }
        }
    }
}

void scan(){
    int w;
    cin >> r >> c >> m >> n;
    cin >> w;

    for(int i = 0; i < w; ++i){
        int u, v;
        cin >> u >> v;
        visited[u][v] = -1;
    }
}

void print(int t){
    if(!visited[0][0]) visited[0][0] = 2;

    int odd = 0, even = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            //cerr << visited[i][j] << " ";
            if(visited[i][j] > 0){
                if(visited[i][j] & 1) ++odd;
                else ++even;
            }
        }
    }

    cout << "Case " << t << ": " << even << " " << odd << endl;
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < r and j < c and visited[i][j] != -1);
}

void dfs(int i, int j){
    for(int k = 0; k < rng; ++k){
        int ii = i + x[k];
        int jj = j + y[k];

        if(valid(ii, jj)){
            ++visited[i][j];

            if(!visited[ii][jj]){
                dfs(ii, jj);
            }
        }
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
        prepare();
        dfs(0, 0);
        print(t);
    }

    return 0;
}
