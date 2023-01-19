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
    ll N; cin >> N;

    vector<ll> digits;
    rep(i, 0, 60) {
        if(N%2 == 1) digits.push_back(1LL<<i);
        N /= 2;
    }
    int num = digits.size();

    set<ll> S;

    rep(bit, 0, 1<<num) {
        ll sum = 0;
        rep(i, 0, num) {
            if(bit & (1<<i)) sum += digits[i];
        }
        S.insert(sum);
    }

    for(auto s : S) cout << s << endl;
}