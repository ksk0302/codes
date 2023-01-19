#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
using namespace std;
using ll=long long;

int main() {
    int N, Q; cin >> N >> Q;
    vector<vector<int>> a(N);
    vector<int> ans(Q);

    for(int i=0; i<N; i++) {
        int L; cin >> L;
        a[i].assign(L, 0);
        for(int l=0; l<L; l++) cin >> a[i][l];
    }

    for(int q=0; q<Q; q++) {
        int s, t; cin >> s >> t;
        ans[q] = a[s-1][t-1];
    }

    for(int q=0; q<Q; q++) cout << ans[q] << endl;
}