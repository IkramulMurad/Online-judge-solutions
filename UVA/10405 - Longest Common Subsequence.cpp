#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(stl) for(auto i=stl.begin();i!=stl.end();i++)
#define ll long long
#define ld long double
#define pi pair<int,int>
#define srt(vec) sort( vec.begin(), vec.end() )
#define cin_i(x) scanf("%d",&x)
#define cin_l(x) scanf("%ll",&x)

using namespace std;
int lcs(char* s1,char* s2,int l1,int l2)
{
    int a[l1+1][l2+1];
    for(int i=0; i<=l1; i++)
    {
        for(int j=0; j<=l2; j++)
        {
            if(i==0||j==0) a[i][j]=0;
            else if(s1[i-1]==s2[j-1]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    }
    return a[l1][l2];
}
int main()
{
    char s1[1002],s2[1002];
    while(gets(s1)&&gets(s2))
    {
        int l1=strlen(s1),l2=strlen(s2);
        cout<<lcs(s1,s2,l1,l2)<<endl;
    }
    return 0;
}
