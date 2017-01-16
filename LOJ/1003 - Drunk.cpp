#include <bits/stdc++.h>
 
using namespace std;
 
map<string, vector<string> >::iterator it;
int flag=0;
 
void dfs(string s,map<string, vector<string> >& a,map<string, int>& color){
    vector<string> v=a[s];
    color[s]=1;
    vector<string>::iterator jt;
    for(jt=v.begin();jt!=v.end();jt++){
        string x=*jt;
        if(color[x]==0){
            dfs(x,a,color);
        }
        else if(color[x]==1){
            flag=1;
            return;
        }
    }
    color[s]=2;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int m;
        scanf("%d",&m);
        getchar();
        map<string, vector<string> > a;
        map<string, int> color;
        flag=0;
        for(int i=0;i<m;i++){
            string b,c;
            cin>>b>>c;
            a[c].push_back(b);
        }
        for(it=a.begin();it!=a.end();it++){
            string s=it->first;
            if(color[s]==0){
                dfs(s,a,color);
            }
        }
        printf("Case %d: ",t);
        flag?printf("No\n"):printf("Yes\n");
    }
    return 0;
}
