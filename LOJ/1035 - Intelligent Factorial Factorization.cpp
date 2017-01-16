#include <bits/stdc++.h>
 
using namespace std;
 
int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int a[101][101];
 
void cal(){
    memset(a,0,sizeof(a));
    a[2][2]=1;
    for(int i=3;i<=100;i++){
        int n=i;
        for(int j=0;prime[j]<=i;j++){
            int kount=a[i-1][prime[j]];
            while(n%prime[j]==0){
                n/=prime[j];
                kount++;
            }
            a[i][prime[j]]=kount;
            if(j==24) break;
        }
    }
}
 
int main()
{
    cal();
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n;
        scanf("%d",&n);
        printf("Case %d: %d =",t,n);
        int flag=0;
        for(int i=0;prime[i]<=n;i++){
            if(!flag){
                flag=1;
                if(a[n][prime[i]]!=0){
                    printf(" %d (%d)",prime[i],a[n][prime[i]]);
                }
            }
            else{
                if(a[n][prime[i]]!=0){
                    printf(" * %d (%d)",prime[i],a[n][prime[i]]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
