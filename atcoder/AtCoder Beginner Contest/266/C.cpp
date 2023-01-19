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

double calc(pair<double, double> l, pair<double, double> n, pair<double, double> m) {
    double ax = n.first - l.first, ay = n.second - l.second;
    double bx = m.first - l.first, by = m.second - l.second;
    double a_size = sqrt(ax*ax+ay*ay), b_size = sqrt(bx*bx+by*by);
    double cross = ax*by - ay*bx;
    return asin(cross/(a_size*b_size));
}

int main() {
    pair<double, double> a, b, c, d;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
    vector<double> angles(4);
    angles[0] = calc(a, b, d);
    angles[1] = calc(b, c, a);
    angles[2] = calc(c, d, b);
    angles[3] = calc(d, a, c);
    rep(i, 0, 4) {
        if(angles[i] <= 0.0 || angles[i] >= M_PI) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}