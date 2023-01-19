#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
using namespace std;

int main() {
    vector<string> S(10);
    for(int i=0; i<10; i++) cin >> S[i];

    int A, B, C ,D;
    bool flag = false;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(S[i][j] == '#') {
                A = i+1; C = j+1; flag = true; break;
            }
        }
        if(flag) break;
    }

    flag = false;
    for(int i=9; i>=0; i--) {
        for(int j=9; j>=0; j--) {
            if(S[i][j] == '#') {
                B = i+1; D = j+1; flag = true; break;
            }
        }
        if(flag) break;
    }
    cout << A << " " << B << endl;
    cout << C << " " << D << endl;
}