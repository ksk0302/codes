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
    int N, K; cin >> N >> K;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    int sousa = min(N, K);
    rep(i, sousa, N) cout << A[i] << " ";
    rep(i, 0, sousa) cout << 0 << " ";
    cout << endl;
}