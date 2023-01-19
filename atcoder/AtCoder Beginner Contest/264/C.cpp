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
    int H1, W1, H2, W2;
    cin >> H1 >> W1;
    vveci A(H1, veci(W1));
    rep(i, 0, H1) rep(j, 0, W1) cin >> A[i][j];
    cin >> H2 >> W2;
    vveci B(H1, veci(W1));
    rep(i, 0, H2) rep(j, 0, W2) cin >> B[i][j];

    int cnt = 0;

    rep(bit1, 0, 1<<H1) {
        rep(bit2, 0, 1<<W1) {
            vector<pair<int, int>> choose;
            rep(i, 0, H1) {
                rep(j, 0, W1) {
                    if(bit1/(1<<i)%2 != 0 && bit2/(1<<j)%2 != 0) {
                        choose.push_back(make_pair(i, j));
                    }
                }
            }
            if(choose.size() != H2*W2) continue;

            bool flag = true;
            int cnt = 0;
            rep(i, 0, H2) {
                rep(j, 0, W2) {
                    if(A[choose[cnt].first][choose[cnt].second] != B[i][j]) flag = false;
                    cnt++;
                }
            }
            if(flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}