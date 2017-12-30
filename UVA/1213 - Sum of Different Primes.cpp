#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

const int mx = 1120;
vector<int> primes;
int dp[200][20][mx + 5];

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void reset(){
    memset(dp, -1, sizeof(dp));
}

void siv(){
    int sq = sqrt(mx);
    bool used[mx] = {false};

    for(int i = 3; i <= sq; i += 2){
        if(!used[i]){
            for(int j = i*i; j < mx; j += i + i){
                used[j] = true;
            }
        }
    }

    primes.push_back(2);
    for(int i = 3; i < mx; i += 2){
        if(!used[i]) primes.push_back(i);
    }
}

int cal(int i, int k, int num){
    if(k == 0){
        if(num == 0) return 1;
        return 0;
    }
    if(i == primes.size()) return 0;
    if(dp[i][k][num] != -1) return dp[i][k][num];

    int n1 = 0, n2;
    if(num - primes[i] >= 0){
        n1 = cal(i + 1, k - 1, num - primes[i]);
    }
    n2 = cal(i + 1, k, num);

    return dp[i][k][num] = n1 + n2;
}

int main()
{
    //file();

    siv();
    reset();

    int num, k;
    while(cin >> num >> k and (num or k)){
        cout << cal(0, k, num) << endl;
    }

    return 0;
}
