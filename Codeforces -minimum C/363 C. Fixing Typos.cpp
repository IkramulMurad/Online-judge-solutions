#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;

    if(s.size()==1){
        cout<<s;
        return 0;
    }

    vector<pair<char,int> >v;
    char prv=s[0];
    int freq=1;

    //remove more than or equal 3 consecutive character
    for(int i=1; i<s.size(); ++i){
        if(s[i]==prv){
            ++freq;
        }
        else{
            v.push_back(make_pair(prv,min(freq,2)));
            prv=s[i];
            freq=1;
        }

        if(i==s.size()-1){
            v.push_back(make_pair(prv,min(freq,2)));
        }
    }

    //remove all typo
    for(int i=1; i<v.size(); ++i){
        if(v[i].second==2 and v[i-1].second==2){
            v[i].second=1;
        }
    }

    //print
    for(int i=0; i<v.size(); ++i){
        cout<<v[i].first;
        if(v[i].second==2) cout<<v[i].first;
    }

    return 0;
}
