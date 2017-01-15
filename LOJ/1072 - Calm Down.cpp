#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        double r,ans,pi=2*acos(0);
        int n;
        cin>>r>>n;
        double x=sin(pi/n);
        //cout<<x<<endl;
        ans=(r*x)/(1+x);
        printf("Case %d: %.10f\n",i,ans);
    }
    return 0;
}
