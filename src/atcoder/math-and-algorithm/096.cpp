#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        sum += t[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sum; j++) {
            if (dp[i][j]) {
                dp[i + 1][j] += dp[i][j];
                if (j + t[i] <= sum) {
                    dp[i + 1][j + t[i]] += dp[i][j];
                }
            }
        }
    }

    int ans = (sum + 1) / 2;
    while (!dp[n][ans]) ans++;
    cout << ans << endl;
    return 0;
}
