#include <iostream>
using namespace std;

int main() {
    int X, Y, N;
    cin >> X >> Y >> N;

    int ans = 0;
    if(X*3 > Y) {
        while(N>0) {
            if(N>=3) {
                ans += Y;
                N -= 3;
            } else {
                ans += X;
                N -= 1;
            }
        }
    } else {
        ans = X*N;
    }
    cout << ans << endl;
}