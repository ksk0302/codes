#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;
using ll = long long;
using veci = vector<int>;
using vecll = vector<ll>;
using vecd = vector<double>;
using vveci = vector<veci>;
using vvecll = vector<vecll>;
using vvecd = vector<vecd>;
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)

int N, M, cnt = 0;
vveci G;
set<int> visited;

void dfs(int v) {
    if(cnt > 1e6) return;
    cnt++;
    visited.insert(v);

    for(auto next : G[v]) {
        if(visited.find(next) != visited.end()) continue;
        dfs(next);
    }

    visited.erase(v);
}

int main() {
    cin >> N >> M;
    G.assign(N, veci());
    rep(i, 0, M) {
        int u, v; cin >> u >> v;
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }

    dfs(0);

    cout << min(cnt, 1000000) << endl;
}