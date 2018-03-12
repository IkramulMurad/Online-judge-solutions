#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> II;
const int mx = 1e5 + 5;
const int sz = 262144 + 5; // 2^log(mx)+1
int n, q;
int a[mx];
 
bool triangle(LL a, LL b, LL c);
 
class SegTree{
public:
    vector<set<II> > v;
 
private:
    void query(int node, int s, int t, int l, int r, vector<int>& nodes);
    LL selectNext(set<II>::reverse_iterator rit[], vector<int>& nodes);
 
public:
    SegTree(){ v.resize(sz); }
    void init(int node, int s, int t);
    void update(int node, int s, int t, int idx, int oldValue, int value);
    LL cal(int l, int r);
};
 
void SegTree::init(int node, int s, int t){
    if(s == t){
        v[node].insert({a[s], s});
        return;
    }
 
    int mid = (s + t) / 2;
    int left = node * 2, right = left + 1;
 
    init(left, s, mid);
    init(right, mid + 1, t);
 
    for(auto it = v[left].begin(); it != v[left].end(); ++it){
        v[node].insert(*it);
    }
    for(auto it = v[right].begin(); it != v[right].end(); ++it){
        v[node].insert(*it);
    }
}
 
void SegTree::update(int node, int s, int t, int i, int oldValue, int value){
    if(i < s or i > t) return;
    if(s >= i and t <= i){
        v[node].erase({oldValue, i});
        v[node].insert({value, i});
        return;
    }
 
    int mid = (s + t) / 2;
    int left = node * 2, right = left + 1;
 
    update(left, s, mid, i, oldValue, value);
    update(right, mid + 1, t, i, oldValue, value);
 
    v[node].erase({oldValue, i});
    v[node].insert({value, i});
}
 
void SegTree::query(int node, int s, int t, int l, int r, vector<int>& nodes){
    if(l > t or r < s) return;
    if(s >= l and t <= r){
        nodes.push_back(node);
        return;
    }
 
    int mid = (s + t) / 2;
    int left = node * 2, right = left + 1;
 
    query(left, s, mid, l, r, nodes);
    query(right, mid + 1, t, l, r, nodes);
}
 
LL SegTree::selectNext(set<II>::reverse_iterator rit[], vector<int>& nodes){
    int id = -1, sz = nodes.size();
    LL mx = 0;
 
    for(int i =0; i < sz; ++i){
        if(rit[i] != v[nodes[i]].rend() and rit[i]->first > mx){
            id = i;
            mx = rit[i]->first;
        }
    }
    if(id != -1) ++rit[id];
 
    return mx;
}
 
LL SegTree::cal(int l, int r){
    vector<int> nodes;
    query(1, 1, n, l, r, nodes);
 
    int sz = nodes.size();
    set<II>::reverse_iterator rit[sz];
 
    for(int i = 0; i < sz; ++i){
        rit[i] = v[nodes[i]].rbegin();
    }
 
    LL a = selectNext(rit, nodes), b = selectNext(rit, nodes), c;
    while(true){
        c = selectNext(rit, nodes);
        //cerr << a << " " << b << " " << c << endl;
        if(!c) break;
 
        if(triangle(a, b, c)) return a + b + c;
        a = b;
        b = c;
    }
 
    return 0;
}
 
void scan(){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}
 
bool triangle(LL a, LL b, LL c){
    if(a + b > c and b + c > a and c + a > b)
        return true;
    return false;
}
 
void debug(){
    for(int i = 1; i <= n; ++i){
        cerr << a[i] << " ";
    }
    cerr << endl;
}
 
int main()
{
//    system("gen.exe");
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
 
    scan();
 
    SegTree st;
    st.init(1, 1, n);
 
    for(int i = 0; i < q; ++i){
        int type;
        cin >> type;
 
        if(type == 1){
            int pos, val;
            cin >> pos >> val;
 
            st.update(1, 1, n, pos, a[pos], val);
            a[pos] = val;
            //debug();
        }
        else{
            int l, r;
            cin >> l >> r;
 
            LL ans = st.cal(l, r);
            cout << ans << endl;
        }
    }
 
    return 0;
}
