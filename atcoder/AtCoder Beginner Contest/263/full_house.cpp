#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
using namespace std;

int main() {
    int cnt = 0;
    map<int, int> card;
    for(int i=0; i<5; i++) {
        int a; cin >> a;
        card[a]++;
    }
    for(auto c : card) {
        if(c.second > 3) {
            cout << "No" << endl; return 0;
        }
        cnt++;
    }
    if(cnt == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}