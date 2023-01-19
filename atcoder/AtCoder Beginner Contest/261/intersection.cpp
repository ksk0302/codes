#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
using namespace std;

int main() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if(r1 <= l2 || r2 <= l1) cout << 0 << endl;
    else {
        int left = max(l1, l2), right = min(r1, r2);
        cout << right - left << endl;
    }
}