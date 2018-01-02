#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

string calculate(int b, int s){
    if(b == 1) return ":-\\";
    if(b <= s) return ":-|";
    return ":-(";
}

int main()
{
    //file();

    int b, s, t = 0;
    while(cin >> b >> s and (b or s)){
        cout << "Case " << ++t << ": " << calculate(b, s) << endl;
    }

    return 0;
}
