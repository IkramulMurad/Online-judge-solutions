// #define DBG_FILE

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

typedef pair <int, int> II;
typedef pair <int, II> III;
const int mx = 1e5 + 5;
const int sz = 1 << ((int)ceil(log2(mx)) + 1);
int n, m;

void input(vector <III> &givenQuery, vector < vector <II> > &sortedQuery);
void update(int a[], int l, int r, int n, int val);
void update(int a[], int n, int index, int val);
int query(int a[], int index);

struct SegTree{
    int tree[sz];

    void build(int node, int s, int t){
        if(s == t){
            tree[node] = 0;
            return;
        }

        int mid = (s + t) / 2;
        int left = node * 2;
        int right = left + 1;

        build(left, s, mid);
        build(right, mid + 1, t);

        tree[node] = 0;
    }

    void update(int node, int s, int t, int l, int r, int x, int carry = 0){
        if(s > r or t < l){
            if(carry){
                tree[node] = carry;
            }
            return;
        }
        if(s >= l and t <= r){
            tree[node] = x;
            return;
        }

        int mid = (s + t) / 2;
        int left = node * 2;
        int right = left + 1;

        update(left, s, mid, l, r, x, carry ? carry : tree[node]);
        update(right, mid + 1, t, l, r, x, carry ? carry : tree[node]);

        tree[node] = 0;
    }

    int query(int node, int s, int t, int i, int carry = 0){
        if(s > i or t < i){
            return 0;
        }
        if(s >= i and t <= i){
            return (carry ? carry : tree[node]);
        }

        int mid = (s + t) / 2;
        int left = node * 2;
        int right = left + 1;

        int p = query(left, s, mid, i, carry ? carry : tree[node]);
        int q = query(right, mid + 1, t, i, carry ? carry : tree[node]);

        return p + q;
    }
};



int main(){
    //freopen("in.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        vector <III> givenQuery;
        vector < vector <II> > sortedQuery(mx);
        input(givenQuery, sortedQuery);

        SegTree st;
        st.build(1, 1, n);
        
        //updating queries
        for(int i = 0; i < givenQuery.size(); ++i){
            int x = givenQuery[i].first;
            int l = givenQuery[i].second.first;
            int r = givenQuery[i].second.second;

            st.update(1, 1, n, l, r, x);
        }

        //kth vector contains all the monkeys that heard kth joke
        vector <vector <int> > jokeVector(mx);
        for(int i = 1; i <= n; ++i){
            int jokeNum = st.query(1, 1, n, i);
            jokeVector[jokeNum].push_back(i);
        }
        
        //Those who didn't hear a joke will be counted
        int ans = jokeVector[0].size();

        //for different jokes, a[i] denotes how many times ith monkey heard the joke
        int a[mx] = {0};

        for(int i = 1; i < mx; ++i){
            //if current joke is last joke for any monkey and
            //this joke have to have at least two query/occurance
            if(jokeVector[i].size() > 0 and sortedQuery[i].size() > 1){
                //range update all the query
                for(int j = 0; j < sortedQuery[i].size(); ++j){
                    int l = sortedQuery[i][j].first;
                    int r = sortedQuery[i][j].second;
                    update(a, l, r, n, 1);
                }

                //query for all the monkey who have listened this joke as their last joke
                for(int j = 0; j < jokeVector[i].size(); ++j){
                    //if jth monkey listened the joke more than once
                    if(query(a, jokeVector[i][j]) > 1){
                        ++ans;
                    }
                }

                //reverse the queries to clear BIT
                for(int j = 0; j < sortedQuery[i].size(); ++j){
                    int l = sortedQuery[i][j].first;
                    int r = sortedQuery[i][j].second;
                    update(a, l, r, n, -1);
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}

void input(vector <III> &givenQuery, vector < vector <II> > &sortedQuery){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int mnk, jk, snd;
        scanf("%d %d %d", &mnk, &jk, &snd);

        int left = max(1, mnk - snd);
        int right = min(n, mnk + snd);

        givenQuery.push_back({jk, {left, right}});
        sortedQuery[jk].push_back({left, right});
    }
}

void update(int a[], int n, int index, int val){
    //Traverse all ancestors and add 'val'
    while (index <= n){
        a[index] += val;
        index += index & (-index);
    }
}

int query(int a[], int index){
    int sum = 0;

    // Traverse ancestors of a[index]
    while (index>0){
        sum += a[index];
        index -= index & (-index);
    }
    return sum;
}

void update(int a[], int l, int r, int n, int val){
    update(a, n, l, val);
    update(a, n, r + 1, -val);
}
