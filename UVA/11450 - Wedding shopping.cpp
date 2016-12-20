#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        int m,c;
        scanf("%d %d",&m,&c);

        vector<vector<int> > v;

        for(int i=0; i<c; ++i){
            int k;
            vector<int> temp;
            scanf("%d",&k);
            for(int j=0; j<k; ++j){
                int x;
                scanf("%d",&x);
                temp.push_back(x);
            }
            v.push_back(temp);
        }

        vector<int> old=v[0];
        vector<int> cur,tmp;
        for(int i=1; i<c; ++i){
            cur=v[i];
            bitset<205> visited;
            for(int j=0; j<cur.size(); ++j){
                int y=cur[j];
                for(int k=0; k<old.size(); ++k){
                    int z=old[k]+y;
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
            int mx=0;
            for(int i=0; i<old.size(); ++i){
                mx=max(mx,old[i]);
            }
            printf("%d\n",mx);
        }
        else printf("no solution\n");
    }
    return 0;
}
