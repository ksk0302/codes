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
    ll K; cin >> K;

    ll ans = 0;
    for(ll p=2; p*p<=K; p++) {
        ll cnt = 0;
        while(K%p == 0) {
            K /= p; cnt++;
        }

        ll N = 0;
        while(cnt > 0) {
            N += p;
            ll tmpN = N;
            while(tmpN%p == 0) {
                tmpN /= p; cnt--;
            }
        } 
        ans = max(ans, N);
    }
    cout << max(ans, K) << endl;
}