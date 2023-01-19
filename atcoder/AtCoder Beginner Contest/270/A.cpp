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
    int A, B;
    cin >> A >> B;
    int ans = 0;
    bool flag1 = false, flag2 = false, flag4 = false, flag6 = false;
    if(A%2 == 1) {
        flag1 = true;
        A--;
    }
    if(B%2 == 1) {
        flag1 = true;
        B--;
    }
    if(A==6 || B==6) flag6 = true;
    if(A==4 || B==4) flag4 = true;
    if(A==2 || B==2) flag2 = true;
    if(flag6) ans += 6;
    else if(flag4 && flag2) ans += 6;
    else if(flag4) ans += 4;
    else if(flag2) ans += 2;
    
    if(flag1) ans += 1;
    cout << ans << endl;
}