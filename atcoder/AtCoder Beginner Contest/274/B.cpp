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
    int H, W; cin >> H >> W;
    vector<string> C(H);
    for(int i=0; i<H; i++) cin >> C[i];
    vector<int> X(W, 0);
    for(int j=0; j<W; j++) {
        for(int i=0; i<H; i++) {
            if(C[i][j] == '#') X[j]++;
        }
    }
    for(int i=0; i<W; i++) cout << X[i] << " ";
    cout << endl;
}