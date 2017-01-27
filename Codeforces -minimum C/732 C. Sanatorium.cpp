#include <iostream>

using namespace std;

int main()
{
    long long b,d,s;
    cin>>b>>d>>s;

    if(b>d and b>s) --b;
    else if(d>b and d>s) --d;
    else if(s>b and s>d) --s;

    else if(b<d and b<s){
        --d; --s;
    }
    else if(d<b and d<s){
        --b; --s;
    }
    else if(s<b and s<d){
        --b; --d;
    }

    long long mx=max(max(b,d),s);
    long long ans=(mx*3)-b-d-s;

    cout<<ans;

    return 0;
}
