#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=205;
const int inf=1e6;
char g[mx][mx];
bool visited[mx][mx];
int fx[40005],fy[40005];
int fire[mx][mx], jane[mx][mx];
int xx,yy;
int x[]={1,-1,0,0};
int y[]={0,0,1,-1};
 
void clr(){
    for(int i=0; i<xx; ++i){
        for(int j=0; j<yy; ++j){
            visited[i][j]=0;
        }
    }
}
 
void clrr(){
    for(int i=0; i<xx; ++i){
        for(int j=0; j<yy; ++j){
            fire[i][j]=jane[i][j]=inf;
        }
    }
}
 
bool isValid(int u, int v){
    if(u>=0 and v>=0 and u<xx and v<yy){
        if(g[u][v]!='#' and !visited[u][v])
            return true;
    }
    return false;
}
 
void bfs1(int idx){
    queue<int> qx,qy,qval;
    for(int i=0; i<idx; ++i){
        int u=fx[i], v=fy[i];
        visited[u][v]=1;
        qx.push(u); qy.push(v); qval.push(0);
    }
 
    while(!qx.empty()){
        int ax=qx.front(), ay=qy.front(), val=qval.front();
        qx.pop(); qy.pop(); qval.pop();
 
        fire[ax][ay]=min(fire[ax][ay],val);
        for(int i=0; i<4; ++i){
            int s=ax+x[i], t=ay+y[i];
            if(isValid(s,t)){
                visited[s][t]=1;
                qx.push(s); qy.push(t); qval.push(val+1);
            }
        }
    }
}
 
bool isCorrect(int u, int v, int val){
    if(u>=0 and v>=0 and u<xx and v<yy){
        if(g[u][v]!='#' and !visited[u][v] and val<fire[u][v])
            return true;
    }
    return false;
}
 
void bfs2(int u, int v){
    visited[u][v]=1;
    queue<int> qx,qy,qval;
    qx.push(u); qy.push(v); qval.push(0);
 
    while(!qx.empty()){
        int ax=qx.front(), ay=qy.front(), val=qval.front();
        qx.pop(); qy.pop(); qval.pop();
        jane[ax][ay]=min(jane[ax][ay],val);
 
        for(int i=0; i<4; ++i){
            int s=ax+x[i], t=ay+y[i];
            if(isCorrect(s,t,val+1)){
                visited[s][t]=1;
                qx.push(s); qy.push(t); qval.push(val+1);
            }
        }
    }
}
 
int getAns(){
    int ans=inf;
    for(int i=0; i<yy; ++i){
        ans=min(ans,jane[0][i]);
        ans=min(ans,jane[xx-1][i]);
    }
    for(int i=0; i<xx; ++i){
        ans=min(ans,jane[i][0]);
        ans=min(ans,jane[i][yy-1]);
    }
    return ans;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        scanf("%d %d",&xx,&yy);
        getchar();
        //scanning graph
        int idx=0, jx, jy;
        char c;
        for(int i=0; i<xx; ++i){
            for(int j=0; j<yy; ++j){
                scanf("%c",&c);
                g[i][j]=c;
                if(c=='F'){
                    fx[idx]=i;
                    fy[idx]=j;
                    ++idx;
                }
                else if(c=='J'){
                    jx=i;
                    jy=j;
                }
            }
            getchar();
        }
 
        //process
        clrr();
        clr();
        bfs1(idx);
 
        /*for(int i=0; i<xx; ++i){
            for(int j=0; j<yy; ++j){
                cout<<fire[i][j]<<" ";
            }
            cout<<endl;
        }*/
 
        clr();
        bfs2(jx,jy);
 
        int ans=getAns();
        printf("Case %d: ",t);
        ans==inf? printf("IMPOSSIBLE\n"):printf("%d\n",ans+1);
    }
    return 0;
}
