#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mx = 5e5 + 5;
const int sz = 1048576 + 5; //2^log(mx)+1
int a[mx] = {0};
int n;

class SegTree{
private:
    LL kount;
    vector<vector<int> > v;
    int tree[sz];

public:
    SegTree() : kount(0){ v.resize(sz); }
    void init(int node, int s, int t);
    void initMax(int node, int s, int t);
    void DnQ(int s, int t);
    LL getKount();

private:
    LL query(int node, int s, int t, int l, int r, int x);
    int findMaxId(int node, int s, int t, int l, int r);
    int binSearch(int node, int x);
};

LL SegTree::getKount(){
    return kount;
}

int SegTree::binSearch(int node, int x){
    return int(upper_bound(v[node].begin(), v[node].end(), x) - v[node].begin());
}

void SegTree::initMax(int node, int s, int t){
    if(s == t){
        tree[node] = s;
        return;
    }

    int mid = (s + t) / 2;
    int left = node * 2, right = left + 1;

    initMax(left, s, mid);
    initMax(right, mid + 1, t);

    if(a[tree[left]] > a[tree[right]]) tree[node] = tree[left];
    else tree[node] = tree[right];
}

int SegTree::findMaxId(int node, int s, int t, int l, int r){
    if(l > t or r < s) return 0;
    if(s >= l and t <= r) return tree[node];

    int mid = (s + t) / 2;
    int left = node * 2, right = left + 1;

    int p1 = findMaxId(left, s, mid, l, r);
    int p2 = findMaxId(right, mid + 1, t, l, r);

    if(a[p1] >= a[p2]) return p1;
    else return p2;
}

void SegTree::init(int node, int s, int t){
    if(s == t){
        v[node].push_back(a[s]);
        return;
    }

    int mid = (s + t) / 2;
    int left = node * 2, right = left + 1;

    init(left, s, mid);
    init(right, mid + 1, t);

    int n = v[left].size(), m = v[right].size();
    int i = 0, j = 0;

    while(i < n and j < m){
        if(v[left][i] < v[right][j])
            v[node].push_back(v[left][i++]);
        else
            v[node].push_back(v[right][j++]);
    }

    while(i < n) v[node].push_back(v[left][i++]);
    while(j < m) v[node].push_back(v[right][j++]);
}

LL SegTree::query(int node, int s, int t, int l, int r, int x){
    if(l > t or r < s) return 0;
    if(s >= l and t <= r){
        return binSearch(node, x);
    }

    int mid = (s + t) / 2;
    int left = node * 2, right = left + 1;

    LL q1 = query(left, s, mid, l, r, x);
    LL q2 = query(right, mid + 1, t, l, r, x);

    return q1 + q2;
}

void SegTree::DnQ(int s, int t){
    if(t <= s) return;

    int id = findMaxId(1, 1, n, s, t);

    int stPoint, endPoint, l, r;
    if(id - s < t - id){
        stPoint = s;
        endPoint = id;

        l = id;
        r = t;
    }
    else{
        stPoint = id;
        endPoint = t;

        l = s;
        r = id;
    }

    for(int i = stPoint; i <= endPoint; ++i){
        kount += query(1, 1, n, l, r, a[id]/a[i]);
        if(a[id] == 1) --kount;
    }

    DnQ(s, id - 1);
    DnQ(id + 1, t);
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }

    SegTree st;
    st.initMax(1, 1, n);
    st.init(1, 1, n);
    st.DnQ(1, n);

    cout << st.getKount() << endl;

    return 0;
}
