#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
struct Tree{
    ll sum;
    ll prop;
};
 
 
const int mx=1e5+3;
Tree tree[mx*4];
 
void init(){
    int rng=mx*4;
    for(int i=0;i<rng;++i){
        tree[i].sum=tree[i].prop=0;
    }
}
 
void update(int node,int fa,int la,int i,int j,ll v){
    if(i>la || j<fa) return;
    else if(fa>=i && la<=j){
        tree[node].sum+=(la-fa+1)*v;
        tree[node].prop+=v;
        return;
    }
    int mid=(fa+la)>>1;
    int left=node<<1;
    int right=left|1;
    update(left,fa,mid,i,j,v);
    update(right,mid+1,la,i,j,v);
    tree[node].sum=tree[left].sum+tree[right].sum+(la-fa+1)*tree[node].prop;
}
 
ll query(int node,int fa,int la,int i,int j,ll carry=0){
    if(i>la || j<fa) return 0;
    else if(fa>=i && la<=j)
        return tree[node].sum+(la-fa+1)*carry;
    int mid=(fa+la)>>1;
    int left=node<<1;
    int right=left|1;
    ll p1=query(left,fa,mid,i,j,carry+tree[node].prop);
    ll p2=query(right,mid+1,la,i,j,carry+tree[node].prop);
    return p1+p2;
}
 
int main()
{
    //freopen("in.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t){
        int n,q;
        scanf("%d %d",&n,&q);
        init();
        printf("Case %d:\n",t);
        for(int i=0;i<q;i++){
            int type;
            scanf("%d",&type);
            if(!type){
                int x,y,v;
                scanf("%d %d %d",&x,&y,&v);
                update(1,1,n,x+1,y+1,v);
            }
            else{
                int x,y;
                scanf("%d %d",&x,&y);
                ll ans=query(1,1,n,x+1,y+1);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
