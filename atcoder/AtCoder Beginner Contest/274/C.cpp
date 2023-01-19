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

int N;

vector<int> bfs(vector<vector<int>> G) {
    queue<int> que;
    vector<int> dist(2*N+2, -1);
    dist[1] = 0;
    que.push(1);

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for(auto i : G[v]) {
            if(dist[i] != -1) continue;
            que.push(i);
            dist[i] = dist[v] + 1;
        }
    }
    return dist;
}

int main() {
    cin >> N;
    vector<int> A(N+1);
    for(int i=1; i<=N; i++) cin >> A[i];
    vector<vector<int>> G(2*N+2);
    for(int i=1; i<=N; i++) {
        G[A[i]].push_back(2*i);
        G[A[i]].push_back(2*i+1);
    }

    vector<int> ans = bfs(G);
    for(int i=1; i<=2*N+1; i++) cout << ans[i] << endl;
}