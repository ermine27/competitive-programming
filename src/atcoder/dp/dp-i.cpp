#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    dp[0][0] = 1.0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i + 1][j + 1] += dp[i][j] * p[i];
            dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
        }
    }

    double ans = 0.0;
    for (int i = n / 2 + 1; i <= n; i++) {
        ans += dp[n][i];
    }

    cout << setprecision(12) << ans << endl;
    return 0;
}
