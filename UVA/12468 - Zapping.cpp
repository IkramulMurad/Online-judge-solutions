#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    while(cin>>a>>b){
        if(a<0 and b<0) break;

        int x=abs(a-b);
        int y=min(a,b)+100-max(a,b);

        cout<<min(x,y)<<endl;
    }
    return 0;
}
