#include <bits/stdc++.h>

using namespace std;

string str[10];
int money[10];
int n;

void perform(string s, int amount){
    int idx;
    for(int i=0; i<n; ++i){
        if(str[i]==s) idx=i;
    }
    money[idx]+=amount;
}

int main()
{
    int tc=0;
    while(cin>>n){
        memset(money,0,sizeof money);
        for(int i=0; i<n; ++i){
            cin>>str[i];
        }
        for(int i=0; i<n; ++i){
            string s;
            int x,y;
            cin>>s>>x>>y;
            if(y){
                int amount=x/y;
                perform(s,-(amount*y));
                for(int j=0; j<y; ++j){
                    string t;
                    cin>>t;
                    perform(t,amount);
                }
            }
        }

        if(tc) cout<<endl;
        for(int i=0; i<n; ++i){
            cout<<str[i]<<" "<<money[i]<<endl;
        }
        ++tc;
    }
    return 0;
}
