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
    int N; cin >> N;
    vector<int> a(N+1);
    rep(i, 1, N+1) cin >> a[i];

    ll cnt = 0, ans = 0;
    rep(i, 1, N+1) {
        if(a[i] == i) cnt++;
        else if(a[a[i]] == i) ans++;
    }

    cout << ans/2 + cnt*(cnt-1)/2 << endl;
}