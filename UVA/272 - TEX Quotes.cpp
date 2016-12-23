#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char c;
    string s;
    int flag=0;
    while(~scanf("%c",&c)){
        if(c=='"' and !flag){
            s+="``";
            flag=1;
        }
        else if(c=='"' and flag){
            s+="''";
            flag=0;
        }
        else{
            s.push_back(c);
        }
    }
    //PE for newline
    cout<<s;
    return 0;
}
