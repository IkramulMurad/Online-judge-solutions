#include <bits/stdc++.h>
using namespace std;

#define np next_permutation

int main()
{
//    freopen("in.txt", "r", stdin);
    string s;
    while(true){
        cin >> s;
        if(s[0] == '#') break;

        if(np(s.begin(), s.end())) cout << s << endl;
        else cout << "No Successor" << endl;
    }
    return 0;
}
