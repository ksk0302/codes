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
    int N; cin >> N;
    vector<int> H(N);
    for(int i=0; i<N; i++) cin >> H[i];
    int ans = 0, maxH = H[0];
    for(int i=0; i<N; i++) {
        if(maxH < H[i]) {
            maxH = H[i];
            ans = i;
        }
    }
    cout << ans + 1 << endl;
}