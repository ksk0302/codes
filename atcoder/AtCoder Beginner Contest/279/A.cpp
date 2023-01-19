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
    string S; cin >> S;
    int ans = 0;
    rep(i, 0, S.size()) {
        if(S[i] == 'w') ans += 2;
        else ans++;
    }
    cout << ans << endl;
}