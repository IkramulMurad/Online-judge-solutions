#include <bits/stdc++.h>
using namespace std;

const int mx = 50000 * 32 + 5;

struct Trie{
    int root, sz;
    int tree[mx][2];
    int val[mx];

    Trie(){
        root = sz = 0;
        resetRow(sz);
    }

    void resetRow(int r){
        memset(tree[r], -1, sizeof(tree[r]));
        val[r] = 0;
    }

    void insert(int x){
        int cur = root;
        for(int i = 31; i >= 0; --i){
            bool nxt = x & (1 << i);
            if(tree[cur][nxt] == -1){
                tree[cur][nxt] = ++sz;
                resetRow(sz);
            }
            cur = tree[cur][nxt];
        }
        val[cur] = x;
    }

    int query(int x, bool type){
        int cur = root;
        for(int i = 31; i >= 0; --i){
            bool nxt = x & (1 << i);
            if(tree[cur][nxt ^ (type ? 1 : 0)] != -1){
                cur = tree[cur][nxt ^ (type ? 1 : 0)];
            }
            else if(tree[cur][nxt ^ (type ? 0 : 1)] != -1){
                cur = tree[cur][nxt ^ (type ? 0 : 1)];
            }
        }
        return x ^ val[cur];
    }
};

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int mx = INT_MIN;
        int mn = INT_MAX;
        int prefix_xor = 0;

        Trie tree;
        tree.insert(prefix_xor);

        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            int x;
            scanf("%d", &x);

            prefix_xor ^= x;
            mn = min(mn, tree.query(prefix_xor, 0));
            mx = max(mx, tree.query(prefix_xor, 1));

            tree.insert(prefix_xor);
        }
        printf("Case %d: %d %d\n", t, mx, mn);
    }

    return 0;
}
