#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> II;

const int mx=105;
int n,m;
int off;
int p[mx],r[mx];
vector<pair<int,II> > v;
vector<int> trees;
bitset<205> inMst,inMstFirst;

void clr(){
    v.clear();
}

void scanGraph(){
    cin>>n>>m;
    for(int i=0; i<m; ++i){
        int s,t,w;
        cin>>s>>t>>w;

        v.push_back(make_pair(w,make_pair(s,t)));
    }
}

void init(){
    for(int i=0; i<mx; ++i){
        p[i]=i;
        r[i]=1;
    }
    inMst.reset();
}

int find(int n){
    if(p[n]==n) return n;
    return p[n]=find(p[n]);
}

int join(int u, int v){
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

    int cost=0;
    int total=0;
    for(int i=0; i<v.size(); ++i){
        int s=v[i].second.first;
        int t=v[i].second.second;
        int w=v[i].first;

        if(i!=off and join(s,t)){
            cost+=w;
            total++;
            inMst[i]=1;
        }
    }

    if(total<n-1) return -1;
    return cost;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; ++t){
        //clear graph
        clr();

        //scanning graph
        scanGraph();

        //process
        sort(v.begin(),v.end());

        printf("Case #%d : ",t);

        off=2e9;
        int x=kruskal();
        inMstFirst=inMst;

        if(x==-1){
            cout<<"No way"<<endl;
            continue;
        }

        int ans=2e9;
        for(int i=0; i<m; ++i){
            if(inMstFirst[i]){
                off=i;
                int step=kruskal();
                if(step!=-1){
                    ans=min(ans,step);
                }
            }
        }

        if(ans==2e9) cout<<"No second way"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}
