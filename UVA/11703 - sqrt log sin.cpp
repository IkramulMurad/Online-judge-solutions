#include <bits/stdc++.h>

using namespace std;

const int m=1000000;
const int mx=1000005;
int x[mx];

int main()
{
    x[0]=1;
    for(int i=1; i<mx; ++i){
        double j=i;
        int p1=(int)floor(j-sqrt(j));
        int p2=(int)floor(log(j));
        int p3=(int)floor(j*sin(j)*sin(j));

        x[i]=(x[p1]+x[p2]+x[p3])%m;
    }

    int n;
    while(cin>>n){
        if(n==-1) break;
        cout<<x[n]<<endl;
    }

    return 0;
}
