#include <bits/stdc++.h>
using namespace std;

int main() {
    const string str = "atcoder";
    int l, r;
    cin >> l >> r;

    cout << str.substr(l - 1, r - l + 1) << endl;
    return 0;
}
