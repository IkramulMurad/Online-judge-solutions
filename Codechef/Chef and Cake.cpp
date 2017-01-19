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

void sliding_window(int a[], vector<pair<int, int> > &p, int n, int k, int q){
    //make min array, sliding window part
    deque<int> dq;
    int mn[n];
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
    /*for(int i=0; i<idx; ++i){
        cerr<<mn[i]<<" ";
    }
    cerr<<endl;*/

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

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q,k;
    while(cin>>n>>k>>q){
        int a[n];
        generate(a,n);

        vector<pair<int,int> >p(q);
        getPairs(p,q,n,k);

        sliding_window(a,p,n,k,q);
    }

    return 0;
}
