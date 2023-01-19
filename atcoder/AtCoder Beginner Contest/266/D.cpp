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
    int N; cin >> N;
    ll Tmax = 0;
    vecll T(N), X(N), A(N);
    rep(i, 0, N) {
        cin >> T[i] >> X[i] >> A[i];
        Tmax = max(Tmax, T[i]);
    }
    vvecll dp(5, vecll(Tmax+1, 0));
    rep(i, 0, N) if(T[i] >= X[i]) dp[X[i]][T[i]] = A[i];

    rep(i, 1, Tmax+1) {
        rep(j, 0, 5) {
            if(j == 0) dp[j][i] += max(dp[j][i-1], dp[j+1][i-1]);
            else if(j == 4) dp[j][i] += max(dp[j][i-1], dp[j-1][i-1]);
            else dp[j][i] += max({dp[j][i-1], dp[j-1][i-1], dp[j+1][i-1]});
        }
    }

    ll maxofAsum = 0;
    rep(i, 0, 5) maxofAsum = max(maxofAsum, dp[i][Tmax]);
    cout << maxofAsum << endl;
}