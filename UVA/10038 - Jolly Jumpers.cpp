#include <bits/stdc++.h>
using namespace std;

bool jolly(vector <int> &v){
    int n = v.size();
    if(n == 1) return true;

    vector <int> u;
    for(int i = 1; i < v.size(); ++i){
        u.push_back(abs(v[i] - v[i - 1]));
    }

    sort(u.begin(), u.end());
    for(int i = 0; i < u.size(); ++i){
        if(u[i] != i + 1) return false;
    }
    return true;
}

int main(){
    //freopen("in.txt", "r", stdin);

    int n;
    while(cin >> n){
        int x;
        vector <int> v;
        for(int i = 0; i < n; ++i){
            cin >> x;
            v.push_back(x);
        }

        if(jolly(v)){
            cout << "Jolly" << endl;
        }
        else cout << "Not jolly" << endl;
    }

    return 0;
}
