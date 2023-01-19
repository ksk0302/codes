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
    int N; cin >> N;
    int tmp1 = N%16, tmp2 = N/16;
    string one_digit = to_string(tmp1), ten_digit = to_string(tmp2);
    if(ten_digit == "10") ten_digit = "A";
    if(ten_digit == "11") ten_digit = "B";
    if(ten_digit == "12") ten_digit = "C";
    if(ten_digit == "13") ten_digit = "D";
    if(ten_digit == "14") ten_digit = "E";
    if(ten_digit == "15") ten_digit = "F";
    if(one_digit == "10") one_digit = "A";
    if(one_digit == "11") one_digit = "B";
    if(one_digit == "12") one_digit = "C";
    if(one_digit == "13") one_digit = "D";
    if(one_digit == "14") one_digit = "E";
    if(one_digit == "15") one_digit = "F";
    string ans = ten_digit + one_digit;
    cout << ans << endl;
}