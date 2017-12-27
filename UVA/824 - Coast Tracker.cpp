#include <iostream>
#include <cstdio>
using namespace std;

bool g[3][3];
int x[] = {0, -1, -1, -1, 0, 1, 1, 1};
int y[] = {1, 1, 0, -1, -1, -1, 0, 1};
int sx, sy, dir, ans;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void scan(){
    cin >> sy >> dir;
    int dx = sx - 1, dy = sy - 1;

    for(int i = 0; i < 8; ++i){
        int px, py, land;

        cin >> px >> py >> land;
        px -= dx; py -= dy;

        if(land) g[px][py] = true;
        else g[px][py] = false;
    }
}

void solve(){
    int s = (dir + 6) % 8, t = (s + 7) % 8;

    for(int k = s; k != t; k = (k + 1) % 8){
        int ii = 1 + x[k], jj = 1 + y[k];
        if(g[ii][jj]){
            ans = k;
            break;
        }
    }
}

void print(){
    cout << ans << endl;
}

int main()
{
    //file();

    while(cin >> sx){
        if(sx == -1) break;
        scan();
        solve();
        print();
    }

    return 0;
}
