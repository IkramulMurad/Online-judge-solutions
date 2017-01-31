#include <bits/stdc++.h>

using namespace std;

string table[515];
string bin;

void makebin(int n){
    if(n){
        char c='0'+char(n%2);
        n/=2;
        makebin(n);
        bin.push_back(c);
    }
}

void pre(){
    for(int i=1; i<=512; ++i){
        bin="";
        makebin(i);
        table[i]=bin;
    }
}

bool comp(string a, string b){
    if(a.size()>b.size()) return true;
    else if(a.size()<b.size()) return false;
    else{
        for(int i=0; i<a.size(); ++i){
            if(a[i]>b[i]) return true;
            else if(a[i]<b[i]) return false;
        }
    }
    return false;
}

int main()
{
    string s;
    cin>>s;
    pre();

    int ans=0;
    for(int i=1; i<=512; ++i){
        if(comp(table[i],s)) break;
        ++ans;
    }
    cout<<ans;

    return 0;
}
