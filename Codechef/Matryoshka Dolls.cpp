#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc;
    cin >> tc;
 
    while(tc--){
        int n;
        cin >> n;
 
        map<int, int> m;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            m[x]++;
        }
 
        bool pos = 1;
        for(int i = 0; i < 1001; ++i)
            if(m[i] > 1) pos = 0;
   
        if(pos) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
} 
