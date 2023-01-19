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
    double A, B; cin >> A >> B;
    double g1 = pow(1.0*A/B/2.0, 1.0*2/3);
    g1 = max(1.0, floor(g1));
    double g2 = g1 + 1;

    double ans = min((g1-1.0)*B + A/g1*sqrt(g1), (g2-1.0)*B + A/g2*sqrt(g2));
    printf("%.10lf\n", ans);
}