/* Motivated by a Chinese programmar */

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

void solve(string s, LL a, LL b){
    bool pref[s.length()]={0};
    bool suf[s.length()]={0};

    LL sum=0;
    for(int i=0; i<s.size(); ++i){
        sum=(sum*10+s[i]-'0')%a;
        pref[i]=sum==0;
    }

    sum=0;
    LL t=1;
    for(int i=s.size()-1; i>=0; --i){
        sum=(((s[i]-'0')*t)%b+sum%b)%b;
        t=(t*10)%b;

        suf[i]=sum==0;
    }

    bool flag=false;
    for(int i=0; i<s.size()-1; ++i){
        if(s[i+1]!='0' and pref[i] and suf[i+1]){
            flag=true;
            cout<<"YES"<<endl;

            for(int k=0; k<=i; ++k){
                cout<<s[k];
            }
            cout<<endl;

            for(int k=i+1; k<s.size(); ++k){
                cout<<s[k];
            }
            break;
        }
    }

    if(!flag) cout<<"NO";
}

int main()
{
    string s;
    LL a,b;
    cin>>s>>a>>b;

    solve(s,a,b);

    return 0;
}
