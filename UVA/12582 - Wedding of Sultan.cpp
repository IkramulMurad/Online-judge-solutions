#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

const int mx = 26;
int kount[mx];
string str;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int getNum(char ch){
    return int(ch - 'A');
}

char getCh(int num){
    return char('A' + num);
}

void reset(){
    for(int i = 0; i < mx; ++i){
        kount[i] = 0;
    }
}

void scan(){
    cin >> str;
}

void solve(){
    stack<char> stk;
    for(int i = 0; i < str.size(); ++i){
        char ch = str[i];
        if(!stk.empty() and stk.top() == ch){
            stk.pop();
            if(!stk.empty()){
                int x = getNum(stk.top());
                ++kount[x];
            }
        }
        else{
            ++kount[getNum(ch)];
            stk.push(ch);
        }
    }

    --kount[getNum(str[0])];
}

void print(int t){
    cout << "Case " << t << endl;
    for(int i = 0; i < mx; ++i){
        if(kount[i]){
            cout << getCh(i) << " = " << kount[i] << endl;
        }
    }
}

int main()
{
    //file();

    int tc;
    cin >> tc;

    for(int t = 1; t <= tc; ++t){
        reset();
        scan();
        solve();
        print(t);
    }

    return 0;
}
