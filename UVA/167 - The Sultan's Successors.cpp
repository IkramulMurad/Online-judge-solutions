#include <iostream>
#include <iomanip>
using namespace std;

const int mx = 8;
int board[mx][mx];
int place[mx];
int ans;

void scan(){
    ans = 0;
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            cin >> board[i][j];
        }
    }
}

void print(){
    cout << setw(5) << ans << endl;
}

int abs(int x){
    if(x < 0) return -x;
    return x;
}

int max(int x, int y){
    if(x > y) return x;
    return y;
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

void solve(int col, int sum){
    if(col == mx){
        ans = max(ans, sum);
        return;
    }
    for(int row = 0; row < mx; ++row){
        if(safe(row, col)){
            place[col] = row;
            solve(col + 1, sum + board[row][col]);
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        scan();
        solve(0, 0);
        print();
    }

    return 0;
}
