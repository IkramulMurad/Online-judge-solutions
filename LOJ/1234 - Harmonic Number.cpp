#include <bits/stdc++.h>
 
using namespace std;
const int max_num=1e6+5;
const int lim=1e8;
double a[max_num];
int main()
{
    //freopen("in.txt","r",stdin);
    double x=0;
    a[0]=0;
    int k=1;
    for(int i=1;i<=lim;i++){
        x+=double((double)1.0/(double)i);
        if(i%100==0){
            a[k]=x;
            k++;
        }
    }
    int T,n;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        int index=n/100;
        double res=a[index];
        int start=index*100+1;
        for(int i=start;i<=n;i++){
            res+=double((double)1.0/(double)i);
        }
        printf("Case %d: %.10f\n",t,res);
    }
    return 0;
}
