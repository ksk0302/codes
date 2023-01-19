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

int main() {
    int H, W, rs, cs, N;
    cin >> H >> W >> rs >> cs >> N;
    map<int, vector<int>> Rwalls;
    map<int, vector<int>> Cwalls;
    rep(i, 0, N) {
        int r, c; cin >> r >> c;
        Rwalls[r].push_back(c);
        Cwalls[c].push_back(r);
    }

    for(auto &i : Rwalls) sort(i.second.begin(), i.second.end());
    for(auto &i : Cwalls) sort(i.second.begin(), i.second.end());

    int Q; cin >> Q;
    vector<pair<int, int>> ans(Q);
    rep(q, 0, Q) {
        char d;
        int l;
        cin >> d >> l;
        if(d == 'L') {
            auto itr = Rwalls.find(rs);
            int left = 0;
            if(itr != Rwalls.end()) {
                veci &vec = itr->second;
                auto wall = lower_bound(vec.begin(), vec.end(), cs);
                if(wall != vec.begin()) {
                    wall--; left = *wall;
                }
            }
            cs = max(cs-l, left+1);
        } else if(d == 'U') {
            auto itr = Cwalls.find(cs);
            int left = 0;
            if(itr != Cwalls.end()) {
                veci &vec = itr->second;
                auto wall = lower_bound(vec.begin(), vec.end(), rs);
                if(wall != vec.begin()) {
                    wall--; left = *wall;
                }
            }
            rs = max(rs-l, left+1);
        } else if(d == 'R') {
            auto itr = Rwalls.find(rs);
            int right = W+1;
            if(itr != Rwalls.end()) {
                veci &vec = itr->second;
                auto wall = upper_bound(vec.begin(), vec.end(), cs);
                if(wall != vec.end()) right = *wall;
            }
            cs = min(cs+l, right-1);
        } else if(d == 'D') {
            auto itr = Cwalls.find(cs);
            int right = H+1;
            if(itr != Cwalls.end()) {
                veci &vec = itr->second;
                auto wall = upper_bound(vec.begin(), vec.end(), rs);
                if(wall != vec.end()) right = *wall;
            }
            rs = min(rs+l, right-1);
        }
        ans[q] = make_pair(rs, cs);
    }
    
    rep(q, 0, Q) cout << ans[q].first << " " << ans[q].second << endl;
}