#include <bits/stdc++.h>
 
using namespace std;
int a[505][505];
 
int getGrundy(int i,int j){
    set<int> v;
    set<int>::iterator it;
    int mx=10;
    int x[6]={-2,-2,-3,-1,-1,1};
    int y[6]={1,-1,-1,-2,-3,-2};
    for(int k=0;k<6;k++){
        int posx=i+x[k],posy=j+y[k];
        if(posx<0||posx>=503) v.insert(mx);
        else if(posy<0||posy>=503) v.insert(mx);
        else{
            int val=a[posx][posy];
            v.insert(val);
        }
    }
    int g=0;
    for(it=v.begin();it!=v.end();it++,g++){
        if(g!=*it) break;
    }
    return g;
}
void cal(){
    memset(a,0,sizeof(a));
    for(int i=0;i<503;i++){
        for(int j=i,k=0;j>=0;j--,k++){
            a[j][k]=getGrundy(j,k);
        }
    }
    int x=502;
    for(int i=0;i<x;i++){
        for(int j=x,k=i+1;j>i;j--,k++){
            a[j][k]=getGrundy(j,k);
        }
    }
}
int main()
{
    //freopen("out1.txt","w",stdout);
    cal();
    /*for(int i=0;i<503;i++){
        for(int j=0;j<503;j++){
            printf("%4d", a[i][j]);
        }
        cout<<endl;
    }*/
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n,ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            ans^=a[x][y];
        }
        printf("Case %d: ",t);
        ans>0?printf("Alice\n"):printf("Bob\n");
    }
    return 0;
}
