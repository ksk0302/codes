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

int main() {
    int N, M; cin >> N >> M;
    vecll A(N+1);
    rep(i, 1, N+1) cin >> A[i];
    vvecll dp(M+1, vecll(N+1, -1e15));
    dp[0].assign(N+1, 0);

    rep(i, 1, M+1) {
        rep(j, i, N-M+i+1) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + A[j]*i);
        }
    }

    cout << dp[M][N] << endl;
}