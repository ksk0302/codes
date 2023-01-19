#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long answer = LLONG_MIN;
    vector<long long> a(n), sum(n-m+1, 0), ans(n-m+1, 0);
    for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<m; i++) sum[0] += a[i];
    for(int i=1; i<=n-m; i++) sum[i] = sum[i-1] - a[i-1] + a[m+i-1];
    for(int i=1; i<=m; i++) ans[0] += a[i-1]*i;
    for(int i=1; i<=n-m; i++) ans[i] = ans[i-1] - sum[i-1] + a[m+i-1]*m;
    for(int i=0; i<=n-m; i++) answer = max(answer, ans[i]);
    cout << answer << endl;
}