#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#include <map>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> p(N); for(int i=0; i<N; i++) cin >> p[i];
    vector<int> dist(N);
    for(int i=0; i<N; i++) {
        if(p[i] >= i) dist[i] = p[i] - i;
        else dist[i] = N - (i - p[i]);
    }

    map<int, int> human;
    for(int i=0; i<N; i++) {
        if(dist[i] != 0) human[dist[i]-1]++;
        else human[N-1]++;
        human[dist[i]]++;
        if(dist[i] != N-1) human[dist[i]+1]++;
        else human[0]++;
    }

    int ans = -1;
    for(auto h : human) {
        ans = max(ans, h.second);
    }
    cout << ans << endl;
}