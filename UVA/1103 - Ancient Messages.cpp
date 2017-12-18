#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 205;
char dg[mx][mx], g[mx][mx];
bool visited[mx][mx];
int n, m;
char binVal[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                        "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
char hgByVal[] = "WAKJSD";
char hgByAlpha[] = "ADJKSW";
int place[6];
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < 6; ++i){
        place[i] = 0;
    }
}

void scan(){
    for(int i = 0; i < n; ++i){
        cin >> dg[i];
    }
}

int getBin(char hex){
    int s = 0;
    if(hex == '0') s = 0;
    if(hex == '1') s = 1;
    if(hex == '2') s = 2;
    if(hex == '3') s = 3;
    if(hex == '4') s = 4;
    if(hex == '5') s = 5;
    if(hex == '6') s = 6;
    if(hex == '7') s = 7;
    if(hex == '8') s = 8;
    if(hex == '9') s = 9;
    if(hex == 'a') s = 10;
    if(hex == 'b') s = 11;
    if(hex == 'c') s = 12;
    if(hex == 'd') s = 13;
    if(hex == 'e') s = 14;
    if(hex == 'f') s = 15;
    return s;
}

void process(){
    m *= 4;
    for(int i = 0; i < n; ++i){
        int j = 0;
        while(j < m){
            int idx = getBin(dg[i][j/4]);

            for(int k = 0; k < 4; ++k){
                g[i][j++] = binVal[idx][k];
            }
        }
    }
}

int getIndex(int total){
    char ch = hgByVal[total];

    int i;
    for(i = 0; i < 6; ++i){
        if(hgByAlpha[i] == ch) break;
    }
    return i;
}

bool border(int i, int j){
    return (i == 0 or j == 0 or i == n - 1 or j == m - 1);
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

void fillSpace(int i, int j){
    visited[i][j] = true;
    g[i][j] = '.';

    for(int k = 0; k < 4; ++k){
        int ii = i + x[k];
        int jj = j + y[k];

        if(valid(ii, jj) and !visited[ii][jj] and g[ii][jj] == '0'){
            fillSpace(ii, jj);
        }
    }
}

void dfs(int i, int j, int& total){
    visited[i][j] = true;

    for(int k = 0; k < 4; ++k){
        int ii = i + x[k];
        int jj = j + y[k];

        if(valid(ii, jj) and !visited[ii][jj]){
            if(g[ii][jj] == '0'){
                ++total;
                fillSpace(ii, jj);
            }
            else if(g[ii][jj] == '1'){
                dfs(ii, jj, total);
            }
        }
    }
}

void solve(){
    //fill outside space
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(border(i, j) and !visited[i][j] and g[i][j] == '0'){
                fillSpace(i, j);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j] and g[i][j] == '1'){
                int total = 0;
                dfs(i, j, total);

                int index = getIndex(total);
                ++place[index];
            }
        }
    }
}

void print(int t){
    cout << "Case " << t << ": ";
    for(int i = 0; i < 6; ++i){
        int rng = place[i];
        for(int j = 0; j < rng; ++j){
            cout << hgByAlpha[i];
        }
    }
    cout << endl;
}

int main()
{
    //file();

    int t = 0;

    while(cin >> n >> m and (n or m)){
        reset();
        scan();
        process();
        solve();
        print(++t);
    }

    return 0;
}
