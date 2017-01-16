#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=1e5+3;
int a[mx];
int tree[mx*3];
 
void init(int node,int first,int last){
    if(first==last){
        tree[node]=a[first];
        return;
    }
    int mid=(first+last)/2;
    int left=node*2;
    int right=node*2+1;
    init(left,first,mid);
    init(right,mid+1,last);
    tree[node]=min(tree[left],tree[right]);
}
 
int query(int node,int first,int last,int l,int r){
    if(first>r||last<l) return mx;
    if(first>=l and last<=r) return tree[node];
    int mid=(first+last)/2;
    int left=node*2;
    int right=node*2+1;
    int p1=query(left,first,mid,l,r);
    int p2=query(right,mid+1,last,l,r);
    return min(p1,p2);
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
            int l,r;
            scanf("%d %d",&l,&r);
            int ans=query(1,1,n,l,r);
            printf("%d\n",ans);
        }
    }
    return 0;
}
