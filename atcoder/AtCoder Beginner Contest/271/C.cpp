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
    int N; cin >> N;
    map<int, int> manga;
    rep(i, 0, N) {
        int a; cin >> a;
        manga[a]++;
    }
    
    int sold = 0;
    vector<bool> books(N+1, false);
    stack<int> S;
    S.push(-1);
    for(auto m : manga) {
        if(m.first <= N) {
            books[m.first] = true;
            S.push(m.first);
            if(m.second > 1) sold += m.second - 1;
        } else {
            sold += m.second;
        }
    }

    int read = 0;
    rep(i, 1, N+1) {
        if(books[i]) read++;
        else if(sold >= 2) {
            sold -= 2;
            read++;
        } else if(sold == 1) {
            int tmp = S.top(); S.pop(); sold--;
            if(tmp <= i) break;
            books[tmp] = false;
            read++;
        } else {
            int tmp1 = S.top(); S.pop();
            if(tmp1 <= i) break;
            int tmp2 = S.top(); S.pop();
            if(tmp2 <= i) break;
            books[tmp1] = false;
            books[tmp2] = false;
            read++;
        }
    }
    cout << read << endl;
}