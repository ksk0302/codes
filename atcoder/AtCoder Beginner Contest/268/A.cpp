#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
using namespace std;

int main() {
    map<int, int> a;
    for(int i=0; i<5; i++) {
        int tmp; cin >> tmp;
        a[tmp]++;
    }

    int ans = 0;
    for(auto i : a) ans++;
    cout << ans << endl;
}