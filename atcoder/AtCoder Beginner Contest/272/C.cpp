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
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    bool flag = false;
    int odd_cnt = 0, even_cnt = 0;
    for(int i=0; i<N; i++) {
        if(A[i]%2 == 1) odd_cnt++;
        else even_cnt++;
        if(odd_cnt >= 2 || even_cnt >= 2) {
            flag = true;
            break;
        }
    }
    if(flag) {
        int max_even = 0, second_max_even = 0;
        int max_odd = 0, second_max_odd = 0;
        for(int i=N-1; i>=0; i--) {
            if(A[i]%2 == 1 && max_odd == 0) max_odd = A[i];
            else if(A[i]%2 == 1 && max_odd != 0) {
                second_max_odd = A[i];
                break;
            }
        }
        for(int i=N-1; i>=0; i--) {
            if(A[i]%2 == 0 && max_even == 0) max_even = A[i];
            else if(A[i]%2 == 0 && max_even != 0) {
                second_max_even = A[i];
                break;
            }
        }
        cout << max(max_odd + second_max_odd, max_even + second_max_even) << endl;
    } else {
        cout << -1 << endl;
    }
}