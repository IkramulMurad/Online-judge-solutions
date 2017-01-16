#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=13;
char g[mx][mx];
bool visited[mx][mx], impossible;
int n,cnt;
int x[]={1,-1,0,0};
int y[]={0,0,1,-1};
 
void clr(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            visited[i][j]=0;
        }
    }
}
 
void bfs(int u, int v, char target){
    visited[u][v]=1;
    vector<pair<int,int> > old,cur;
    old.push_back(make_pair(u,v));
 
    while(!old.empty()){
        ++cnt;
        for(int j=0; j<old.size(); ++j){
            int ax=old[j].first, ay=old[j].second;
            for(int i=0; i<4; ++i){
                int sx=ax+x[i];
                int sy=ay+y[i];
                if(sx>=0 and sy>=0 and sx<n and sy<n){
                if(!visited[sx][sy] and g[sx][sy]==target) return;
                    if(!visited[sx][sy] and (g[sx][sy]=='.' or (g[sx][sy]<target and g[sx][sy]>='A')) ){
                        visited[sx][sy]=1;
                        cur.push_back(make_pair(sx,sy));
                    }
                }
            }
        }
        old.clear();
        old=cur;
        cur.clear();
    }
 
    if(old.empty()) impossible=true;
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        scanf("%d",&n);
 
        getchar();
        char ch,cmax=0;
        int idx=0;
        int foodx[26],foody[26];
 
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                scanf("%c",&ch);
                cmax=max(cmax,ch);
                g[i][j]=ch;
 
                if(ch>='A'){
                    int z=ch-65;
                    foodx[z]=i;
                    foody[z]=j;
                    idx=max(idx,z);
                }
            }
            getchar();
        }
 
        if(cmax<'A'){
            printf("Case %d: 0\n",t);
            continue;
        }
 
        //process
        impossible=false;
        int ans=0;
        for(int i=0; i<idx; ++i){
            clr();
            cnt=0;
            char target='A'+i+1;
            bfs(foodx[i],foody[i],target);
            ans+=cnt;
 
            if(impossible) break;
        }
 
        if(impossible) printf("Case %d: Impossible\n",t);
        else printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
