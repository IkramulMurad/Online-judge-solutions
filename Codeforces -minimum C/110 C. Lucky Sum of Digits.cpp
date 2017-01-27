#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin>>n;

    //4a+7b=n
    int a,b;
    bool impossible=true;
    for(a=0; a*4<=n; ++a){
        if((n-(a*4))%7==0){
            impossible=false;
            b=(n-(a*4))/7;
            break;
        }
    }
    if(impossible) cout<<-1;
    else{
        for(int i=0; i<a; ++i) cout<<4;
        for(int i=0; i<b; ++i) cout<<7;
    }

    return 0;
}
