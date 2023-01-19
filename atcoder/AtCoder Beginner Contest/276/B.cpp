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
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N+1);
    rep(i, 0, M) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, 1, N+1) sort(G[i].begin(), G[i].end());
    rep(i, 1, N+1) {
        cout << G[i].size() << " ";
        rep(j, 0, G[i].size()) cout << G[i][j] << " ";
        cout << endl;
    }
}