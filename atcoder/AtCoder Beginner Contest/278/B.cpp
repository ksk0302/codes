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
    int H, M; cin >> H >> M;
    int a = H / 10, b = H % 10, c = M / 10, d = M % 10;
    int hour = a*10 + c, minute = b*10 + d;
    if(hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59) cout << H << " " << M << endl;
    else {
        while(true) {
            hour = a*10 + c;
            minute = b*10 + d;
            if(hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59) {
                cout << a*10+b << " " << c*10+d << endl;
                return 0;
            }
            d++;
            if(d == 10) {
                d = 0;
                c++;
                if(c == 6) {
                    c = 0; d = 0;
                    b++;
                    if(b == 10) {
                        b = 0; a++;
                    }
                }
            }
            if(a*10 + b == 24) {
                a = 0; b = 0;
            }
        }
    }
}