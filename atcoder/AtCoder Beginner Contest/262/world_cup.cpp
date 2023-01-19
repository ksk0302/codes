#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
using namespace std;

int main() {
    int y; cin >> y;
    for(int i=0; i<4; i++) if((y+i)%4 == 2) cout << y+i << endl;
}