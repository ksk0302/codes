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
using Graph = vector<vector<int>>;
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)

int main() {
    int N, M; cin >> N >> M;
    vecll A(N);
    ll sumA = 0;
    rep(i, 0, N) {
        cin >> A[i];
        sumA += A[i];
    }

    sort(A.begin(), A.end());
    ll tmpmax = 0, tmpsum = A[0];
    rep(i, 1, N) {
        if(A[i] - A[i-1] <= 1) {
            tmpsum += A[i];
            if(i == N-1 && A[i] == M-1 && A[0] == 0) {
                int j = 1;
                while(A[j] - A[j-1] <= 1) {
                    tmpsum += A[j];
                    j++;
                }
            }
        } else {
            tmpmax = max(tmpmax, tmpsum);
            tmpsum = A[i];
        }
    }
    tmpmax = max(tmpmax, tmpsum);

    cout << max((ll)0, sumA - tmpmax) << endl;
}