#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    #else
    //online submission
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row,col;
    cin>>row>>col;

    char a[row+1][col+1];
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>a[i][j];

    int r[row][col],c[row][col];
    //fill row
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(j==0) r[i][j]=0;
            else{
                r[i][j]=r[i][j-1]+(a[i][j-1]=='.' && a[i][j]=='.');
            }
        }
    }
    //fill col
    for(int j=0;j<col;j++){
        for(int i=0;i<row;i++){
            if(i==0) c[i][j]=0;
            else{
                c[i][j]=c[i-1][j]+(a[i-1][j]=='.' && a[i][j]=='.');
            }
        }
    }

    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        long long ans=0;
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--;r2--;c1--;c2--;
        for(int j=r1;j<=r2;j++){
            ans+=r[j][c2]-r[j][c1];
        }
        for(int j=c1; j<=c2; j++){
            ans+=c[r2][j]-c[r1][j];
        }
        cout<<ans<<endl;
    }
    return 0;
}
