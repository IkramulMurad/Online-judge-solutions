#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
 
int main(){
 
    int tc;
    cin>>tc;
 
    for(int t=1; t<=tc; ++t){
    	LL a[3];
    	for(int i=0; i<3; ++i) cin>>a[i];
 
    	sort(a,a+3);
 
    	printf("Case %d: ",t);
 
    	if(a[0]+a[1]<=a[2]) cout<<"Invalid"<<endl;
    	else if(a[0]<=0 or a[1]<=0 or a[2]<=0) cout<<"Invalid"<<endl;
    	else if(a[0]==a[1] and a[1]==a[2]) cout<<"Equilateral"<<endl;
    	else if(a[0]==a[1] or a[1]==a[2]) cout<<"Isosceles"<<endl;
    	else cout<<"Scalene"<<endl;
    }
 
    return 0;
 
}
