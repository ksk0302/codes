#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {1, 1, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
    int key = 12;
    auto iter = lower_bound(vec.begin(), vec.end(), key);

    // 5 を検索
    if (iter != vec.end() && *iter == key) {
        cout << key << " is found at " << distance(vec.begin(), iter) << "\n";
    } else {
        cout << key << "is NOT found." << "\n";
    }

    return 0;
}