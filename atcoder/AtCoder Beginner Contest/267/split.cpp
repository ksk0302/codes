#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    string s;
    cin >> s;

    if(!(s[0] - '0')) {
        vector<int> r(7, 0);
        if(s[6] == '1') r[0]++;
        if(s[3] == '1') r[1]++;
        if(s[1] == '1') r[2]++;
        if(s[7] == '1') r[2]++;
        if(s[0] == '1') r[3]++;
        if(s[4] == '1') r[3]++;
        if(s[8] == '1') r[4]++;
        if(s[2] == '1') r[4]++;
        if(s[5] == '1') r[5]++;
        if(s[9] == '1') r[6]++;
        for(int i=1; i<6; i++) {
            bool flag1 = false, flag2 = false;
            if(r[i] == 0) {
                for(int j=0; j<i; j++) if(r[j] != 0) flag1 = true;
                for(int j=i+1; j<7; j++) if(r[j] != 0) flag2 = true;
                if(flag1 && flag2) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        cout << "No" << endl;
    } else {
        cout << "No" << endl;
    }
}