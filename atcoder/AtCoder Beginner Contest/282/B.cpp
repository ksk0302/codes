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

int main() {
    int N, M; cin >> N >> M;
    vector<string> S(N);
    rep(i, 0, N) cin >> S[i];

    int ans = 0;
    rep(i, 0, N) {
        rep(j, i+1, N) {
            vector<bool> problem(M, false);
            rep(mi, 0, M) if(S[i][mi] == 'o') problem[mi] = true;
            rep(mj, 0, M) if(S[j][mj] == 'o') problem[mj] = true;
            int cnt = 0;
            rep(k, 0, M) if(problem[k]) cnt++;
            if(cnt == M) ans++;
        }
    }
    cout << ans << endl;
}