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
    int H, W; cin >> H >> W;
    vector<string> S(H), T(H), changedS(W, ""), changedT(W, "");
    rep(i, 0, H) cin >> S[i];
    rep(i, 0, H) cin >> T[i];
    rep(i, 0, H) rep(j, 0, W) changedS[j].push_back(S[i][j]);
    rep(i, 0, H) rep(j, 0, W) changedT[j].push_back(T[i][j]);
    sort(changedS.begin(), changedS.end());
    sort(changedT.begin(), changedT.end());
    
    rep(i, 0, W) {
        if(changedS[i] != changedT[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}