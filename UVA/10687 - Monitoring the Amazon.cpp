#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class NearStation{
public:
    NearStation() : x(50), y(50), dist(100){}
    NearStation(int _x, int _y, double _dist) : x(_x), y(_y), dist(_dist){}
    bool operator<(const NearStation&);
    NearStation& operator=(const NearStation&);
private:
    int x, y;
    double dist;
};

class Station{
    friend istream& operator>>(istream&, Station&);
    friend ostream& operator<<(ostream&, Station&);
public:
    Station() : visited(false) {}
    void visitNearest(int);
    bool isVisited();
    void setVisited(bool);
    void instantiate();
private:
    int x, y;
    bool visited;
    NearStation a, b;
};

const double eps = 1e-6;
const int mx = 1005;
Station stations[mx];
int n;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

bool equal(double a, double b){
    return (abs(a - b) < eps);
}

void reset(){
    for(int i = 0; i < mx; ++i){
        stations[i].instantiate();
    }
}

void scan(){
    for(int i = 0; i < n; ++i){
        cin >> stations[i];
    }
}

void solve(){
    stations[0].visitNearest(0);
}

void print(){
    bool imp = false;

    for(int i = 0; i < n; ++i){
        if(!stations[i].isVisited()){
            imp = true;
            break;
        }
    }

    if(imp) cout << "There are stations that are unreachable." << endl;
    else cout << "All stations are reachable." << endl;
}

int main()
{
    //file();

    while(cin >> n and n){
        reset();
        scan();
        solve();
        print();
    }

    return 0;
}


bool NearStation::operator<(const NearStation& b){
    //cerr << dist << " " << b.dist << endl;
    if(abs(dist - b.dist) < eps){
        if(x == b.x)
            return y < b.y;
        return x < b.x;
    }
    return dist < b.dist;
}

NearStation& NearStation::operator=(const NearStation& b){
    x = b.x;    y = b.y;    dist = b.dist;
    return *this;
}

istream& operator>>(istream& is, Station& b){
    return is >> b.x >> b.y;
}

ostream& operator<<(ostream& os, Station& b){
    os << "x: " << b.x << endl;
    os << "y: " << b.y << endl;
    os << "visited: " << b.visited << endl << endl;
    return os;
}

void Station::visitNearest(int cur){
    stations[cur].setVisited(true);

    int indexA, indexB;
    indexA = indexB = n;

    for(int i = 0; i < n; ++i){
        if(i == cur) continue;

        double dist = hypot(stations[cur].x - stations[i].x, stations[cur].y - stations[i].y);
        NearStation c(stations[i].x, stations[i].y, dist);

        if(c < stations[cur].a){
            stations[cur].b = stations[cur].a; indexB = indexA;
            stations[cur].a = c; indexA = i;
        }
        else if(c < stations[cur].b){
            stations[cur].b = c; indexB = i;
        }
    }

    if(!stations[indexA].isVisited() and indexA != n) visitNearest(indexA);
    if(!stations[indexB].isVisited() and indexB != n) visitNearest(indexB);
}

bool Station::isVisited(){
    return visited;
}

void Station::setVisited(bool flag){
    visited = flag;
}

void Station::instantiate(){
    NearStation x;
    a = x; b = x;
    visited = false;
}
