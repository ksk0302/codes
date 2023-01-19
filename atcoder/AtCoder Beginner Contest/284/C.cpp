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

int N, M;
vveci G;
vector<bool> seen;

void dfs(int v) {
    seen[v] = true;
    for(auto v2 : G[v]) {
        if(seen[v2]) {continue;}
        dfs(v2);
    }
    return;
}

int main() {
    cin >> N >> M;
    G.assign(N, veci());
    seen.assign(N, false);

    rep(i, 0, M) {
        int u, v; cin >> u >> v;
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }

    int ans = 0;
    for(int v = 0; v < N; ++v) {
        if(seen[v]) {continue;}
        dfs(v);
        ans++;
    }

    cout << ans << endl;
}