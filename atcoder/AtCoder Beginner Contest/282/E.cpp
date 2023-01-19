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
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)

ll M;

// a^b mod M を求める
ll apowM_2(ll a, ll b) {
    vecll apow(60), twopow(60);
    apow[0] = a;
    twopow[0] = 1;
    rep(i, 1, 60) {
        apow[i] = apow[i-1]*apow[i-1];
        apow[i] %= M;
        twopow[i] = 2*twopow[i-1];
    }

    ll ans = 1;
    rrep(i, 0, 60) {
        if(b >= twopow[i]) {
            b -= twopow[i];
            ans *= apow[i];
            ans %= M;
        }
    }
    return ans;
}

int main() {
    ll N; cin >> N >> M;
    vecll A(N);
    rep(i, 0, N) cin >> A[i];

    sort(A.begin(), A.end());
    vecll row(N, 0), column(N, 0);
    rep(i, 0, N) {
        rep(j, i+1, N) {
            ll tmp = (apowM_2(A[i], A[j]) + apowM_2(A[j], A[i])) % M;
            row[i] = max(row[i], tmp);
            column[j] = max(column[j], tmp);
        }
    }

    ll ans1 = 0, ans2 = 0;
    rep(i, 0, N) {
        ans1 += row[i];
        ans2 += column[i];
    }
    cout << max(ans1, ans2) << endl;
}