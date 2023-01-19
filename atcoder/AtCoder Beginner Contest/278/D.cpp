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
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)
using ll = long long;

int main() {
    int N; cin >> N;
    vector<pair<ll, int>> A(N);
    rep(i, 0, N) {
        ll tmp; cin >> tmp;
        A[i].first = tmp;
        A[i].second = 0;
    }

    vector<ll> ans;
    int Q; cin >> Q;
    int version = 0;
    ll change;
    rep(q, 0, Q) {
        int num; cin >> num;
        if(num == 1) {
            cin >> change;
            version++;
        } else if(num == 2) {
            int i;
            ll x;
            cin >> i >> x;
            if(A[i-1].second != version) {
                A[i-1].first = change;
                A[i-1].second = version;
            }
            A[i-1].first += x;
        } else {
            int i; cin >> i;
            if(A[i-1].second != version) {
                A[i-1].first = change;
                A[i-1].second = version;
            }
            ans.push_back(A[i-1].first);
        }
    }
    rep(i, 0, ans.size()) cout << ans[i] << endl;
}