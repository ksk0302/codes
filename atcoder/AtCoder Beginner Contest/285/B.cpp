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
    int N;
    string S;
    cin >> N >> S;

    vector<int> ans;
    rep(i, 0, N-1) {
        int tmp = N - i - 1;
        for(int j=0; j+i<N-1; j++) {
            if(S[j] == S[j+i+1]) {
                tmp = j;
                break;
            }
        }
        ans.push_back(tmp);
    }

    rep(i, 0, N-1) cout << ans[i] << endl;
}