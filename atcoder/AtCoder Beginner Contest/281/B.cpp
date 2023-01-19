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
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)

int main() {
    string S; cin >> S;
    bool flag = true;
    if(S.size() == 8) {
        if(S[0] < 'A' || S[0] > 'Z') flag = false;
        if(S[7] < 'A' || S[7] > 'Z') flag = false;
        rep(i, 1, 7) {
            int num = S[i] - '0';
            if(num < 0 || num > 9) flag = false;
            if(i == 1 && num == 0) flag = false;
        }
    } else {
        flag = false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}