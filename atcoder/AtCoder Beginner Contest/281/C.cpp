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
using veci = vector<int>;
using vecll = vector<ll>;
using vecd = vector<double>;
using vveci = vector<veci>;
using vvecll = vector<vecll>;
using vvecd = vector<vecd>;
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)

int main() {
    ll N, T; cin >> N >> T;
    vecll A(N);
    ll sumA = 0;
    rep(i, 0, N) {
        cin >> A[i];
        sumA += A[i];
    }
    T = T - (T/sumA)*sumA;
    int index = 0;
    while(true) {
        if(T - A[index] > 0) {
            T -= A[index];
            index++;
        } else {
            break;
        }
    }
    cout << index + 1 << " " << T << endl;
}