#include <bits/stdc++.h>
 
using namespace std;
 
const int mx=27;
const int inf=1e9;
int ans;
bool visited[mx][mx][mx];
int x[]={0,0,0,0,1,-1};
int y[]={0,0,1,-1,0,0};
int z[]={1,-1,0,0,0,0};
 
void clr(){
    for(int i=0; i<mx; ++i){
        for(int j=0; j<mx; ++j){
            for(int k=0; k<mx; ++k){
                visited[i][j][k]=0;
            }
        }
    }
}
 
void make(char a, char b, char c, string& s){
    s.push_back(a);
    s.push_back(b);
    s.push_back(c);
}
 
void bfs(string s, string t){
    if(visited[s[0]-'a'][s[1]-'a'][s[2]-'a']) return;
    if(visited[t[0]-'a'][t[1]-'a'][t[2]-'a']) return;
    visited[s[0]-'a'][s[1]-'a'][s[2]-'a']=1;
    queue<string> qs;
    queue<int> qv;
    qs.push(s); qv.push(0);
 
    while(!qs.empty()){
        string a=qs.front();
        int val=qv.front();
        qs.pop(); qv.pop();
 
        if(a==t){
            ans=val;
            return;
        }
 
        //all 6 nodes
        char m,n,o;
        for(int i=0; i<6; ++i){
            m=(a[0]-'a'+x[i]+26)%26+'a';
            n=(a[1]-'a'+y[i]+26)%26+'a';
            o=(a[2]-'a'+z[i]+26)%26+'a';
            if(!visited[m-'a'][n-'a'][o-'a']){
                visited[m-'a'][n-'a'][o-'a']=1;
                string b;
                make(m,n,o,b);
                qs.push(b);
                qv.push(val+1);
            }
        }
 
    }
}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; ++t){
        string u,v;
        cin>>u>>v;
        int n;
        scanf("%d",&n);
 
        clr();
        for(int i=0; i<n; ++i){
            string a,b,c;
            cin>>a>>b>>c;
            for(int j=0; j<a.size(); ++j){
                for(int k=0; k<b.size(); ++k){
                    for(int l=0; l<c.size(); ++l){
                        int idx=a[j]-'a', idy=b[k]-'a', idz=c[l]-'a';
                        visited[idx][idy][idz]=1;
                    }
                }
            }
        }
        ans=inf;
        bfs(u,v);
 
        printf("Case %d: ",t);
        ans==inf? printf("-1\n"): printf("%d\n",ans);
    }
    return 0;
}
