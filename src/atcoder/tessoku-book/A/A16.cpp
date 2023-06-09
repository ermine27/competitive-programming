#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repe(i, n) for (int i = 1; i <= (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int n;
    cin >> n;
    vi a(n - 1), b(n - 2), dp(n + 1, 1e9);
    rep(i, n - 1) cin >> a[i];
    rep(i, n - 2) cin >> b[i];
    dp[0] = 0;
    rep(i, n - 1) {
        dp[i + 1] = min(dp[i + 1], dp[i] + a[i]);
        if (i < n - 2) {
            dp[i + 2] = min(dp[i + 2], dp[i] + b[i]);
        }
    }

    cout << dp[n - 1] << endl;
    return 0;
}
