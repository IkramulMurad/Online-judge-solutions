#include <iostream>
using namespace std;

int a[20];
int N, r;

void print(){
    for(int i = 0; i < N; ++i){
        cout << a[i];
    }
    cout << endl;
}

void dfs(int n, int r) {
    if(r > n || r < 0) return;
    if(n == 0) {
        print();
        return;
    }

    a[N-n] = 0;
    dfs(n-1, r); //not taking 1
    a[N-n] = 1;
    dfs(n-1, r-1); //taking 1
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        cin >> N >> r;

        dfs(N, r);
        if(t) cout << endl;
    }
    return 0;
}
