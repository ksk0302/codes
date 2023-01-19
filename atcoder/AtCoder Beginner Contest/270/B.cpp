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
    int X, Y, Z;
    cin >> X >> Y >> Z;

    if(X * Y < 0) {
        cout << abs(X) << endl;
        return 0;
    } else {
        if(abs(X) < abs(Y)) {
            cout << abs(X) << endl;
            return 0;
        }
        if(Y * Z < 0) {
            cout << abs(X) + 2*abs(Z) << endl;
            return 0;
        } else {
            if(abs(Z) < abs(Y)) {
                cout << abs(X) << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}