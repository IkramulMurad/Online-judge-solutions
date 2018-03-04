#include <bits/stdc++.h>
using namespace std;

void scan(int& n, vector<int>& f, vector<int>& g){
    cin >> n;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        f.push_back(x);
    }

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        g.push_back(x);
    }
}

void print(int ans){
    if(ans == 0) cout << "none" << endl;
    else if(ans == 1) cout << "front" << endl;
    else if(ans == 2) cout << "back" << endl;
    else if(ans == 3) cout << "both" << endl;
}

bool satisfy(vector<int>& f, vector<int>& g){
    for(int i = 0; i < f.size(); ++i){
        if(f[i] > g[i]) return false;
    }
    return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        int n;
        vector<int> f, g;
        scan(n, f, g);

        int ans = 0;
        if(satisfy(f, g)){
            ans += 1;
        }

        reverse(g.begin(), g.end());
        if(satisfy(f, g)){
            ans += 2;
        }

        print(ans);
    }

    return 0;
}
