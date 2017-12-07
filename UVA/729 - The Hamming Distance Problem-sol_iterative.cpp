#include <iostream>
using namespace std;

bool chk(int num, int pos){
    return bool(num & (1 << pos));
}

void print(int num, int upto){
    for(int i = upto - 1; i >= 0; --i){
        cout << chk(num, i);
    }
}

bool satisfy(int num, int total, int upto){
    int ans = 0;
    for(int i = 0; i < upto; ++i){
        if(chk(num, i)) ++ans;
    }
    return ans == total;
}

void solve(int n, int r){
    int rng = (1 << n);
    for(int i = 0; i < rng; ++i){
        if(satisfy(i, r, n)){
            print(i, n);
            cout << endl;
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        int n, r;
        cin >> n >> r;

        if(t > 1) cout << endl;

        solve(n, r);
    }

    return 0;
}
