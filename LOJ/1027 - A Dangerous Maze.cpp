#include <bits/stdc++.h>
 
using namespace std;
int den,num;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
void reduce(){
    int g=gcd(num,den);
    den/=g;
    num/=g;
}
void ep(int a[],int n){
    den=n;
    num=0;
    for(int i=0;i<n;i++){
        num+=abs(a[i]);
        if(a[i]<0) den--;
    }
    reduce();
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n,flag=0;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]>0) flag=1;
        }
        if(flag==0) printf("Case %d: inf\n",t);
        else{
            ep(a,n);
            printf("Case %d: %d/%d\n",t,num,den);
        }
    }
    return 0;
}
