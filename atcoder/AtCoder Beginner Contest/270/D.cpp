#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
using namespace std;
using ll=long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    for(int i=0; i<K; i++) cin >> A[i];

    sort(A.begin(), A.end());
    ll tkh = 0;
    int max_i = K-1, i = K-1;
    bool who = true;
    while(N > 0) {
        if(who) {
            while(A[i] > N) i--;
            tkh += A[i];
            N -= A[i];
            who = false;
            max_i = i;
        } else {
            while(A[i] > N) i--;
            N -= A[i];
            who = true;
            max_i = i;
        }
        if(i == -1) i = max_i;
    }
    cout << tkh << endl;
}