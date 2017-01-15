#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m;
        cin>>n>>m;
        long long a[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='S'){
                int d;
                cin>>d;
                for(int k=0;k<n;k++){
                    a[k]+=d;
                }
            }
            else if(c=='M'){
                int d;
                cin>>d;
                for(int k=0;k<n;k++){
                    a[k]*=d;
                }
            }
            else if(c=='D'){
                int d;
                cin>>d;
                for(int k=0;k<n;k++){
                    a[k]/=d;
                }
            }
            else if(c=='R'){
                reverse(a,a+n);
            }
            else if(c=='P'){
                long long x;
                int y,z;
                cin>>y>>z;
                x=a[y];
                a[y]=a[z];
                a[z]=x;
            }
        }
        cout<<"Case "<<i<<":\n";
        int j;
        for(j=0;j<n-1;j++){
            cout<<a[j]<<" ";
        }
        cout<<a[j]<<endl;
    }
    return 0;
}
