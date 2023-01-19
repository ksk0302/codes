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
    string S; cin >> S;
    string tmp = "atcoder";

    int now = -1, ans = 0;
    rep(i, 0, 7) {
        rep(j, 0, S.size()) {
            if(S[j] == tmp[i]) {
                now = j;
                break;
            }
        }
        while(now != i) {
            swap(S[now], S[now-1]);
            now--;
            ans++;
        }
    }
    cout << ans << endl;
}