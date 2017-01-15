#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int n;
        cin>>n;
        if(n==0) cout<<"0 0"<<endl;
        else if(n<=10)
            cout<<"1 "<<n-1<<endl;
        else cout<<"10 "<<n-10<<endl;
    }
    return 0;
}
