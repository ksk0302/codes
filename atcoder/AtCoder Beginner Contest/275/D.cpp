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

map<ll, ll> memo;

ll rec(ll N) {
    if(N == 0) return 1;
    if(memo[N/2] == 0) memo[N/2] = rec(N/2);
    if(memo[N/3] == 0) memo[N/3] = rec(N/3);
    return memo[N/2] + memo[N/3];
}

int main() {
    ll N; cin >> N;
    cout << rec(N) << endl;
}