#include <bits/stdc++.h>
using namespace std;

const int mx = 8;
int p[mx][mx];
int a[mx], b[mx];
int n;

int minBlocks(){
    int ans = 0;

    int c[mx];
    for(int i = 0; i < n; ++i) c[i] = a[i];

    for(int i = 0; i < n; ++i){
        bool found = false;
        for(int j = 0; j < n; ++j){
            if(b[i] == c[j]){
                ans += b[i];
                c[j] = 0;

                found = true;
                break;
            }
        }
        if(!found) ans += b[i];
    }

    for(int i = 0; i < n; ++i) if(c[i]) ans += c[i];

    return ans;
}

int maxBlocks(){
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            ans += min(b[i], a[j]);
        }
    }

    return ans;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        cin >> n;

        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];

        int ans1 = minBlocks();
        int ans2 = maxBlocks();
        ans2 -= ans1;

        printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", ans1, ans2);
    }

    return 0;
}
