#include <iostream>
using namespace std;

const int mx = 4;
int a[mx][mx];
bool visited[mx][mx];
int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};

void reset(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

void scan(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            cin >> a[i][j];
        }
    }
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < mx and j < mx);
}

void print(){
    int lo = 0, hi = mx - 1;
    while(lo < hi){
        int i, j;
        i = j = lo;

        for(int dir = 0; dir < 4; ++dir){
            for(int k = lo; k <= hi; ++k){
                if(!visited[i][j]){
                    cout << a[i][j] << " ";
                    visited[i][j] = true;
                }
                if(k != hi){
                    i += x[dir];
                    j += y[dir];
                }
            }
        }
        ++lo; --hi;
    }
    cout << endl;
}

int main()
{
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        reset();
        scan();
        print();
    }

    return 0;
}
