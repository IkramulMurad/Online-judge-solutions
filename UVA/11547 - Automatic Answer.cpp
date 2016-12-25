#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        long long n;
        cin>>n;

        n*=567;
        n/=9;
        n+=7492;
        n*=235;
        n/=47;
        n-=498;
        n%=100;
        n/=10;
        if(n<0) n*=-1;

        cout<<n<<endl;
    }
    return 0;
}
