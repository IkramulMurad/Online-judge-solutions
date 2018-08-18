#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("in.txt", "r", stdin);

    int n, q;
    while(~scanf("%d %d", &n, &q) and (n or q)){
        int x[n], y[n];
        for(int i = 0; i < n; ++i){
            scanf("%d %d", &x[i], &y[i]);
        }

        vector < vector <double> > v(n);
        for(int i = 0; i < n; ++i){
            v[i].push_back(0.0);
            for(int j = i + 1; j < n; ++j){
                double dist = hypot(x[i] - x[j], y[i] - y[j]);
                //cout << dist << " ";
                v[i].push_back(dist);
                v[j].push_back(dist);
            }
            //cout << endl;
        }

        for(int i = 0; i < n; ++i){
            sort(v[i].begin(), v[i].end());
            //for(int j = 0; j < n; ++j) cout << v[i][j] << " "; cout << endl;
        }

        for(int i = 0; i < q; ++i){
            int r, total = 0;
            scanf("%d", &r);

            for(int j = 0; j < n; ++j){
                total += upper_bound(v[j].begin(), v[j].end(), double(r)) - v[j].begin();
            }

            printf("%.2f\n", double(total) / n);
        }
        printf("\n");
    }

    return 0;
}
