#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        string s[n],thief="eidakuchuhoilo",theft;
        int a[n];
        long long sum=0,avg;
        for(int j=0;j<n;j++){
            int x,y,z;
            cin>>s[j]>>x>>y>>z;
            a[j]=x*y*z;
            sum+=a[j];
        }
        avg=sum/n;
        for(int j=0;j<n;j++){
            if(a[j]<avg) theft=s[j];
            if(a[j]>avg) thief=s[j];
        }
        if(thief=="eidakuchuhoilo"){
            cout<<"Case "<<i<<": no thief\n";
        }
        else
            cout<<"Case "<<i<<": "<<thief<<" took chocolate from "<<theft<<"\n";
    }
    return 0;
}
