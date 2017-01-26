#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //scanning
    int n;
    cin>>n;

    LL a[n][n], da[n][n], db[n][n], d[n][n];
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin>>a[i][j];
        }
    }

    //diagonal process a
    for(int i=0; i<n; ++i){
        int x=i, y=0;
        LL sum=0;
        while(x<n){
            sum+=a[x++][y++];
        }
        x=i; y=0;
        while(x<n){
            da[x++][y++]=sum;
        }
    }

    for(int i=1; i<n; ++i){
        int x=0, y=i;
        LL sum=0;
        while(y<n){
            sum+=a[x++][y++];
        }
        x=0; y=i;
        while(y<n){
            da[x++][y++]=sum;
        }
    }

    //diagonal process b
    for(int i=0; i<n; ++i){
        int x=i, y=0;
        LL sum=0;
        while(x>=0){
            sum+=a[x--][y++];
        }

        x=i; y=0;
        while(x>=0){
            db[x--][y++]=sum;
        }
    }

    for(int i=1; i<n; ++i){
        int x=n-1, y=i;
        LL sum=0;
        while(y<n){
            sum+=a[x--][y++];
        }
        x=n-1; y=i;
        while(y<n){
            db[x--][y++]=sum;
        }
    }

    //calculate whole table
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            d[i][j]=da[i][j]+db[i][j]-a[i][j];
        }
    }

    //find out maxA and maxB and get result
    int f=0;
    LL mxa=0, mxb=0, mx;
    int xa,ya,xb,yb;

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            f^=1;
            if(f){
                if(d[i][j]>=mxa){
                    mxa=d[i][j];
                    xa=i+1; ya=j+1;
                }
            }
            else{
                if(d[i][j]>=mxb){
                    mxb=d[i][j];
                    xb=i+1; yb=j+1;
                }
            }
        }
        if(!(n&1)) f^=1;
    }


    mx=mxa+mxb;
    cout<<mx<<endl;
    cout<<xa<<" "<<ya<<" "<<xb<<" "<<yb;

    return 0;
}
