#include <iostream>
#include <cstdio>
using namespace std;

class Queue{
public:
    Queue() : f(0), r(-1) {}
    bool empty() { return f > r; }
    int front() { return q[f]; }
    void push(int val) { q[++r] = val; }
    void pop() { if(!empty()) ++f; }
    void print();
private:
    int f, r;
    int q[500];
};

void Queue::print(){
    cerr << f << " " << r << endl;
    for(int i = f; i <= r; ++i){
        cerr << q[i] << " ";
    }
    cerr << endl;
}

const int mx = 25;
bool g[mx][mx], visited[mx][mx];
int n, m, x, y, ans;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void reset(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

void scan(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> g[i][j];
        }
    }
    cin >> x >> y;
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

void bfs(int i, int j, int v){
    if(x == 0 and y == 0){
        if(g[i][j]) ans = 0;
        return;
    }
    Queue qx, qy, qv;
    qx.push(i); qy.push(j); qv.push(v);
    visited[i][j] = true;

    while(!qx.empty()){
        int si = qx.front(), sj = qy.front(), v = qv.front();
        qx.pop(); qy.pop(); qv.pop();

        for(int k = 0; k < 4; ++k){
            int ii = si + dx[k], jj = sj + dy[k];
            if(g[si][sj] and valid(ii, jj) and !visited[ii][jj] and g[ii][jj]){
                visited[ii][jj] = true;
                qx.push(ii); qy.push(jj); qv.push(v + 1);

                if(ii == x and jj == y) { ans = v + 1; return; }
            }
        }

    }
}

void solve(){
    ans = -1;
    bfs(0, 0, 0);
}

void print(){
    cout << ans << endl;
}

int main()
{
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
