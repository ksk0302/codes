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
    int N, M; cin >> N >> M;
    vector<vector<bool>> join(N);
    for(int i=0; i<N; i++) join[i].assign(N, false);
    for(int i=0; i<M; i++) {
        int k; cin >> k;
        vector<int> x(k);
        for(int j=0; j<k; j++) cin >> x[j];
        for(int s=0; s<k; s++) {
            for(int t=s+1; t<k; t++) {
                join[x[s]-1][x[t]-1] = true;
                join[x[t]-1][x[s]-1] = true;
            }
        }
    }

    bool flag = true;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i == j) continue;
            if(!join[i][j]) flag = false;
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}