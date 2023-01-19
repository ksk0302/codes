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

ll N, P, Q, R;
vecll A, sumA;

ll key()

int main() {
    cin >> N >> P >> Q >> R;
    A.resize(N);
    sumA.resize(N);
    rep(i, 0, N) {
        cin >> A[i];
        if(i == 0) sumA[i] = A[i];
        else sumA[i] = sumA[i-1] + A[i];
    }

    ll xl = -1, xr = -1;
    rep(i, 0, N) {
        x = i;
    }
}