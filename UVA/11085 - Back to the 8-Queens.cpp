#include <iostream>
using namespace std;

const int mx = 8;
int givenRowPos[mx], rowPos[mx];
int ans, x;

void scan(){
    ans = mx;
    givenRowPos[0] = x - 1;
    for(int i = 1; i < mx; ++i){
        int y;
        cin >> y;
        givenRowPos[i] = y - 1;
    }
}

void print(int tc){
    cout << "Case " << tc << ": " << ans << endl;
}

int min(int x, int y){
    if(x < y) return x;
    return y;
}

int abs(int x){
    if(x < 0) return -x;
    return x;
}

bool safe(int row, int col){
    for(int i = 0; i < col; ++i){
        if(row == rowPos[i]) return false;

        int rowDif = abs(row - rowPos[i]);
        int colDif = abs(col - i);
        if(rowDif == colDif) return false;
    }
    return true;
}

void solve(int col, int total){
    if(col == mx){
        ans = min(ans, total);
        return;
    }

    for(int row = 0; row < mx; ++row){
        if(safe(row, col)){
            rowPos[col] = row;
            if(row == givenRowPos[col]){
                solve(col + 1, total);
            }
            else{
                solve(col + 1, total + 1);
            }
        }
    }
}

int main()
{
    int t = 0;
    while(cin >> x){
        scan();
        solve(0, 0);
        print(++t);
    }

    return 0;
}
