#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int m,c;
        scanf("%d %d",&m,&c);

        vector<vector<long long> > v;

        for(int i=0; i<c; ++i){
            int k;
            vector<long long> temp;
            scanf("%d",&k);
            for(int j=0; j<k; ++j){
                int x;
                scanf("%d",&x);
                temp.push_back(x);
            }
            v.push_back(temp);
        }

        vector<long long> old=v[0];
        vector<long long> cur,tmp;
        for(int i=1; i<c; ++i){
            cur=v[i];
            bitset<205> visited;
            for(int j=0; j<cur.size(); ++j){
                long long y=cur[j];
                for(int k=0; k<old.size(); ++k){
                    long long z=old[k]+y;
                    if(z<=m and !visited[z]){
                        visited[z]=1;
                        tmp.push_back(z);
                    }
                }
            }
            old.clear();
            old=tmp;
            tmp.clear();
        }
        if(old.size()){
            long long mx=0;
            for(int i=0; i<old.size(); ++i){
                mx=max(mx,old[i]);
            }
            printf("%lld\n",mx);
        }
        else printf("no solution\n");
    }
    return 0;
}
