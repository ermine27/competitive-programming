/*
解法２：ダブリング
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<vector<int>> doubling(63, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> doubling[0][i];
        doubling[0][i]--;
    }
    for (int i = 0; i + 1 < 63; i++) {
        for (int j = 0; j < n; j++) {
            doubling[i + 1][j] = doubling[i][doubling[i][j]];
        }
    }

    int ans = 0;
    for (int i = 0; i < 63; i++) {
        if (k & (1LL << i))
            ans = doubling[i][ans];
    }

    cout << ans + 1 << endl;
    return 0;
}
