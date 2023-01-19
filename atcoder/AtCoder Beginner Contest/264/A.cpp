#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
using namespace std;

int main() {
    int l, r; cin >> l >> r;
    string s = "atcoder";
    for(int i=l; i<=r; i++) {
        cout << s[i-1];
    }
    cout << endl;
}