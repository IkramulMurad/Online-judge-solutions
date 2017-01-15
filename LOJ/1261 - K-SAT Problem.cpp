#include <bits/stdc++.h>
 
using namespace std;
int findInSet(int n, int a[],int k){
    if(n>0){
        for(int i=0;i<k;i++){
            if(n==a[i]){
                return 1;
            }
        }
        return 0;
    }
    else{
        for(int i=0;i<k;i++){
            if((-1)*n==a[i]){
                return -1;
            }
        }
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        int a[n][k],hasZero[n];
        for(int j=0;j<n;j++){
            for(int jt=0;jt<k;jt++){
                scanf("%d",&a[j][jt]);
                if(a[j][jt]<0){
                    hasZero[j]=1;
                }
            }
        }
        int p,flag=0;
        scanf("%d",&p);
        int ar[p],choice[n];
        memset(choice,0,sizeof(choice));
        for(int j=0;j<p;j++){
            scanf("%d",&ar[j]);
        }
        for(int j=0;j<n;j++){
            for(int jt=0;jt<k;jt++){
                int x=findInSet(a[j][jt],ar,p);
                if(x==1){
                    choice[j]=1;
                    break;
                }
                else {
                    choice[j]+=x;
                }
            }
        }
        for(int j=0;j<n;j++){
            if(choice[j]<=0){
                flag=1;
                break;
            }
        }
        if(p==0){
            int f=0;
            for(int j=0;j<n;j++){
                if(hasZero[j]!=1){
                    f=1;
                    break;
                }
            }
            if(f==0)printf("Case %d: Yes\n",i);
            else printf("Case %d: No\n",i);
        }
        else if(flag==1) printf("Case %d: No\n",i);
        else if(flag==0) printf("Case %d: Yes\n",i);
    }
    return 0;
}
