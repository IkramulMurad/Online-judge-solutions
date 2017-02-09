#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> II;
vector<pair<int,II> > v;
const int mx=56;
int n;
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
    u=find(u);
    v=find(v);

    if(u!=v){
        if(r[v]>r[u]){
            r[v]+=r[u];
            p[u]=v;
        }
        else{
            r[u]+=r[v];
            p[v]=u;
        }
        return 1;
    }

    return 0;
}

int kruskal(){
    init();
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

            if(kount==n-1) break;
        }
    }

    if(kount==n-1) return ans;
    return -1;
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int t=1; t<=tc; ++t){
        scanf("%d",&n);
        v.clear();

        int sum=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                int x;
                scanf("%d",&x);

                sum+=x;

                if(x>0) v.push_back(make_pair(x,make_pair(i,j)));
            }
        }

        int mst=kruskal();
        printf("Case %d: ",t);
        if(mst==-1) printf("-1\n");
        else printf("%d\n",sum-mst);
    }

    return 0;
}
