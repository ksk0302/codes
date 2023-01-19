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
    int N, S; cin >> N >> S;
    veci a(N+1), b(N+1);
    rep(i, 1, N+1) cin >> a[i] >> b[i];

    vector<vector<bool>> dp(N+1, vector<bool>(S+1, false));
    a[0] = 0; b[0] = 0;
    dp[0][0] = true;
    rep(i, 1, N+1) {
        rep(j, 0, S+1) {
            if(j >= a[i] && dp[i-1][j-a[i]]) dp[i][j] = true;
            if(j >= b[i] && dp[i-1][j-b[i]]) dp[i][j] = true;
        }
    }

    if(!dp[N][S]) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        int now = S;
        vector<char> ans;
        rrep(i, 1, N+1) {
            if(now >= a[i] && dp[i-1][now-a[i]]) {
                now -= a[i];
                ans.push_back('H');
            } else if(now >= b[i] && dp[i-1][now-b[i]]) {
                now -= b[i];
                ans.push_back('T');
            }
        }
        rrep(i, 0, ans.size()) cout << ans[i];
        cout << endl;
    }
}