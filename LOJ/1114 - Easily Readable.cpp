#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;

int getId(char c){
    if(c >= 'A' and c <= 'Z') return (c - 'A');
    return (26 + c - 'a');
}

struct Trie{
    int sz, root;
    int tree[mx][52];
    int info[mx];

    Trie(){
        sz = root = 0;
        resetRow(sz);
    }

    void resetRow(int r){
        memset(tree[r], -1, sizeof(tree[r]));
        info[r] = 0;
    }

    void pushWord(string a){
        int cur = root;
        for(int i = 0; a[i]; ++i){
            int nxt = getId(a[i]);
            if(tree[cur][nxt] == -1){
                tree[cur][nxt] = ++sz;
                resetRow(sz);
            }
            cur = tree[cur][nxt];
        }
        ++info[cur];
    }

    int findWord(string a){
        int cur = root;
        for(int i = 0; a[i]; ++i){
            int nxt = getId(a[i]);
            if(tree[cur][nxt] == -1){
                return 0;
            }
            cur = tree[cur][nxt];
        }
        return info[cur];
    }
};

string buffer;

int toInt(string s){
    int x;
    stringstream ss(s);

    ss >> x;
    return x;
}

int nextInt(){
  getline(cin,buffer);
  return toInt(buffer);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //even if you still use printf, scanf
    //use following lines for faster I/0
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //If the problem is about line input
    //always try to use line input through whole program
    int tc = nextInt();

    for(int t = 1; t <= tc; ++t){
        int n;
        string str;
        Trie tree;

        n = nextInt();
        for(int i = 0; i < n; ++i){
            getline(cin, str);
            if(str.size() > 2) sort(str.begin() + 1, str.end() - 1);
            tree.pushWord(str);
        }

        printf("Case %d:\n", t);

        n = nextInt();
        for(int i = 0; i < n; ++i){
            getline(cin, str);
            stringstream ss(str);

            string word;
            int ans = 1;
            while(ss >> word){
                if(word.size() > 2) sort(word.begin() + 1, word.end() - 1);
                ans *= tree.findWord(word);
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
