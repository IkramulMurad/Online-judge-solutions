#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> II;

const int mx=1e4+5;
int n,m,off;
int p[105],r[105];
vector<pair<int,II> > v;
bitset<mx> inMst,inFirstMst;

void init(){
    for(int i=0; i<105; ++i){
        p[i]=i;
        r[i]=1;
    }
    inMst.reset();
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

int kruskal(){
    init();

    int ans=0;
    int total=0;

    for(int i=0; i<v.size(); ++i){
        int s=v[i].second.first;
        int t=v[i].second.second;
        int w=v[i].first;
        if(i!=off and join(s,t)){
            ans+=w;
            total++;
            inMst[i]=1;

            if(total==n-1) return ans;
        }
    }
    if(total<n-1) return -1;
    return ans;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--){
        v.clear();

        cin>>n>>m;
        for(int i=0; i<m; ++i){
            int s,t,w;
            cin>>s>>t>>w;

            v.push_back(make_pair(w,make_pair(s,t)));
        }

        sort(v.begin(),v.end());

        off=2e9;
        int ans1=kruskal();
        int ans2=2e9;

        inFirstMst=inMst;

        for(int i=0; i<v.size(); ++i){
            if(inFirstMst[i]){
                off=i;
                int step=kruskal();
                if(step!=-1){
                    ans2=min(ans2,kruskal());
                }
            }
        }

        cout<<ans1<<" "<<ans2<<endl;
    }

    return 0;
}
