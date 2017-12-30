#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mx = 1005;
const int total = 35;
int dp[total][mx], taken[total][mx];
bool inSol[total];
int depth[total], quantity[total];
int cap, w, n;

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    memset(inSol, false, sizeof(inSol));
    memset(dp, -1, sizeof(dp));
    memset(taken, -1, sizeof(taken));
}

void scan(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> depth[i] >> quantity[i];
    }
}

int cal(int i, int amount){
    if(i == n) return 0;
    if(dp[i][amount] != -1) return dp[i][amount];

    int q1 = 0, q2 = 0;
    if(amount + depth[i] * w <= cap){
        q1 = quantity[i] + cal(i + 1, amount + depth[i] * w);
    }
    q2 = cal(i + 1, amount);

    if(q1 > q2) { taken[i][amount] = 1; dp[i][amount] = q1; }
    else { taken[i][amount] = 0; dp[i][amount] = q2; }

    return dp[i][amount];
}

void solveAndPrint(int tc){
    w *= 3;

    if(tc) cout << endl;
    cout << cal(0, 0) << endl;

    int kount , i, amount;
    kount = i = amount = 0;

    while(taken[i][amount] != -1){
        if(taken[i][amount] == 1){
            amount += depth[i] * w;
            inSol[i] = true;
            ++kount;
        }
        ++i;
    }

    cout << kount << endl;
    for(int i = 0; i < n; ++i){
        if(inSol[i]) cout << depth[i] << " " << quantity[i] << endl;
    }
}

int main()
{
    //file();

    int tc = 0;
    while(cin >> cap >> w){
        reset();
        scan();
        solveAndPrint(tc++);
    }

    return 0;
}
