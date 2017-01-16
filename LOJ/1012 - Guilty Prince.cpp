#include <bits/stdc++.h>
 
using namespace std;
 
int r,c,kount;
char a[21][21];
int visited[21][21];
 
void dfs(int x,int y){
    if(x+1<r and !visited[x+1][y] and a[x+1][y] == '.'){
        kount++;
        visited[x+1][y]=1;
        dfs(x+1,y);
    }
    if(x-1>=0 and !visited[x-1][y] and a[x-1][y] == '.'){
        kount++;
        visited[x-1][y]=1;
        dfs(x-1,y);
    }
    if(y+1<c and !visited[x][y+1] and a[x][y+1] == '.'){
        kount++;
        visited[x][y+1]=1;
        dfs(x,y+1);
    }
    if(y-1>=0 and !visited[x][y-1] and a[x][y-1] == '.'){
        kount++;
        visited[x][y-1]=1;
        dfs(x,y-1);
    }
}
 
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        kount=1;
        int sx,sy,col,row;
 
        scanf("%d %d",&col,&row);
        getchar();
        c=col,r=row;
 
        for(int j=0;j<row;j++){
            for(int k=0;k<col;k++){
                cin>>a[j][k];
                if(a[j][k]=='@'){
                    sx=j;sy=k;
                    visited[sx][sy]=1;
                }
            }
        }
 
        memset(visited, 0, sizeof(visited));
        dfs(sx,sy);
 
        printf("Case %d: %d\n",i,kount);
    }
    return 0;
}
