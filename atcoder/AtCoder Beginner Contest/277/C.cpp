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
    int N; cin >> N;
    map<int, vector<int>> G;
    rep(i, 0, N) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    map<int, bool> floor;
    queue<int> que;
    floor[1] = true;
    que.push(1);
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for(auto v2 : G[v]) {
            if(floor[v2]) continue;
            floor[v2] = true;
            que.push(v2);
        }
    }
    int ans = 0;
    for(auto f : floor) if(f.second) ans = f.first;
    cout << ans << endl;
}