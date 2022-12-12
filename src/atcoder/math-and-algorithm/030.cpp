#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> u(n), v(n);
    for (int i = 0; i < n; i++) cin >> u[i] >> v[i];
    vector<vector<long long>> dp(n + 1, vector<long long>(w + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i + 1][j] = dp[i][j];
            if (j >= u[i]) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - u[i]] + v[i]);
            }
        }
    }

    cout << dp[n][w] << endl;
    return 0;
}
