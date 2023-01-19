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
using ll=long long;

int main() {
    int N; cin >> N;
    vector<int> A(N), tmp(N);
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<int> ans;
    int i = N-1;
    while(i >= 0) {
        int j = i, tmp = A[i], cnt = 0;
        while(tmp == A[j]) {
            cnt++;
            j--;
        }
        ans.push_back(cnt);
        i = j;
    }

    for(int i=0; i<ans.size(); i++) cout << ans[i] << endl;
    for(int i=0; i<N-ans.size(); i++) cout << 0 << endl;
}