// #define DBG_FILE
// #define DBG_UPD
// #define DBG_QRY

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int mx = 1e5 + 5;
const int sz = 1 << ((int)ceil(log2(mx)) + 1);

void reduce(int &num, int &den){
    int gcd = __gcd(num, den);
    num /= gcd;
    den /= gcd;
}

struct Node{
    int val, prop;

    Node(){
        val = 0;
        prop = -1;
    }
};

struct SegTree
{
    Node tree[sz];

    void build(int node, int s, int t){
        if(s == t){
            tree[node] = Node();
            return;
        }

        int mid = (s + t) / 2;
        int left = node * 2;
        int right = left + 1;

        build(left, s, mid);
        build(right, mid + 1, t);

        tree[node].val = tree[left].val + tree[right].val;
        tree[node].prop = -1;
    }

    void update(int node, int s, int t, int l, int r, int x, int carry = -1){
        if(s > r or t < l){
            if(carry >= 0){
                tree[node].val = (t - s + 1) * carry;
                tree[node].prop = carry;
            }
            return;
        }
        if(s >= l and t <= r){
            tree[node].val = (t - s + 1) * x;
            tree[node].prop = x;

            #ifdef DBG_UPD
            cout << "node: " << node << ", val: " << tree[node].val << ", prop: " << x << endl;
            cout << endl;
            #endif

            return;
        }

        int mid = (s + t) / 2;
        int left = node * 2;
        int right = left + 1;

        update(left, s, mid, l, r, x, carry >= 0 ? carry : tree[node].prop);
        update(right, mid + 1, t, l, r, x, carry >= 0 ? carry : tree[node].prop);

        tree[node].val = tree[left].val + tree[right].val;
        tree[node].prop = -1;

        #ifdef DBG_UPD
        cout << "left: " << left << ", val: " << tree[left].val << ", prop: " << tree[left].prop << endl;
        cout << "right: " << right << ", val: " << tree[right].val << ", prop: " << tree[right].prop << endl;
        cout << "node: " << node << ", val: " << tree[node].val << ", prop: " << tree[node].prop << endl;
        cout << endl;
        #endif
    }

    int query(int node, int s, int t, int l, int r, int carry = -1){
        if(s > r or t < l){
            return 0;
        }
        if(s >= l and t <= r){
            #ifdef DBG_QRY
            cout << "node: " << node << ", val: " << (carry >= 0 ? (t - s + 1) * carry : tree[node].val) << endl;
            cout << endl;
            #endif

            if(carry >= 0){
                return (t - s + 1) * carry;
            }
            return tree[node].val;
        }

        int mid = (s + t) / 2;
        int left = node * 2;
        int right = left + 1;

        int p = query(left, s, mid, l, r, carry >= 0 ? carry : tree[node].prop);
        int q = query(right, mid + 1, t, l, r, carry >= 0 ? carry : tree[node].prop);

        #ifdef DBG_QRY
        cout << "left: " << left << ", val: " << p << endl;
        cout << "right: " << right << ", val: " << q << endl;
        cout << "node: " << node << ", val: " << p + q << endl;
        cout << endl;
        #endif

        return p + q;
    }
};


int main(){
    #ifdef DBG_FILE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; ++t){
        int n, q;
        scanf("%d %d", &n, &q);
        printf("Case %d:\n", t);

        SegTree st;
        st.build(1, 1, n);

        for(int i = 0; i < q; ++i){
            int type, l, r;
            scanf("%d %d %d", &type, &l, &r);

            if(type == 1){
                int v;
                scanf("%d", &v);

                #ifdef DBG_UPD
                cout << "update: " << l + 1 << " - " << r + 1 << ", val: " << v << endl;
                #endif

                st.update(1, 1, n, l + 1, r + 1, v);
            }
            else{
                #ifdef DBG_QRY
                cout << "query: " << l + 1 << " - " << r + 1 << endl;
                #endif
                
                int num = st.query(1, 1, n, l + 1, r + 1);
                int den = r - l + 1;
                reduce(num, den);

                if(den == 1){
                    printf("%d\n", num);
                }
                else{
                    printf("%d/%d\n", num, den);
                }
            }
        }
    }
}
