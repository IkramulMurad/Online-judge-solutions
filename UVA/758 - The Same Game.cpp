#include <iostream>
#include <cstdio>
using namespace std;

const int mx = 18;
char g[mx][mx];
bool hasBall[mx][mx], visited[mx][mx];
int n = 10, m = 15;
int score;
char clr;
int r, c, cluster[mx][mx];
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

void file(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void resetVisited(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            visited[i][j] = false;
        }
    }
}

void resetHasBall(){
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < mx; ++j){
            hasBall[i][j] = true;
        }
    }
}

int remainingBalls(){
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(hasBall[i][j]) ++ans;
        }
    }
    return ans;
}

bool valid(int i, int j){
    return (i >= 0 and j >= 0 and i < n and j < m);
}

void dfs(int i, int j, char color, int& ans){
    ++ans;
    visited[i][j] = true;

    for(int k = 0; k < 4; ++k){
        int newI = i + x[k];
        int newJ = j + y[k];

        if(valid(newI, newJ) and !visited[newI][newJ] and hasBall[newI][newJ] and g[newI][newJ] == color){
            dfs(newI, newJ, color, ans);
        }
    }
}

bool colEmpty(int j){
    for(int i = 0; i < n; ++i){
        if(hasBall[i][j]) return false;
    }
    return true;
}

void reduceCol(int j){
    for(int i = 0; i < n; ++i){
        if(hasBall[i][j]){
            hasBall[i][j] = false;
            hasBall[i][j - 1] = true;
            g[i][j - 1] = g[i][j];
        }
    }
}

void shiftCol(){
    for(int i = m - 1; i >= 0; --i){
        if(colEmpty(i)){
            for(int j = i + 1; j < m; ++j){
                reduceCol(j);
            }
        }
    }
}

void reduceRow(int i, int j){
    if(hasBall[i][j]){
        hasBall[i][j] = false;
        hasBall[i + 1][j] = true;
        g[i + 1][j] = g[i][j];
    }
}

void shiftRow(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!hasBall[i][j]){
                for(int k = i - 1; k >= 0; --k){
                    reduceRow(k, j);
                }
            }
        }
    }
}

void eat(int i, int j, char color){
    hasBall[i][j] = false;

    for(int k = 0; k < 4; ++k){
        int newI = i + x[k];
        int newJ = j + y[k];

        if(valid(newI, newJ) and hasBall[newI][newJ] and g[newI][newJ] == color){
            eat(newI, newJ, color);
        }
    }
}

void adjustBalls(){
    shiftCol();
    shiftRow();
}

bool chooseCluster(){
    bool ret = false;
    int cur = 2;

    for(int j = m - 1; j >= 0; --j){
        for(int i = 0; i < n; ++i){
            if(cluster[i][j] >= cur){
                cur = cluster[i][j];
                r = i; c = j;
                ret = true;
            }
        }
    }

    return ret;
}

void makeCluster(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            resetVisited();
            cluster[i][j] = 0;
            if(hasBall[i][j]){
                dfs(i, j, g[i][j], cluster[i][j]);
            }
        }
    }
}

bool moveAvailable(){
    makeCluster();
    if(chooseCluster()){
        clr = g[r][c];
        eat(r, c, clr);
        adjustBalls();
        return true;
    }
    if(!remainingBalls()){
        score += 1000;
    }

    return false;
}

void updateScore(){
    score += (cluster[r][c] - 2) * (cluster[r][c] - 2);
}

void scan(){
    for(int i = 0; i < n; ++i){
        cin >> g[i];
    }
}

void printGameId(int t){
    if(t++) cout << endl;
    cout << "Game " << t << ":" << endl << endl;
}

void printMove(int mv){
    int balls = cluster[r][c];
    int points = (balls - 2) * (balls - 2);

    cout << "Move " << mv << " at (" << 10 - r << "," << c + 1 << "): removed " << balls;
    cout << " balls of color " << clr << ", got " << points << " points." << endl;
}

void printFinalScore(){
    cout << "Final score: " << score << ", with " << remainingBalls() << " balls remaining." << endl;
}

int main()
{
    //file();

    int tc;
    cin >> tc;

    for(int t = 0; t < tc; ++t){
        scan();

        score = 0;
        resetHasBall();
        printGameId(t);

        int mv = 0;
        while(moveAvailable()){
            updateScore();
            printMove(++mv);
        }

        printFinalScore();
    }

    return 0;
}
