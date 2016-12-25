#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c=1;
    string s;
    while(cin>>s){
        if(s=="*") break;

        printf("Case %d: ",c++);
        if(s=="Hajj") printf("Hajj-e-Akbar\n");
        else printf("Hajj-e-Asghar\n");
    }
    return 0;
}
