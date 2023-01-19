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
using vveci = vector<veci>;
using vvecll = vector<vecll>;
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)

int main() {
    int N; cin >> N;
    vecll S(N), A(N);
    rep(i, 0, N) cin >> S[i];
    A[0] = S[0];
    rep(i, 1, N) A[i] = S[i] - S[i-1];
    rep(i, 0, N) cout << A[i] << " ";
    cout << endl;
}