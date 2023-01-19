#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int r, c;
    vector<vector<int>> a(2, vector<int>(2));

    cin >> r >> c;
    for(int i=0; i<2; i++) for(int j=0; j<2; j++) cin >> a[i][j];

    cout << a[r-1][c-1] << endl;
}