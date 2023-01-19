#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ll = long long;
using veci = vector<int>;
using vecll = vector<ll>;
using vecd = vector<double>;
using vveci = vector<veci>;
using vvecll = vector<vecll>;
using vvecd = vector<vecd>;
using Graph = vector<vector<int>>;
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)

veci dx = {-1, -1, 0, 0, 1, 1};
veci dy = {-1, 0, -1, 1, 0, 1};

Graph G(2001, veci(2001, 0));

void dfs(int sx, int sy) {
    G[sx][sy] = 0;

    rep(i, 0, 6) {
        int nextx = sx + dx[i], nexty = sy + dy[i];
        if(nextx < 0 || nextx > 2000 || nexty < 0 || nexty > 2000) continue;
        if(!G[nextx][nexty]) continue;
        dfs(nextx, nexty);
    }
}

int main() {
    int N; cin >> N;
    rep(i, 0, N) {
        int x, y; cin >> x >> y; x+=1000; y+=1000;
        G[y][x] = 1;
    }

    int cnt = 0;
    rep(i, 0, 2001) {
        rep(j, 0, 2001) {
            if(!G[i][j]) continue;
            dfs(i, j);
            cnt++;
        }
    }

    cout << cnt << endl;
}