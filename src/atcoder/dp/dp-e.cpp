#include <bits/stdc++.h>
using namespace std;

// clang-format off
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

int main() {
    int n, wmax;
    cin >> n >> wmax;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    const int vmax = 1e5 + 9;
    vector<vector<long long>> dp(n + 1, vector<long long>(vmax + 1, INT_MAX / 2));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= vmax; j++) {
            if (j + v[i] <= vmax) {
                chmin(dp[i + 1][j + v[i]], dp[i][j] + w[i]);
            }
            chmin(dp[i + 1][j], dp[i][j]);
        }
    }

    long long ans = 0;
    for (int j = 0; j < vmax; j++) {
        if (dp[n][j] <= wmax)
            ans = j;
    }
    cout << ans << endl;
}
