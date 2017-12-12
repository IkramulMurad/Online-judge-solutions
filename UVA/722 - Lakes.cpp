#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 105;
char g[mx][mx];
bool visited[mx][mx];
int n, m, ans, r, c;
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void fileInput(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
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

void scan(){
    scanf("%d %d ", &r, &c);

    ans = 0;
    n = 0;
    while(gets(g[n])){
        if(g[n][0] < '0' or g[n][0] > '9') break;

        m = len(g[n]);
        ++n;
    }
}

bool valid(int i, int j){
    if(i >= 0 and j >= 0 and i < n and j < m) return true;
    return false;
}

void dfs(int i, int j){
    visited[i][j] = true;
    ++ans;

    for(int k = 0; k < 4; ++k){
        int newI = i + x[k];
        int newJ = j + y[k];
        if(valid(newI,newJ) and !visited[newI][newJ] and g[newI][newJ] == '0'){
            dfs(newI, newJ);
        }
    }
}

void print(int t){
    if(t > 1) cout << endl;
    cout << ans << endl;
}

int main()
{
    //fileInput();

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        reset();
        scan();
        dfs(r - 1, c - 1);
        print(t);
    }

    return 0;
}
