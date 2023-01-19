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

int N, M;
Graph G;
vector<int> color;  // 1 : 黒, 0 : 白, -1 : 未訪問

// 二部グラフ判定 DFS
bool dfs(int v, int b_or_w = 0) {
    color[v] = b_or_w;
    for(auto next : G[v]) {
        if(color[next] != -1) {
            if(color[next] == b_or_w) return false;
            continue;
        }

        if(!dfs(next, 1-b_or_w)) return false;
    }
    return true;
}

int main() {
    cin >> N >> M;
    G.assign(N, veci());
    color.assign(N, -1);

    rep(i, 0, M) {
        int u, v; cin >> u >> v;
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }

    ll bipartite = 0;
    for(int v = 0; v < N; v++) {
        if(color[v] != -1) continue;
        if(dfs(v)) bipartite++;
    }

    cout << bipartite*(bipartite-1)/2 << endl;
}