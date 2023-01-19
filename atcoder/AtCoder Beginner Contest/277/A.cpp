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
    int N, X; cin >> N >> X;
    vector<int> P(N);
    rep(i, 0, N) cin >> P[i];
    rep(i, 0, N) {
        if(P[i] == X) {
            cout << i+1 << endl;
            return 0;
        }
    }
}