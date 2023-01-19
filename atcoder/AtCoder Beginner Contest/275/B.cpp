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

int main() {
    unsigned long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll m = 998244353;
    a %= m; b %= m; c %= m; d %= m; e %= m; f %= m;
    ll abc = (((a*b) % m) * c) % m, def = (((d*e) % m) * f) % m;
    ll ans = (abc - def) % m;
    if(ans < 0) ans += m;
    cout << ans << endl;
}