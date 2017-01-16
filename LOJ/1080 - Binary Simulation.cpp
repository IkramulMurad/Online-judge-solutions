#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=1e5+5;
int tree[mx*3];
int prop=0;
 
void init(){
    fill(tree,tree+(mx*3),0);
}
 
void update(int node,int f,int l,int i,int j){
    if(i>l||j<f) return;
    else if(f>=i && l<=j){
        tree[node]+=1;
        return;
    }
    int mid=(f+l)/2;
    int left=node*2;
    int right=left+1;
    update(left,f,mid,i,j);
    update(right,mid+1,l,i,j);
}
 
int query(int node,int f,int l,int i){
    if(i>l||i<f) return 0;
    else if(f>=i && l<=i){
        return prop+=tree[node];
    }
    prop+=tree[node];
    int mid=(f+l)/2;
    int left=node*2;
    int right=left+1;
    query(left,f,mid,i);
    query(right,mid+1,l,i);
    return prop;
}
 
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        string a;
        cin>>a;
        int len=a.length();
        init();
 
        printf("Case %d:\n",t);
        int q;
        scanf("%d",&q);
 
        for(int i=0;i<q;i++){
            char c;
            scanf(" %c",&c);
            if(c=='I'){
                int l,r;
                scanf("%d %d",&l,&r);
                update(1,1,len,l,r);
            }
            else{
                int x;
                scanf("%d",&x);
                prop=0;
                int bin=a[x-1]-'0',tog=query(1,1,len,x);
                int ans=bin^(tog&1);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
