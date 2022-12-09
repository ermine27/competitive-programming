#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(s + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i + 1][j] += dp[i][j];
            if (j + a[i] <= s)
                dp[i + 1][j + a[i]] += dp[i][j];
        }
    }

    cout << (dp[n][s] ? "Yes" : "No") << endl;
    return 0;
}
