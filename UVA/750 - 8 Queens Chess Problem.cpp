#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int mx = 8;
int fixRow, fixCol, kase;
int pos[mx];
//ifstream in("in.txt");
//ofstream out("out.txt");

void preSolve(){
    cin >> fixRow >> fixCol;
    --fixRow; --fixCol;

    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8" << endl << endl;

    kase = 0;
    pos[fixCol] = fixRow;
}

void print(){
    cout << setw(2) << ++kase << "     ";
    for(int i = 0; i < mx; ++i){
        cout << " " << pos[i] + 1;
    }
    cout << endl;
}

int abs(int x){
    if(x < 0) return -x;
    return x;
}

bool safe(int row, int col){
    if(row == fixRow) return false;
    if(abs(row - fixRow) == abs(col - fixCol)) return false;

    for(int i = 0; i < col; ++i){
        if(pos[i] == row) return false;

        int rowDif = abs(row - pos[i]);
        int colDif = abs(col - i);

        if(rowDif == colDif) return false;
    }

    return true;
}

void solve(int col){
    if(col == fixCol){
        solve(col + 1);
        return; //tricky point
    }
    if(col == mx){
        print();
        return;
    }

    for(int row = 0; row < mx; ++row){
        if(safe(row, col)){
            pos[col] = row;
            solve(col + 1);
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        if(t > 1) cout << endl;
        preSolve();
        solve(0);
    }

    return 0;
}
