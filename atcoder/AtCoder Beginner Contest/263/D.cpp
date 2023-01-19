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
    ll N, L, R; cin >> N >> L >> R;
    vecll A(N+2, 0), sumA(N+2, 0), tmp(N+2, 0);
    rep(i, 1, N+1) cin >> A[i];
    rep(i, 1, N+1) sumA[i] = sumA[i-1] + A[i];
    rep(i, 0, N+1) tmp[i] = sumA[N] - sumA[i] + i * L;
    ll mintmp = LLONG_MAX, x = 0;
    rep(i, 0, N+1) {
        if(tmp[i] < mintmp) {
            mintmp = tmp[i]; x = i;
        }
    }
    rep(i, 0, x+1) A[i] = L;

    reverse(A.begin(), A.end());
    rep(i, 1, N+1) sumA[i] = sumA[i-1] + A[i];
    rep(i, 0, N+1) tmp[i] = sumA[N] - sumA[i] + i * R;
    mintmp = LLONG_MAX; ll y = 0;
    rep(i, 0, N+1) {
        if(tmp[i] < mintmp) {
            mintmp = tmp[i]; y = i;
        }
    }
    rep(i, 0, y+1) A[i] = R;

    ll ans = 0;
    rep(i, 1, N+1) ans += A[i];
    cout << ans << endl;
}