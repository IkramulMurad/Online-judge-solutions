#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL string_to_int(string s){
    LL ans=0;
    LL p=1;
    for(int i=s.size()-1; i>=0; --i){
        ans+=(LL)(s[i]-'0')*p;
        p*=10;
    }
    return ans;
}

LL getInt(string s, LL p){
    LL num=string_to_int(s);
    return  p*num;
}

int getDigit(LL n){
    int ans=0;
    while(n){
        n/=10;
        ++ans;
    }
    return ans;
}

int main()
{

//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    LL n;
    string k;
    while(cin>>n>>k){
        int dig=getDigit(n);
        LL ans=0,p=1;

        int last;
        int first;
        for(int i=k.size()-1; i>=0;){
            last=i;
            first=max(last-dig+1,0);

            if(string_to_int(k.substr(first,last-first+1))>=n){
                ++first;
            }
            while(first<last and k[first]=='0') ++first;

            string s=k.substr(first,last-first+1);
            ans+=getInt(s,p);

            p*=n;
            i=first-1;
        }
        cout<<ans<<endl;
    }

    return 0;
}
