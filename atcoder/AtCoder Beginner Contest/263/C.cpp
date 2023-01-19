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
    int N, M; cin >> N >> M;

    vveci ans;
    rep(bit, 0, 1<<M) {
        veci tmp = {};
        rep(i, 0, M) {
            if(bit / (1<<i) % 2 != 0) tmp.push_back(i+1);
        }
        if(tmp.size() == N) ans.push_back(tmp);
    }

    sort(ans.begin(), ans.end());

    for(auto i : ans) {
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
}