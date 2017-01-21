#include <bits/stdc++.h>

using namespace std;

bool check(string s){
    stack<char> stk;

    for(int i=0; i<s.size(); ++i){
        if(s[i]=='(' or s[i]=='['){
            stk.push(s[i]);
        }
        else if(s[i]==')' or s[i]==']'){
            if(stk.empty()) return false;
            if(s[i]==')'){
                if( stk.top()=='(') stk.pop();
                else return false;
            }
            else if(s[i]==']'){
                if( stk.top()=='[') stk.pop();
                else return false;
            }
        }
    }

    if(stk.size()) return false;
    return true;
}

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

        check(s)?cout<<"Yes":cout<<"No";
        cout<<endl;
    }

    return 0;
}
