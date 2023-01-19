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
using ll=long long;

int main() {
    int N; cin >> N;
    int ans = 1;
    for(int i=2; i<=N; i++) ans *= i;
    cout << ans << endl;
}