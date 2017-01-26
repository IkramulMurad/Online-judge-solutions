/* Idea of a chinese programmar */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    int a[k];
    int segment=(m*n)/k;
    int finalSegment=(m*n)-((k-1)*segment);

    for(int i=0; i<k-1; ++i) a[i]=segment;
    a[k-1]=finalSegment;


    int x=1, y=1, incDec=1;
    for(int i=0; i<k; ++i){
        cout<<a[i];
        for(int j=0; j<a[i]; ++j){
            cout<<" "<<x<<" "<<y;
            y+=incDec;

            if(y>m or y<=0){
                ++x;
                incDec=-incDec; //always 1 and -1
                y+=incDec;
            }
        }
        cout<<endl;
    }

    return 0;
}



/* My idea */

#include <bits/stdc++.h>

using namespace std;

int visited[305][305];

void print_rest_row(int nextRow, int h, int w){
    for(int i=nextRow; i<h; ++i){
        for(int j=0; j<w; ++j){
            if(!visited[i][j]) cout<<" "<<i+1<<" "<<j+1;
        }
        ++i;
        if(i<h){
            for(int j=w-1; j>=0; --j){
                if(!visited[i][j]) cout<<" "<<i+1<<" "<<j+1;
            }
        }
    }
}

void solve_row(int h, int w, int k){
    int nextRow,nextColumn;
    nextRow=nextColumn=0;
    for(int i=1; i<k; ++i){
        cout<<2;
        cout<<" "<<1+nextRow<<" "<<1+nextColumn++;
        cout<<" "<<1+nextRow<<" "<<1+nextColumn++;
        visited[nextRow][nextColumn-1]=1;
        visited[nextRow][nextColumn-2]=1;
        if(nextColumn==w){
            nextRow++;
            nextColumn=0;
        }
        cout<<endl;
    }

    int ans=(h*w)-(nextRow*w+nextColumn);
    if(ans){
        cout<<ans;
        print_rest_row(nextRow,h,w);
    }

}

void print_rest_column(int nextColumn, int h, int w){
    for(int i=nextColumn; i<w; ++i){
        for(int j=0; j<h; ++j){
            if(!visited[j][i]) cout<<" "<<j+1<<" "<<i+1;
        }
        ++i;
        if(i<w){
            for(int j=h-1; j>=0; --j){
                if(!visited[j][i]) cout<<" "<<j+1<<" "<<i+1;
            }
        }
    }
}

void solve_column(int h, int w, int k){
    int nextRow,nextColumn;
    nextRow=nextColumn=0;
    for(int i=1; i<k; ++i){
        cout<<2;
        cout<<" "<<1+nextRow++<<" "<<1+nextColumn;
        cout<<" "<<1+nextRow++<<" "<<1+nextColumn;
        visited[nextRow-1][nextColumn]=1;
        visited[nextRow-2][nextColumn]=1;
        if(nextRow==h){
            nextRow=0;
            nextColumn++;
        }
        cout<<endl;
    }

    int ans=(h*w)-(nextColumn*h+nextRow);
    if(ans){
        cout<<ans;
        print_rest_column(nextColumn,h,w);
    }

}

void solve(int h, int w, int k){
    int nextColumn,nextRow;
    nextColumn=nextRow=0;

    if(k==1){
        int ans=(h*w)-(nextRow*w+nextColumn);
        cout<<ans;
        print_rest_row(nextRow,h,w);
    }
    else{
        int kount=1;
        cout<<3;
        cout<<" "<<1+nextRow++<<" "<<1+nextColumn;
        cout<<" "<<1+nextRow++<<" "<<1+nextColumn;
        cout<<" "<<1+nextRow++<<" "<<1+nextColumn;
        cout<<endl;
        visited[nextRow-1][nextColumn]=1;
        visited[nextRow-2][nextColumn]=1;
        visited[nextRow-3][nextColumn]=1;
        ++kount;

        int rng=(h-3)/2+kount;

        for(int i=kount; i<min(rng,k); ++i){
            cout<<2;
            cout<<" "<<1+nextRow++<<" "<<1+nextColumn;
            cout<<" "<<1+nextRow++<<" "<<1+nextColumn;
            cout<<endl;

            visited[nextRow-1][nextColumn]=1;
            visited[nextRow-2][nextColumn]=1;
            ++kount;
        }

        if(nextRow!=h){
            int ans=(h*w)-(nextColumn*h+nextRow);
            cout<<ans;
            print_rest_column(nextColumn,h,w);
        }
        else if(nextRow==h){
            //flag=true;
            nextColumn++;
            nextRow=0;

            for(int i=kount; i<k; ++i){
                cout<<2;
                cout<<" "<<1+nextRow<<" "<<1+nextColumn++;
                cout<<" "<<1+nextRow<<" "<<1+nextColumn++;
                visited[nextRow][nextColumn-1]=1;
                visited[nextRow][nextColumn-2]=1;
                if(nextColumn==w){
                    nextRow++;
                    nextColumn=1;
                }
                cout<<endl;
            }

            int ans=(h*w)-(h+nextRow*(w-1)+nextColumn-1);
            if(ans){
                cout<<ans;
                print_rest_row(nextRow,h,w);
            }
        }

    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    if((m&1)==0){
        solve_row(n,m,k);
    }
    else if((n&1)==0){
        solve_column(n,m,k);
    }
    else{
        solve(n,m,k);
    }

    return 0;
}
