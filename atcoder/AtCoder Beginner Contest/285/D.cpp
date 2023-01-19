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
using veci = vector<int>;
using vecll = vector<ll>;
using vecd = vector<double>;
using vveci = vector<veci>;
using vvecll = vector<vecll>;
using vvecd = vector<vecd>;
using Graph = vector<vector<int>>;
#define rep(i, l, r) for(int i=l; i<r; i++)
#define rrep(i, l, r) for(int i=r-1; i>=l; i--)

map<string, vector<string>> G;
set<string> visited;
stack<string> visited2;

void dfs(string s) {

}

int main() {
    int N; cin >> N;
    rep(i, 0, N) {
        string s, t; cin >> s >> t;
        G[s].push_back(t);
    }
    
    auto begin = G.begin(), end = G.end();
    for (auto iter = begin; iter != end; iter++) {
        if(visited[iter->first] == visited.end()) dfs(iter->first);
    }
}