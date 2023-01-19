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
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)
using ll = long long;

int main() {
    int N; cin >> N;
    vector<string> S(N);
    rep(i, 0, N) cin >> S[i];
    map<string, int> num;
    bool flag1 = true, flag2 = true, flag3 = true;
    rep(i, 0, N) {
        if(S[i][0] != 'H' && S[i][0] != 'D' && S[i][0] != 'C' && S[i][0] != 'S') flag1 = false;
    }
    rep(i, 0, N) {
        if(S[i][1] != 'A' && S[i][1] != '2' && S[i][1] != '3' && S[i][1] != '4' && S[i][1] != '5' && S[i][1] != '6' && S[i][1] != '7' && S[i][1] != '8' && S[i][1] != '9' && S[i][1] != 'T' && S[i][1] != 'J' && S[i][1] != 'Q' && S[i][1] != 'K') flag2 = false;
    }
    rep(i, 0, S.size()) num[S[i]]++;
    for(auto i : num) if(i.second >= 2) flag3 = false;
    if(flag1 && flag2 && flag3) cout << "Yes" << endl;
    else cout << "No" << endl;
}