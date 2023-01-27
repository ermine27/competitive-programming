#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }

    if (sum % 2) {
        cout << "impossible" << endl;
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j + w[i] < n * 100 + 1) {
                dp[i + 1][j + w[i]] += dp[i][j];
            }

            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }

    cout << (dp[n][sum / 2] ? "possible" : "impossible") << endl;
    return 0;
}
