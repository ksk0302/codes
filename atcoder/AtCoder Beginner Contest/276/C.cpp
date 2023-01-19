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
    vector<int> a(N);
    rep(i, 0, N) cin >> a[i];
    prev_permutation(a.begin(), a.end());
    rep(i, 0, N) cout << a[i] << " ";
    cout << endl;
}