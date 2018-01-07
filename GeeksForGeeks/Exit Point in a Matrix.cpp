#include <iostream>
using namespace std;

const int mx = 25;
bool g[mx][mx];
int n, m, lx, ly, px, py;
int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};

void scan(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> g[i][j];
        }
    }
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

int changeDirection(int d){
    return (d + 1) % 4;
}

void go(int d){
    lx += x[d];
    ly += y[d];
}

void solve(){
    int d = 0;
    lx = ly = 0;
    while(valid(lx, ly)){
        if(g[lx][ly]){
            d = changeDirection(d);
            g[lx][ly] = false;
        }
        px = lx; py = ly;
        go(d);
    }
}

void print(){
    cout << px << " " << py << endl;
}

int main()
{
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        scan();
        solve();
        print();
    }

    return 0;
}
