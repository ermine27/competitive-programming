#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n), dp(n, INT_MAX);
    for (int i = 0; i < n; i++) cin >> h[i];
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i + j >= n)
                continue;
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}
