#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > index;

bool isPalindrome(string s, int mid){
    bool flag=true;
    int last=s.length()-1;
    for(int i=0; i<mid; ++i){
        if(s[i]!=s[last-i]){
            flag=false;
            index.push_back(make_pair(i,last-i));
        }
    }
    return flag;
}

int getCost(char a, char b){
    int apos=a-'a'+1;
    int bpos=b-'a'+1;

    int x=abs(apos-bpos);
    int y=26-max(apos,bpos)+min(apos,bpos);

    return min(x,y);
}

int cal(string s){
    int cost=0;
    for(int i=0; i<index.size(); ++i){
        int f=index[i].first, l=index[i].second;
        cost+=getCost(s[f],s[l]);
    }
    return cost;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int n,p;
    string s;
    cin>>n>>p>>s;

    int mid=s.length()/2;

    if(isPalindrome(s,mid)){
        cout<<0;
    }
    else{
        int ans,upDownCost, leftRightCost;
        upDownCost=cal(s);

        int s=0, e=index.size()-1;
        --p;
        if(p<mid){
            if(index[e].first<=p){
                leftRightCost=p-index[s].first;
            }
            else if(index[s].first>=p){
                leftRightCost=index[e].first-p;
            }
            else{
                int mn=min(p-index[s].first, index[e].first-p);
                int mx=max(p-index[s].first, index[e].first-p);

                leftRightCost=2*mn+mx;
            }
        }
        else{
            if(index[s].second<=p){
                leftRightCost=p-index[e].second;
            }
            else if(index[e].second>=p){
                leftRightCost=index[s].second-p;
            }
            else{
                int mn=min(p-index[e].second, index[s].second-p);
                int mx=max(p-index[e].second, index[s].second-p);

                leftRightCost=2*mn+mx;
            }
        }

        ans=upDownCost+leftRightCost;
        cout<<ans;
    }

    return 0;
}
