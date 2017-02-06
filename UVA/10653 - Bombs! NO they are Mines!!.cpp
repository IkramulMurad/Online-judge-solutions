#include <bits/stdc++.h>

using namespace std;

char g[1234][1234];
bool visited[1234][1234];

int sx,sy,tx,ty;
int r,c;

int x[]={1,-1,0,0};
int y[]={0,0,1,-1};

void filling(){
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            g[i][j]='.';
            visited[i][j]=false;
        }
    }
}

bool valid(int ax, int ay){
    if(ax<0 or ay<0 or ax>=r or ay>=c) return false;
    if(visited[ax][ay] or g[ax][ay]=='*') return false;
    return true;
}

int bfs(){
    queue<pair<pair<int,int> , int> > q;
    q.push(make_pair(make_pair(sx,sy),0));

    visited[sx][sy]=1;

    while(!q.empty()){
        int nx=q.front().first.first;
        int ny=q.front().first.second;
        int val=q.front().second;

        if(nx==tx and ny==ty) return val;

        q.pop();

        for(int i=0; i<4; ++i){
            if(valid(nx+x[i],ny+y[i])){
                visited[nx+x[i]][ny+y[i]]=1;
                q.push(make_pair(make_pair(nx+x[i],ny+y[i]),val+1));
            }
        }
    }

    return 1; //for safety
}

int main()
{

    while(cin>>r>>c and (r or c)){
        filling();

        int n;
        cin>>n;
        for(int i=0; i<n; ++i){
            int row,bombs;
            cin>>row>>bombs;

            for(int i=0; i<bombs; ++i){
                int pos;
                cin>>pos;

                g[row][pos]='*';
            }
        }

        cin>>sx>>sy>>tx>>ty;

        cout<<bfs()<<endl;

    }
    return 0;
}
