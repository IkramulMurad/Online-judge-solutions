#include <bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int tc;
    cin>>tc;
    getchar();
    while(tc--){
        string s;
        getline(cin,s);
        int m,f,flag=0,no=0;
        m=f=0;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='M') ++m;
            else if(s[i]=='F') ++f;
        }
        if(m==1) cout<<"NO LOOP"<<endl;
        else if(m!=f) cout<<"NO LOOP"<<endl;
        else cout<<"LOOP"<<endl;
    }
    return 0;
}
