#include <iostream>
using namespace std;

#define n 998244353

int main() {
    long long N;
    cin >> N;

    if(N > 0) {
        for(int i=0; i<n; i++) {
            if((N-i) % n == 0) {
                cout << i << endl;
                return 0;
            }
        }
    } else {
        for(int i=n-1; i>=0; i--) {
            if((N-i) % n == 0) {
                cout << i << endl;
                return 0;
            }
        }
    }
}