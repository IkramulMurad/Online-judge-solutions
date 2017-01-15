#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        long long sum=0;
        int n;
        cin>>n;
        cout<<"Case "<<i<<":\n";
        for(int j=0;j<n;j++){
            string s;
            int k;
           
            cin>>s;
            if(s[0]=='d'){
                cin>>k;
                sum+=k;
            }
            else{
                cout<<sum<<endl;
            }
        }
    }
    return 0;
}
