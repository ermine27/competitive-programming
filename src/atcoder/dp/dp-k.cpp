#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), dp(k + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            int t = i - a[j];
            if (t >= 0 && !dp[t])
                dp[i] = 1;
        }
    }

    cout << (dp[k] ? "First" : "Second") << endl;
    return 0;
}
