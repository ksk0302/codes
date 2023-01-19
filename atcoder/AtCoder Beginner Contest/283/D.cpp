#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;
using ll = long long;
using veci = vector<int>;
using vecll = vector<ll>;
using vecd = vector<double>;
using vveci = vector<veci>;
using vvecll = vector<vecll>;
using vvecd = vector<vecd>;
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)

int main() {
    string S; cin >> S;
    int N = S.size();
    vector<bool> alphabets(26);
    vector<vector<char>> balls(N);

    int now = 0;
    rep(i, 0, N) {
        if(S[i] == '(') now++;
        else if(S[i] == ')') {
            for(auto c : balls[now]) alphabets[c-'a'] = false;
            balls[now].clear();
            now--;
        } else {
            if(alphabets[S[i]-'a']) {
                cout << "No" << endl;
                return 0;
            }
            balls[now].push_back(S[i]);
            alphabets[S[i]-'a'] = true;
        }
    }

    cout << "Yes" << endl;
}