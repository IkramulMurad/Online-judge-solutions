#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 105;
char g[mx][mx];
bool visited[mx][mx];
int n, m, ans;
int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void fileInput(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    ans = 0;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

int len(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; ++i){}
    return i;
}

bool valid(int i, int j){
    if(i >= 0 and j >= 0 and i < n and j < m) return true;
    return false;
}

void dfs(int r, int c){
    visited[r][c] = true;
    ++ans;

    for(int i = 0; i < 8; ++i){
        int vr = r + x[i];
        int vc = c + y[i];
        if(valid(vr, vc) and !visited[vr][vc] and g[vr][vc] == 'W'){
            dfs(vr, vc);
        }
    }
}

void scanAndSolve(){
    char line[mx];
    while(gets(line)){
        if(line[0] == 'L' or line[0] == 'W'){
            m = len(line);
            sscanf(line, "%s", g[n]);
            ++n;
        }
        else if(line[0] >= '0' and line[0] <= '9'){
            int r, c;
            sscanf(line, "%d %d", &r, &c);

            reset();
            dfs(r - 1, c - 1);
            cout << ans << endl;
        }
        else break;
    }
}

int main()
{
    //fileInput();

    int tc;
    scanf("%d ", &tc);

    for(int t = 0; t < tc; ++t){
        if(t) cout << endl;

        n = m = 0;
        scanAndSolve();
    }

    return 0;
}
