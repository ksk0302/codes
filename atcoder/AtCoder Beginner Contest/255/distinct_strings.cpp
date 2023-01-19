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
    string S; cin >> S;
    set<char> s;
    for(int i=0; i<3; i++) s.insert(S[i]);
    if(s.size() == 1) cout << 1 << endl;
    else if(s.size() == 2) cout << 3 << endl;
    else cout << 6 << endl;
}