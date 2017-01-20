#include <bits/stdc++.h>

using namespace std;

long long n, m, k, x, y;

void print(long long a[][105], int x, int y){
    long long mx=0;
    long long mn=LLONG_MAX;
    long long ans;

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            mx=max(mx, a[i][j]);
            mn=min(mn, a[i][j]);

            if(i==x and j==y){
                ans=a[i][j];
            }
        }
    }

    cout<<mx<<" "<<mn<<" "<<ans<<endl;
}

int main()
{

//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);


    while(cin>>n>>m>>k>>x>>y){
        long long a[n][105]={0};

        /*for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cerr<<a[i][j]<<" ";
            }
            cerr<<endl;
        }*/

        if(n==1){
            long long q=k/m;
            long long r=k%m;

            for(int i=0; i<m; ++i){
                a[0][i]+=q;
            }

            for(int i=0; i<r; ++i){
                a[0][i]+=1;
            }

            print(a,x-1,y-1);
        }
        else{
            long long num=n*m+(n-2)*m;
            long long q=k/num;
            long long r=k%num;

            for(int i=0; i<n; ++i){
                for(int j=0; j<m; ++j){
                    if(i==0 or i==n-1){
                        a[i][j]+=q;
                    }
                    else{
                        a[i][j]+=2*q;
                    }
                }
            }

            for(int i=0; i<n; ++i){
                for(int j=0; j<m; ++j){
                    if(!r) break;
                    a[i][j]++;
                    --r;
                }
            }

            if(r){
                for(int i=n-2; i>0; --i){
                    for(int j=0; j<m; ++j){
                        if(!r) break;
                        a[i][j]++;
                        --r;
                    }
                }
            }
            print(a,x-1,y-1);

        }

    }

    return 0;
}
