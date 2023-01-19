#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, M, T;
    cin >> N >> M >> T;
    vector<long long> A(N), X(M), Y(M);
    for(int i=1; i<N; i++) cin >> A[i];
    for(int i=1; i<=M; i++) cin >> X[i] >> Y[i];

    int cnt_M = 1;
    for(int i=2; i<=N; i++) {
        T -= A[i-1];
        if(i == X[cnt_M]) {
            T += Y[cnt_M];
            cnt_M++;
        }
        if(T <= 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}