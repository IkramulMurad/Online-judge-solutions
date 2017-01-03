#include <bits/stdc++.h>

using namespace std;

char next(char c){
    if(c=='R') return 'D';
    return 'R';
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int n;
    while(cin>>n  and n){
        string s;
        cin>>s;
        bool flag=false;
        int mn=2e9,pos,kount=0;
        char cur;
        for(int i=0; i<n; ++i){
            pos=i;
            if(s[i]=='Z'){
                mn=0;
                break;
            }
            if(s[i]!='.'){
                cur=s[i];
                break;
            }
        }
        for(int i=pos; i<n; ++i,++kount){
            if(s[i]==next(cur)){
                mn=min(mn,kount);
                kount=0;
                cur=s[i];
            }
            else if(s[i]==cur) kount=0;
            else if(s[i]=='Z'){
                mn=0;
                break;
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}
