#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
using namespace std;
using ll=long long;

int main() {
    int N; cin >> N;
    int ans = 0;
    for(int i=0; i<N; i++) {
        int a; cin >> a;
        ans += a;
    }
    cout << ans << endl;
}