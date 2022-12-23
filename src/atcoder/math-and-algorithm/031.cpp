#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> dp(n);

    for (int i = 0; i < n; i++) {
        cin >> dp[i];
        if (i >= 2) {
            dp[i] = max(dp[i - 1], dp[i - 2] + dp[i]);
        }
    }

    cout << dp[n - 1] << endl;
    return 0;
}
