#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=1e5+3;
int a[mx];
int tree[mx*3];
int x;
 
void init(int node,int f,int l){
    if(f==l){
        tree[node]=a[f];
        return;
    }
    int mid=(f+l)/2;
    int left=node*2;
    int right=node*2+1;
    init(left,f,mid);
    init(right,mid+1,l);
    tree[node]=tree[left]+tree[right];
}
 
void update(int node,int f,int l,int i,int val){
    if(i<f||i>l) return;
    if(f>=i && l<=i){
        if(val==-1){
            x=tree[node];
            tree[node]=0;
        }
        else tree[node]+=val;
        return;
    }
    int mid=(f+l)/2;
    int left=node*2;
    int right=node*2+1;
    update(left,f,mid,i,val);
    update(right,mid+1,l,i,val);
    tree[node]=tree[left]+tree[right];
}
 
long long query(int node,int f,int l,int i,int j){
    if(i>l||j<f) return 0;
    if(i<=f && j>=l) return tree[node];
    int mid=(f+l)/2;
    int left=node*2;
    int right=node*2+1;
    long long p1=query(left,f,mid,i,j);
    long long p2=query(right,mid+1,l,i,j);
    return p1+p2;
}
 
int main()
{
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        int n,q;
        scanf("%d %d",&n,&q);
 
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        init(1,1,n);
 
        printf("Case %d:\n",tc);
        for(int i=0;i<q;i++){
            int type;
            scanf("%d",&type);
            if(type==1){
                int index;
                scanf("%d",&index);
                index++;
                update(1,1,n,index,-1);
                printf("%d\n",x);
            }
            else if(type==2){
                int index,val;
                scanf("%d %d",&index,&val);
                index++;
                update(1,1,n,index,val);
            }
            else{
                int l,r;
                scanf("%d %d",&l,&r);
                l++;r++;
                long long ans=query(1,1,n,l,r);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
