#include <iostream>
using namespace std;

class Node{
public:
    Node(){}
    Node(int _x, int _y, int _val, int _t = 0) : x(_x), y(_y), val(_val), t(_t) {}
    int getX() { return x; }
    int getY() { return y; }
    int getVal() { return val; }
    int getTime() { return t; }
    void setVal(int _val) { val = _val; }
    void setTime(int _t) { t = _t; }
    Node operator=(Node b){
        x = b.getX();
        y = b.getY();
        val = b.getVal();
        t = b.getTime();

        return *this;
    }
private:
    int x, y, val, t;
};

class Queue{
public:
    Queue() : f(0), r(-1) {}
    Node front() { return a[f]; }
    bool empty() { return f > r; }
    void push(Node x) { a[++r] = x; }
    void pop() { if(!empty()) ++f; }
private:
    int f, r;
    Node a[10005];
};

const int mx = 105;
Node g[mx][mx];
bool visited[mx][mx];
int n, m;
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

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
            int w;
            cin >> w;

            g[i][j] = Node(i, j, w);
        }
    }
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

int bfs(){
    Queue q;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(g[i][j].getVal() == 2){
                visited[i][j] = true;
                q.push(g[i][j]);
            }
        }
    }

    int ans = 0;
    while(!q.empty()){
        Node s = q.front(); q.pop();

        for(int k = 0; k < 4; ++k){
            int newX = s.getX() + x[k];
            int newY = s.getY() + y[k];

            if(valid(newX, newY) and g[newX][newY].getVal() == 1 and !visited[newX][newY]){
                g[newX][newY].setVal(2);
                g[newX][newY].setTime(s.getTime() + 1);
                q.push(g[newX][newY]);

                visited[newX][newY] = true;
                ans = g[newX][newY].getTime();
            }
        }
    }

    return ans;
}

void solve(){
    int ans = bfs();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            //cerr << g[i][j].getVal() << " ";
            if(g[i][j].getVal() == 1) ans = -1;
        }
        //cerr << endl;
    }

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
    }

    return 0;
}
