#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=22;
char g[mx][mx];
bool visited[mx][mx];
 
int height, width, cnt;
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
 
void bfs(int sx, int sy){
    visited[sx][sy]=1;
    vector<pair<int,int> >old,cur;
    old.push_back(make_pair(sx,sy));
    while(!old.empty()){
        ++cnt;
        for(int i=0; i<old.size(); ++i){
            for(int j=0; j<4; ++j){
                int ax=old[i].first+x[j];
                int ay=old[i].second+y[j];
                if(ax>=0 and ay>=0 and ax<height and ay<width and !visited[ax][ay]){
                    visited[ax][ay]=1;
                    if(g[ax][ay]=='h') return;
                    if(g[ax][ay]!='m' and g[ax][ay]!='#'){
                        cur.push_back(make_pair(ax,ay));
                    }
                }
            }
        }
        old.clear();
        old=cur;
        cur.clear();
    }
}
 
void clr(){
    for(int i=0; i<height; ++i){
        for(int j=0; j<width; ++j){
            visited[i][j]=0;
        }
    }
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        scanf("%d %d",&height,&width);
        getchar();
 
        pair<int,int> a,b,c;
        char ch;
        for(int i=0; i<height; ++i){
            for(int j=0; j<width; ++j){
               scanf("%c",&ch);
               g[i][j]=ch;
               if(ch=='a') a=make_pair(i,j);
               else if(ch=='b') b=make_pair(i,j);
               else if(ch=='c') c=make_pair(i,j);
            }
            getchar();
        }
 
        int ans=0;
 
        clr();
        cnt=0;
        bfs(a.first,a.second);
        ans=max(ans,cnt);
 
        clr();
        cnt=0;
        bfs(b.first,b.second);
        ans=max(ans,cnt);
 
        clr();
        cnt=0;
        bfs(c.first,c.second);
        ans=max(ans,cnt);
 
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
