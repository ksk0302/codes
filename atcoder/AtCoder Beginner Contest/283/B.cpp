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
    int N; cin >> N;
    veci A(N);
    rep(i, 0, N) cin >> A[i];
    int Q; cin >> Q;
    veci ans;
    rep(i, 0, Q) {
        int num; cin >> num;
        if(num == 1) {
            int k, x; cin >> k >> x;
            A[k-1] = x;
        } else {
            int k; cin >> k;
            ans.push_back(A[k-1]);
        }
    }

    rep(i, 0, ans.size()) cout << ans[i] << endl;
}