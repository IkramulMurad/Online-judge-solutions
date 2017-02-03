#include <bits/stdc++.h>

using namespace std;

vector<int> v,seq,teq;
map<int,int> mp;

void solve(){
    //make sequence of each operation
    map<int,int> tp;
    for(int i=0; i<v.size(); ++i){
        tp[v[i]]=i+1;
    }

    teq.clear();
    for(auto it=tp.begin(); it!=tp.end(); ++it){
        teq.push_back(it->second);
    }

    //lcs
    int n=seq.size(), m=teq.size();
    int lcs[n+1][m+1];

    for(int i=0; i<=n; ++i) lcs[i][0]=0;
    for(int i=0; i<=m; ++i) lcs[0][i]=0;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(seq[i-1]==teq[j-1]){
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else{
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }

    cout<<lcs[n][m]<<endl;
}

int main()
{
    int n;
    string s;
    while(getline(cin,s)){
        stringstream ss(s);

        if(s.size()<3){
            //get n
            mp.clear();
            seq.clear();
            ss>>n;

            //get correct sequence
            getline(cin,s);
            stringstream sss(s);
            int x,idx=0;
            while(sss>>x){
                mp[x]=++idx;
            }
            for(auto it=mp.begin(); it!=mp.end(); ++it){
                seq.push_back(it->second);
            }
        }
        else{
            //operations
            v.clear();
            int x;
            while(ss>>x) v.push_back(x);
            solve();
        }

    }

    return 0;
}
