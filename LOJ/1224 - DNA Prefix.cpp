#include <bits/stdc++.h>
using namespace std;

const int mx = 1000000;

int getId(char c){
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    return 3;
}

struct Trie{
    int root, sz;
    int tree[mx][4];
    int info[mx];

    Trie(){
        root = sz = 0;
        resetRow(sz);
        memset(info, 0, sizeof(info));
    }

    void resetRow(int r){
        for(int c = 0; c < 4; ++c) tree[r][c] = -1;
    }

    void pushWord(char a[]){
        int cur = root;
        for(int i = 0; a[i]; ++i){
            int nxt = getId(a[i]);
            if(tree[cur][nxt] == -1){
                tree[cur][nxt] = ++sz;
                resetRow(sz);
            }
            cur = tree[cur][nxt];
            info[cur] += i + 1;
        }
    }

    int getMax(){
        int ans = 0;
        for(int i = 0; i <= sz; ++i){
            ans = max(ans, info[i]);
        }
        return ans;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n;
        scanf("%d", &n);

        char str[n][55];
        Trie tree;

        for(int i = 0; i < n; ++i) scanf("%s", str[i]), tree.pushWord(str[i]);

        int ans = tree.getMax();
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
