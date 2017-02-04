#include <bits/stdc++.h>

using namespace std;

class Elephant{
public:
    int w;
    int iq;
    int pos;

    Elephant(int x, int y, int z){
        w=x;
        iq=y;
        pos=z;
    }

    bool operator<(const Elephant& b){
        if(w==b.w)
            if(iq==b.iq)
                return pos<b.pos;
            else return iq<b.iq;
        else return w<b.w;
    }

    bool operator>(const Elephant& b){
        if(w>b.w and iq<b.iq) return true;
        return false;
    }
};

vector<Elephant> v;

int main()
{
    //freopen("in.txt","r",stdin);
    int ix=1, w, iq;
    while(cin>>w>>iq){
        Elephant e(w,iq,ix++);
        v.push_back(e);
    }

    sort(v.begin(), v.end());

    /*for(int i=0; i<v.size(); ++i){
        cerr<<v[i].w<<" "<<v[i].iq<<" "<<v[i].pos<<endl;
    }*/

    int n=v.size();
    int lis[n],parent[n];

    fill(lis,lis+n,1);
    for(int i=0; i<n; ++i) parent[i]=i;

    for(int i=1; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(v[i]>v[j]){
                if(lis[i]<1+lis[j]){
                    lis[i]=1+lis[j];
                    parent[i]=j;
                }
            }
        }
    }

    int ans=0;
    int idx=0;
    for(int i=0; i<n; ++i){
        if(lis[i]>ans){
            ans=lis[i];
            idx=i;
        }
    }

    vector<int> path;
    while(true){
        path.push_back(v[idx].pos);
        if(parent[idx]==idx) break;
        idx=parent[idx];
    }

    cout<<ans<<endl;
    for(int i=path.size()-1; i>=0; --i){
        cout<<path[i]<<endl;
    }

    return 0;
}
