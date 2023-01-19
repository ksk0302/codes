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
    bool flag = true;
    int cmp = 0;
    rep(i, 0, N) {
        int tmp = a[i];
        while(true) {
            if(tmp%2 == 0) tmp /= 2;
            if(tmp%3 == 0) tmp /= 3;
            if(tmp%2 != 0 &&  tmp%3 != 0) break;
        }
        if(i == 0) cmp = tmp;
        if(cmp != tmp) flag = false;
    }

    if(flag) {
        vector<int> p2(N), p3(N);
        int min_2 = 100, min_3 = 100;
        rep(i, 0, N) {
            int tmp = a[i], tmp_2 = 0, tmp_3 = 0;
            while(true) {
                if(tmp%2 == 0) {
                    tmp /= 2; tmp_2++;
                }
                if(tmp%3 == 0) {
                    tmp /= 3; tmp_3++;
                }
                if(tmp%2 != 0 &&  tmp%3 != 0) break;
            }
            p2[i] = tmp_2; p3[i] = tmp_3;
            min_2 = min(min_2, tmp_2);
            min_3 = min(min_3, tmp_3);
        }
        int ans = 0;
        rep(i, 0, N) ans += (p2[i] - min_2) + (p3[i] - min_3);
        cout << ans << endl;
    } else cout << -1 << endl;
}