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
using vveci = vector<veci>;
using vvecll = vector<vecll>;
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)

int main() {
    int H, W; cin >> H >> W;
    vector<string> S(H);
    int cnt = 0;
    rep(i, 0, H) cin >> S[i];
    rep(i, 0, H) {
        rep(j, 0, W) if(S[i][j] == '#') cnt++;
    }
    cout << cnt << endl;
}