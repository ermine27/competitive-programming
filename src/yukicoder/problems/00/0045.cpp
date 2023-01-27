#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> dp(n + 1);
    dp[1] = v[0];
    for (int i = 1; i < n; i++) {
        dp[i + 1] = max(dp[i], dp[i - 1] + v[i]);
    }

    cout << dp[n] << endl;
    return 0;
}
