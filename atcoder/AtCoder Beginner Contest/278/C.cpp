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
    int N, Q; cin >> N >> Q;
    map<int, map<int, int>> G;
    vector<int> ans(Q);
    int cnt = 0;
    rep(q, 0, Q) {
        int t, a, b; cin >> t >> a >> b;
        if(t == 1) {
            G[a][b] = 1;
        } else if(t == 2) {
            G[a][b] = 0;
        } else {
            if(G[a][b] && G[b][a]) ans[cnt] = 1;
            else ans[cnt] = 0;
            cnt++;
        }
    }
    rep(i, 0, cnt) {
        if(ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}