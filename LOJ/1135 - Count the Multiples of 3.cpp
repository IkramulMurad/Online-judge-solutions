// #define DBG_FILE
// #define DBG_BLD
// #define DBG_UPD
// #define DBG_QRY

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int mx = 1e5 + 5;
const int sz = 1 << ((int)ceil(log2(mx)) + 1);

struct Node
{
    int zero, one, two, prop;
    
    Node(){
        zero = 1;
        one = two = prop = 0;
    }

    Node(int x){
        zero = one = two = prop = x;
    }

    void operator=(const Node &b){
        zero = b.zero;
        one = b.one;
        two = b.two;
        //no need to copy prop
    }

    Node operator+(const Node &b){
        Node x;
        x.zero = this->zero + b.zero;
        x.one = this->one + b.one;
        x.two = this->two + b.two;
        //no need to copy prop

        return x;
    }

    void printNode(){
        cout << "zero: " << zero << ", one: " << one << ", two: " << two << ", prop: " << prop << endl;
    }
};

Node shiftNodeOnce(Node a){
    Node b;
    b.two = a.one;
    b.one = a.zero;
    b.zero = a.two;
    b.prop = a.prop;
    
    return b;
}

Node shiftNodeNtimes(Node a, int n){
    n %= 3;
    if(n > 0){
        a = shiftNodeOnce(a);
    }
    if(n > 1){
        a = shiftNodeOnce(a);
    }

    return a;
}

struct SegTree{
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

        tree[node] = tree[left] + tree[right];

        #ifdef DBG_BLD
        cout << "left: " << left << ", val: " << tree[left].zero << endl;
        cout << "right: " << right << ", val: " << tree[right].zero << endl;
        cout << "node: " << node << ", val: " << tree[node].zero << endl;
        cout << endl;
        #endif
    }

    void update(int node, int s, int t, int l, int r){
        if(s > r or t < l){
            return;
        }
        if(s >= l and t <= r){
            tree[node] = shiftNodeOnce(tree[node]);
            ++tree[node].prop;

            #ifdef DBG_UPD
            cout << "node: " << node << ", ";
            tree[node].printNode();
            #endif

            return;
        }

        int mid = (s + t) / 2;
        int left = node * 2;
        int right = left + 1;

        update(left, s, mid, l, r);
        update(right, mid + 1, t, l, r);
        tree[node] = shiftNodeNtimes(tree[left] + tree[right], tree[node].prop);

        #ifdef DBG_UPD
        cout << "left: " << left << ", val: " << tree[left].zero << endl;
        cout << "right: " << right << ", val: " << tree[right].zero << endl;
        cout << "node: " << node << ", val: " << tree[node].zero << endl;
        cout << endl;
        #endif
    }

    Node query(int node, int s, int t, int l, int r, int carry = 0){
        if(s > r or t < l){
            return Node(0);
        }
        if(s >= l and t <= r){
            return shiftNodeNtimes(tree[node], carry);
        }

        int mid = (s + t) / 2;
        int left = node * 2;
        int right = left + 1;

        Node p = query(left, s, mid, l, r, carry + tree[node].prop);
        Node q = query(right, mid + 1, t, l, r, carry + tree[node].prop);
        Node ans = p + q;

        #ifdef DBG_QRY
        cout << "left: " << left << ", val: " << p.zero << endl;
        cout << "right: " << right << ", val: " << q.zero << endl;
        cout << "ans: " << node << ", val: " << ans.zero << endl;
        cout << endl;
        #endif

        return ans;
    }
};


int main(){
    #ifdef DBG_FILE
    freopen("in.txt", "r", stdin);
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

            if(type == 0){
                #ifdef DBG_UPD
                cout << "update: " << l + 1 << " - " << r + 1 << endl;
                #endif
                
                st.update(1, 1, n, l + 1, r + 1);
            }
            else{
                #ifdef DBG_QRY
                cout << "query: " << l + 1 << " - " << r + 1 << endl;
                #endif

                Node ans = st.query(1, 1, n, l + 1, r + 1);
                printf("%d\n", ans.zero);
            }
        }
    }

    return 0;
}
