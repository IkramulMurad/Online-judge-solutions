#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> II;
vector<pair<double,II>> v;
int n,m;
int p[505],r[505];

void init(){
    for(int i=0; i<505; ++i){
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

    if(x==y) return 0;

    if(r[y]>r[x]){
        p[x]=y;
        r[y]+=r[x];
    }
    else{
        p[y]=x;
        r[x]+=r[y];
    }

    return 1;
}

double kruskal(){
    init();

    double ans=0;
    int total=0;

    for(int i=0; i<v.size(); ++i){
        int s=v[i].second.first;
        int t=v[i].second.second;
        double w=v[i].first;

        if(join(s,t)){
            ans=w;
            total++;
            if(total==m-n) return ans;
        }
    }

    return ans;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--){
        cin>>n>>m;
        v.clear();

        int x[m],y[m];
        for(int i=0; i<m; ++i){
            cin>>x[i]>>y[i];
        }

        for(int i=0; i<m-1; ++i){
            for(int j=i+1; j<m; ++j){
                double cost=hypot(x[j]-x[i],y[j]-y[i]);
                v.push_back(make_pair(cost,make_pair(i,j)));
            }
        }

        sort(v.begin(),v.end());

        double ans=kruskal();
        printf("%0.2f\n",ans);
    }

    return 0;
}
