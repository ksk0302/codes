#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <functional>
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

int main() {
    int N, K, D; cin >> N >> K >> D;
    veci a(N);
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(K+1, vector<ll>(D, -1)));
    rep(i, 0, N) cin >> a[i];

    dp[0][0][0] = 0;
    rep(i, 0, N) {
        rep(j, 0, K+1) {
            rep(k, 0, D) {
                if(dp[i][j][k] == -1) continue;
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                if(j != K) dp[i+1][j+1][(k+a[i])%D] = max(dp[i+1][j+1][(k+a[i])%D], dp[i][j][k] + a[i]);
            }
        }
    }
    cout << dp[N][K][0] << endl;
}