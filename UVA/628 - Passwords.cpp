#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 256 + 5;
char dict[105][mx];
char rules[1005][mx];
int numDict, numRules;
int place[1005];

void scan(){
    for(int i = 0; i < numDict; ++i){
        cin >> dict[i];
    }

    cin >> numRules;
    for(int i = 0; i < numRules; ++i){
        cin >> rules[i];
    }
}

void print(int xthRule, int ruleLength){
    for(int i = 0; i < ruleLength; ++i){
        if(rules[xthRule][i] == '0') cout << place[i];
        else cout << dict[place[i]];
    }
    cout << endl;
}

int strlen(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; ++i){}
    return i;
}

char* append(char* s, char* x){
    int lens = strlen(s);
    int lenx = strlen(x);

    for(int i = 0; i < lenx; ++i){
        s[i + lens] = x[i];
    }

    s[lens + lenx] = '\0';
    return s;
}

void solve(int currentIndex, int xthRule, int ruleLength){
    if(currentIndex == ruleLength){
        print(xthRule, ruleLength);
        return;
    }

    int rng = 10;
    bool useDictionary = false;
    if(rules[xthRule][currentIndex] == '#'){
        useDictionary = true;
        rng = numDict;
    }

    for(int i = 0; i < rng; ++i){
        place[currentIndex] = i;
        solve(currentIndex + 1, xthRule, ruleLength);
    }

}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    while(cin >> numDict){
        scan();

        cout << "--" << endl;
        for(int i = 0; i < numRules; ++i){
            solve(0, i, strlen(rules[i]));
        }
    }

    return 0;
}
