#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n and n){
        int ans=n;
        while(ans>9){
            ans=0;
            while(n!=0){
                ans+=n%10;
                n/=10;
            }
            n=ans;
        }
        cout<<ans<<endl;
    }
    return 0;
}
