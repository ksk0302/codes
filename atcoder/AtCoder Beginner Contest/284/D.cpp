#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
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
    int T; cin >> T;

    vvecll ans(T, vecll(2));
    rep(t, 0, T) {
        ll N; cin >> N;
        ll tmp1 = 0, tmp2 = 0;
        for(ll i=2; i<=1e7; i++) {
            if(N%(i*i) == 0) {
                tmp1 = i;
                tmp2 = N / (i*i);
                break;
            } else if(N%i == 0) {
                tmp2 = i;
                tmp1 = sqrt(N / i);
                break;
            }
        }

        ans[t][0] = tmp1;
        ans[t][1] = tmp2;
    }

    rep(t, 0, T) {
        rep(i, 0, 2) cout << ans[t][i] << " ";
        cout << endl;
    }
}