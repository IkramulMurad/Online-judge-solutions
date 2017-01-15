#include <bits/stdc++.h>
 
using namespace std;
class Cube{
    public:
    int x1,x2,y1,y2,z1,z2;
 
 
};
Cube getPoints(Cube a,Cube b){
        a.x1=max(a.x1,b.x1);
        a.y1=max(a.y1,b.y1);
        a.z1=max(a.z1,b.z1);
        a.x2=min(a.x2,b.x2);
        a.y2=min(a.y2,b.y2);
        a.z2=min(a.z2,b.z2);
        return a;
}
long long getVolume(Cube a){
        long long x,y,z,ans;
        x=abs(a.x2-a.x1);
        y=abs(a.y2-a.y1);
        z=abs(a.z2-a.z1);
        ans=x*y*z;
        return ans;
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        Cube a[n];
        Cube res;
        for(int j=0;j<n;j++){
            cin>>a[j].x1>>a[j].y1>>a[j].z1>>a[j].x2>>a[j].y2>>a[j].z2;
        }
        res=a[0];
        Cube b;
        b.x1=b.x2=b.y1=b.y2=b.z1=b.z2=0;
        for(int j=1;j<n;j++){
            if(res.x1>=a[j].x2||res.x2<=a[j].x1){
                res=b;
                break;
            }
            else if(res.y1>=a[j].y2||res.y2<=a[j].y1){
                res=b;
                break;
            }
            else if(res.z1>=a[j].z2||res.z2<=a[j].z1){
                res=b;
                break;
            }
            else res=getPoints(res,a[j]);
        }
        long long ans=getVolume(res);
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}
