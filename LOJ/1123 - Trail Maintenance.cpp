#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int> II;
vector<pair<int,II> > v;
const int mx=205;
int n,m;
int p[mx],r[mx];
 
void init(){
    for(int i=0; i<mx; ++i){
        p[i]=i;
        r[i]=1;
    }
}
 
int find(int n){
    if(p[n]==n) return n;
    return p[n]=find(p[n]);
}
 
bool join(int u, int v){
    int x=find(u);
    int y=find(v);
 
    if(x!=y){
        if(r[y]>r[x]){
            r[y]+=r[x];
            p[x]=y;
        }
        else{
            r[x]+=r[y];
            p[y]=x;
        }
        return 1;
    }
 
    return 0;
}
 
int kruskal(){
    init();
    vector<pair<int,II> > mst;
    sort(v.begin(),v.end());
 
    int ans=0;
    int kount=0;
 
    for(int i=0; i<v.size(); ++i){
        int s=v[i].second.first;
        int t=v[i].second.second;
        int w=v[i].first;
 
        if(join(s,t)){
            ++kount;
            ans+=w;
            mst.push_back(v[i]);
 
            if(kount==n-1) break;
        }
    }
    v.clear();
    v=mst;
    if(kount==n-1) return ans;
    return -1;
}
 
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
 
    int tc;
    scanf("%d",&tc);
 
    for(int t=1; t<=tc; ++t){
        v.clear();
 
        scanf("%d %d",&n,&m);
        printf("Case %d:\n",t);
        for(int i=0; i<m; ++i){
            int s,t,w;
            scanf("%d %d %d",&s,&t,&w);
 
            v.push_back(make_pair(w,make_pair(s,t)));
            int ans=kruskal();
            printf("%d\n",ans);
        }
    }
 
    return 0;
}
