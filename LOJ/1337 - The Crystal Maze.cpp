#include <bits/stdc++.h>
 
using namespace std;
 
#define vi v+y[i]
#define ui u+x[i]
 
const int mx=505;
char g[mx][mx];
bool visited[mx][mx];
int cBoss[mx][mx], height, width, cc, ans;
int x[]={1,-1,0,0};
int y[]={0,0,1,-1};
bitset<250005> used;
int res[250005];
 
void clr(){
    for(int i=0; i<height; ++i){
        for(int j=0; j<width; ++j){
            visited[i][j]=0;
        }
    }
}
 
void dfs(int u, int v){
    visited[u][v]=1;
    cBoss[u][v]=cc;
    if(g[u][v]=='C') ++ans;
    for(int i=0; i<4; ++i){
        if(ui>=0 and vi>=0 and ui<height and vi<width){
            if(!visited[ui][vi] and g[ui][vi]!='#'){
                dfs(ui,vi);
            }
        }
    }
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int q;
        scanf("%d %d %d",&height,&width,&q);
        getchar();
 
        //clear
        memset(cBoss,0,sizeof(cBoss));
        clr();
 
        //scanning graph
        char c;
        for(int i=0; i<height; ++i){
            for(int j=0; j<width; ++j){
                scanf("%c",&c);
                g[i][j]=c;
            }
            getchar();
        }
 
        //process
        res[0]=0;
        cc=1;
        for(int i=0; i<height; ++i){
            for(int j=0; j<width; ++j){
                if(g[i][j]=='#'){
                    cBoss[i][j]=0;
                    visited[i][j]=1;
                    continue;
                }
                else if(!visited[i][j]){
                    ans=0;
                    dfs(i,j);
                    //cout<<cc<<" "<<ans<<endl;
                    res[cc++]=ans;
                }
 
            }
        }
 
        printf("Case %d:\n",t);
 
        for(int i=0; i<q; ++i){
            int u,v;
            scanf("%d %d",&u,&v);
            --u; --v;
            int answer=res[cBoss[u][v]];
            printf("%d\n",answer);
        }
    }
    return 0;
}
