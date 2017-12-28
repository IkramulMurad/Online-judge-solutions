#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int mx = 26;
vector<vector<int> > g(mx);
bool light[mx];
int m, t, k;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    for(int i = 0; i < mx; ++i){
        light[i] = false;
        g[i].clear();
    }
}

int getInt(char ch){ return int(ch - 'A'); }
char getCh(int x) { return char('A' + x); }

bool scan(){
    string s;   getline(cin, s);
    if(s == "#") return false;

    int idx = 0;
    while(s[idx] != ' '){
        int u = getInt(s[idx++]);
        while(s[idx] != ';' and s[idx] != '.'){
            if(s[idx] == ':'){
                ++idx; continue;
            }

            int v = getInt(s[idx++]);
            g[u].push_back(v);
        }
        ++idx;
    }

    ++idx; //space
    m = getInt(s[idx++]);
    ++idx; //space
    t = getInt(s[idx++]);
    ++idx; //space

    k = 0;
    while(idx < s.size()) k = k * 10 + (s[idx++] - '0');

    return true;
}

void dfs(int m, int t, int total){
    ++total;
    if(total == k){
        total = 0;
        light[m] = true;
    }

    for(auto v : g[m]){
        if(!light[v] and v != t){
            if(light[m]) cout << getCh(m) << " ";
            dfs(v, m, total);
            return;
        }
    }

    cout << "/" << getCh(m) << endl;
}

int main()
{
    //file();
    while(scan()){
        dfs(m, t, 0);
        reset();
    }

    return 0;
}
