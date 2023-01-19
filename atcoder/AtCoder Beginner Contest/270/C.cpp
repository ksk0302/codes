#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
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

int N, X, Y;
vveci G;
vector<bool> visited;
stack<int> route, ans;

void dfs(int s) {
    visited[s] = true;
    route.push(s);
    if(s == Y-1) ans = route;

    rep(i, 0, G[s].size()) {
        if(!visited[G[s][i]]) dfs(G[s][i]);
    }
    route.pop();
    return;
}

int main() {
    cin >> N >> X >> Y;
    G.assign(N, veci());
    visited.assign(N, false);

    rep(i, 0, N-1) {
        int u, v; cin >> u >> v;
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }

    dfs(X-1);
    veci answer;
    while(!ans.empty()) {
        answer.push_back(ans.top());
        ans.pop();
    }
    rrep(i, 0, answer.size()) cout << answer[i] + 1 << " ";
    cout << endl;
}