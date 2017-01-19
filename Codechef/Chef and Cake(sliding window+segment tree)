#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int mod=1e9+7;

LL eqn(LL a, LL x, LL b, LL c, LL m){
    LL ans=(a*((x*x)%m))%m;
    ans=(ans+(b*x)%m)%m;
    ans=(ans+c)%m;

    return ans;
}

void generate(int ar[], int n){
    LL a,b,c,d,e,f,r,s,t,m,val;
    cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>ar[0];

    val=t;

    for(int i=1; i<n; ++i){
        val=(val*t)%s;
        if(val<=r){
            ar[i]=eqn(a,ar[i-1],b,c,m);
        }
        else{
            ar[i]=eqn(d,ar[i-1],e,f,m);
        }
    }

    /*for(int i=0; i<n; ++i){
        cerr<<ar[i]<<" ";
    }
    cerr<<endl;*/

}

void getPairs(vector<pair<int,int> > &p, int q, int n, int k){
    LL L1,la,lc,lm,D1,da,dc,dm;
    cin>>L1>>la>>lc>>lm>>D1>>da>>dc>>dm;

    for(int i=0; i<q; ++i){
        L1=(((la*L1)%lm)+lc)%lm;
        D1=(((da*D1)%dm)+dc)%dm;
        int l=L1+1;
        int r=min(LL(l+k-1+D1),LL(n));
        p[i].first=l;
        p[i].second=r;
    }

    /*for(int i=0; i<q; ++i){
        cerr<<p[i].first<<" "<<p[i].second<<endl;
    }*/
}


void sliding_window(int mn[], int q, int k, int n, int a[], vector<pair<int,int> > &p){
    deque<int> dq;
    for(int i=0; i<k; ++i){
        while(!dq.empty() and a[i]<=a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    int idx=0;
    for(int i=k; i<n; ++i){
        mn[idx++]=a[dq.front()];

        while(!dq.empty() and dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() and a[i]<=a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    mn[idx++]=a[dq.front()];
//    for(int i=0; i<idx; ++i){
//        cerr<<mn[i]<<" ";
//    }
//    cerr<<endl;

    //result processing
    LL sum,prod;
    sum=0;
    prod=1;
    for(int i=0; i<q; ++i){
        int l=p[i].first-1;
        int r=p[i].second;
        r-=k;
        r=max(l,r);

        int m=min(mn[l],mn[r]);
        sum+=m;
        prod=(prod*m)%mod;
    }

    cout<<sum<<" "<<prod<<endl;

}


void build(int tree[], int a[], int node, int lo, int hi){
    if(lo==hi){
        tree[node]=a[lo-1];
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(hi+lo)>>1;

    build(tree, a, left, lo, mid);
    build(tree, a, right, mid+1, hi);

    tree[node]=min(tree[left], tree[right]);
}

int query(int tree[], int a[], int node, int lo, int hi, int l, int r){
    if(l>hi or r<lo) return 2e9;
    if(l<=lo and r>=hi) return tree[node];

    int left=node<<1;
    int right=left+1;
    int mid=(hi+lo)>>1;

    int p1=query(tree, a, left, lo, mid, l, r);
    int p2=query(tree, a, right, mid+1, hi, l, r);

    return min(p1, p2);
}

void segment_tree(int q, int k, int n, int a[], vector<pair<int, int> > &p){
    int rng=(1<<(int)(ceil(log2(n))+1))+5;
    //cerr<<rng<<endl;

    int tree[rng];
    build(tree,a,1,1,n);
//    for(int i=0; i<rng; ++i){
//        cerr<<tree[i]<<" ";
//    }
    //result processing
    LL sum,prod;
    sum=0;
    prod=1;
    for(int i=0; i<q; ++i){
        int l=p[i].first;
        int r=p[i].second;

        int m=query(tree,a,1,1,n,l,r);
        sum+=m;
        prod=(prod*m)%mod;
    }

    printf("%lld %lld\n",sum,prod);

}

void solve(int a[], vector<pair<int, int> > &p, int n, int k, int q){
    //make min array, sliding window part

    int mn[n];

    if(n>=(LL)1e6) sliding_window(mn,q,k,n,a,p);
    else segment_tree(q,k,n,a,p);

}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);


    int n,q,k;
    while(~scanf("%d %d %d",&n,&k,&q)){
        int a[n];
        generate(a,n);

        vector<pair<int,int> >p(q);
        getPairs(p,q,n,k);

        solve(a,p,n,k,q);
    }

    return 0;
}
