#include <bits/stdc++.h>
 
using namespace std;
 
int n,m;
string s[1005];
 
bool process_brick(int x,int y){
    if(x+1<n and s[x+1][y]=='A') return true;
    return false;
}
 
bool process_water(int x,int y){
    if(x-1>=0 and s[x-1][y]=='B') return true;
    if(x+1<n and s[x+1][y]=='A') return true;
    if(y+1>=m) return true;
    if(y-1<0) return true;
    return false;
}
 
bool process_air(int x,int y){
    if(x-1>=0 and s[x-1][y]=='B') return true;
    if(y+1<m and s[x][y+1]=='W') return true;
    if(y-1>=0 and s[x][y-1]=='W') return true;
    return false;
}
 
bool process(int i, int j, char c){
    if(c=='B') return process_brick(i,j);
    if(c=='W') return process_water(i,j);
    if(c=='A') return process_air(i,j);
}
 
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0; i<n; ++i) cin>>s[i];
 
        bool flag=false;
 
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(process(i,j,s[i][j])){
                    flag=true;
                }
            }
        }
        if(flag) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}
