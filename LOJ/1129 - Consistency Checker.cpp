#include <bits/stdc++.h>
using namespace std;

const int mx = 100005;

struct Trie{
    int root, sz;
    int trie[mx][10];
    bool info[mx];

    Trie(){
        root = sz = 0;
        resetRow(sz);
        for(int i = 0; i < mx; ++i) info[i] = false;
    }

    void resetRow(int r){
        for(int i = 0; i < 10; ++i) trie[r][i] = -1;
    }

    void pushWord(char a[]){
        int cur = root;
        for(int i = 0; a[i]; ++i){
            int nxt = a[i] - '0';
            if(trie[cur][nxt] == -1){
                trie[cur][nxt] = ++sz;
                resetRow(sz);
            }
            cur = trie[cur][nxt];
        }
        info[cur] = true;
    }

    bool findWord(char a[]){
        bool prefix = true;
        int cur = root;
        for(int i = 0; a[i]; ++i){
            int nxt = a[i] - '0';
            if(trie[cur][nxt] == -1){
                return false;
            }
            cur = trie[cur][nxt];
            if(info[cur]) return true;
        }
        return prefix;
    }
};

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        Trie tree;
        int n;
        cin >> n;

        char str[n][11];
        for(int i = 0; i < n; ++i) cin >> str[i];

        bool ans = true;
        for(int i = 0; i < n; ++i){
            if(tree.findWord(str[i])){
                ans = false;
                break;
            }
            else{
                tree.pushWord(str[i]);
            }
        }

        cout << "Case " << t << ": ";
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
