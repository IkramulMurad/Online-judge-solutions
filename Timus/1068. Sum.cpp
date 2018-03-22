#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long total;
    while(cin>>n){
        if(n==0){
            total=1;
        }
        else if(n<0){
            n=abs(n);
            total=(n*(n+1))/2;
            total-=1;
            total=0-total;
        }
        else total=(n*(n+1))/2;
        cout<<total<<endl;
    }
    return 0;
}
