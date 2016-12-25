#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,c=1;
    while(cin>>n and n){
        int x,kount=0;
        for(int i=0; i<n; ++i){
            cin>>x;
            if(x==0) ++kount;
        }
        printf("Case %d: ",c++);
        cout<<(n-kount)-kount<<endl;
    }
    return 0;
}
