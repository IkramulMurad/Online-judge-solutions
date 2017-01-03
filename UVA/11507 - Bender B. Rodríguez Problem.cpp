#include <bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int l;
    while(cin>>l and l){
        string s,t="+x";
        for(int i=1; i<l; ++i){
            cin>>s;
            if(s=="No") continue;
            if(t=="+x") t=s;
            else if(t=="-x"){
                t=s;
                s[0]=='+' ? t[0]='-' : t[0]='+';
            }
            else if(t=="+y"){
                if(s=="+y") t="-x";
                else if(s=="-y") t="+x";
            }
            else if(t=="-y"){
                if(s=="+y") t="+x";
                else if(s=="-y") t="-x";
            }
            else if(t=="+z"){
                if(s=="+z") t="-x";
                else if(s=="-z") t="+x";
            }
            else if(t=="-z"){
                if(s=="+z") t="+x";
                else if(s=="-z") t="-x";
            }
        }
        cout<<t<<endl;
    }
    return 0;
}
