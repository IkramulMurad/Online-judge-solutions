#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL a[12][123], dp[12][123];
LL n,m;
vector<LL> path;

void scan(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin>>a[i][j];
        }
    }
}

LL min(LL a, LL b, LL c){
    return min(min(a,b),c);
}

int nextI(int i){
    return (i+1)%n;
}
int prevI(int i){
    return (i-1+n)%n;
}

void findPath(int i, int j){
    if(j>=m) return;
    path.push_back(i+1);

    int nxt[3];
    nxt[0]=nextI(i); nxt[1]=i; nxt[2]=prevI(i);
    sort(nxt,nxt+3);

    if(dp[i][j]-a[i][j]==dp[nxt[0]][j+1]){
        findPath(nxt[0],j+1);
    }
    else if(dp[i][j]-a[i][j]==dp[nxt[1]][j+1]){
        findPath(nxt[1],j+1);
    }
    else if(dp[i][j]-a[i][j]==dp[nxt[2]][j+1]){
        findPath(nxt[2],j+1);
    }
}

LL minPath(int i, int j){
    if(j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    return dp[i][j]=a[i][j]+min(minPath(nextI(i),j+1),
                                minPath(i,j+1),
                                minPath(prevI(i),j+1));
}

void solve(){
    scan();

    memset(dp,-1,sizeof dp);

    LL ans=2e17;
    int idx=0;
    for(int i=0; i<n; ++i){
        LL tmp=minPath(i,0);
        if(ans>tmp){
            ans=tmp;
            idx=i;
        }
    }

    path.clear();
    findPath(idx,0);

    for(int i=0; i<path.size(); ++i){
        if(i) cout<<" ";
        cout<<path[i];
    }
    cout<<endl;
    cout<<ans<<endl;
}

int main()
{
    while(cin>>n>>m){
        solve();
    }

    return 0;
}
