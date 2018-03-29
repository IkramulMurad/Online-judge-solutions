#include <bits/stdc++.h>
using namespace std;

bool a[1024];
int idx;
string str;

void solve(int s, int t, int v){
    if(str[idx] == 'f'){
        for(int i = s; i < t; ++i) a[i] = true;
    }

    if(str[idx] == 'p'){
        int ex = v / 4;
        for(int i = 0; i < 4; ++i){
            int l = s + (i * ex);
            int r = l + ex;
            ++idx;
            solve(l, r, v / 4);
        }
    }
}

void fun(){
    memset(a, false, sizeof(a));

    idx = 0;
    cin >> str;
    solve(0, 1024, 1024);

    idx = 0;
    cin >> str;
    solve(0, 1024, 1024);
}

void print(){
    int ans = 0;
    for(int i = 0; i < 1024; ++i){
        if(a[i]) ++ans;
    }
    cout << "There are " << ans << " black pixels." << endl;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        fun();
        print();
    }

    return 0;
}
