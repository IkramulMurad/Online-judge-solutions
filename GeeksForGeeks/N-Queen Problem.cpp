#include <iostream>
#include <stdio.h>
using namespace std;

const int mx = 20;
int place[mx];
int n;
bool prevPrint;

void print(){
    if(prevPrint) cout << " ";
    prevPrint = true;

    cout << "[";
    for(int i = 0; i < n; ++i){
        cout << place[i] + 1 << " ";
    }
    cout << "]";
}

int abs(int x){
    if(x < 0) return -x;
    return x;
}

bool safe(int row, int col){
    for(int k = 0; k < col; ++k){
        if(place[k] == row){
            return false;
        }

        int rowDif = abs(row - place[k]);
        int colDif = abs(col - k);

        if(rowDif == colDif){
            return false;
        }
    }
    return true;
}

void solve(int col){
    if(col == n){
        print();
        return;
    }
    for(int row = 0; row < n; ++row){
        if(safe(row, col)){
            place[col] = row;
            solve(col + 1);
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        cin >> n;
        prevPrint = false;

        if(n == 1) cout << "[1 ]";
        else if(n < 4) cout << -1;
        else solve(0);

        cout << endl;
    }

    return 0;
}
