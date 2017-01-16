#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=12;
const int inf=1e6;
char g[mx][mx];
bool visited[mx][mx];
int temp[mx][mx];
int xx,yy,cnt;
int riderx[105], ridery[105], riderVal[105];
int x[]={1,1,2,2,-1,-1,-2,-2};
int y[]={2,-2,1,-1,2,-2,1,-1};
 
void clr(){
    for(int i=0; i<xx; ++i){
        for(int j=0; j<yy; ++j){
            visited[i][j]=0;
            temp[i][j]=inf;
        }
    }
}
 
bool valid(int ax, int ay){
    if(ax>=0 and ay>=0 and ax<xx and ay<yy and !visited[ax][ay]){
        return true;
    }
    return false;
}
 
void bfs(int u, int v){
    visited[u][v]=1;
    queue<int> qx,qy,qval;
    qx.push(u); qy.push(v); qval.push(0);
 
    while(!qx.empty()){
        int sx=qx.front(), sy=qy.front(), sval=qval.front();
        qx.pop(); qy.pop(); qval.pop();
        temp[sx][sy]=sval;
 
        for(int i=0; i<8; ++i){
            int zx=sx+x[i];
            int zy=sy+y[i];
            if(valid(zx,zy)){
                visited[zx][zy]=1;
                qx.push(zx);
                qy.push(zy);
                qval.push(sval+1);
            }
        }
    }
}
 
int addRiders(int rng){
    int sum=0;
    for(int i=0; i<rng; ++i){
        int u=riderx[i], v=ridery[i], val=riderVal[i];
        int z=temp[u][v]/val;
        if(temp[u][v]%val) ++z;
        sum+=z;
    }
    return sum;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        scanf("%d %d",&xx,&yy);
        getchar();
 
        //scanning graph
        char c;
        int idx=0;
        for(int i=0; i<xx; ++i){
            for(int j=0; j<yy; ++j){
                scanf("%c",&c);
                g[i][j]=c;
                if(c>'0'){
                    int val=c-48;
                    riderVal[idx]=val;
                    riderx[idx]=i;
                    ridery[idx]=j;
                    ++idx;
                }
            }
            getchar();
        }
 
        //process
        int res=100000;
        for(int i=0; i<xx; ++i){
            for(int j=0; j<yy; ++j){
                clr();
                bfs(i,j);
                int sum=addRiders(idx);
                res=min(res,sum);
            }
        }
 
        printf("Case %d: ",t);
        res==100000 ? printf("-1\n") : printf("%d\n",res);
    }
    return 0;
}
