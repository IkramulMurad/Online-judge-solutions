#include <bits/stdc++.h>

using namespace std;

bool isprime(int n){
    int sq=sqrt(n)+1;
    for(int i=2;i<=sq;++i){
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    if(n==2) cout<<1;
    else if(isprime(n)) cout<<1;
    else if(n%2==0) cout<<2;
    else{
        if(isprime(n-2)) cout<<2;
        else cout<<3;
    }
    return 0;
}
