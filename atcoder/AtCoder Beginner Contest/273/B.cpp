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
    ll X;
    int K;
    cin >> X >> K;
    ll p_ten = 1;
    for(int i=0; i<K; i++) {
        ll x = (X/p_ten)%10;
        X -= x*p_ten;
        if(x >= 5) X += 10*p_ten;
        p_ten *= 10;
    }
    cout << X << endl;
}