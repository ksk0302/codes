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
    
    vector<int> ans(T);
    rep(i, 0, T) {
        int N; cin >> N;
        int cnt = 0;
        rep(j, 0, N) {
            int a; cin >> a;
            if(a%2 == 1) cnt++;
        }
        ans[i] = cnt;
    }

    rep(i, 0, T) cout << ans[i] << endl;
}