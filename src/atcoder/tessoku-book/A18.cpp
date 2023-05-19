#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#if 0
int main() {
    int n, s;
    cin >> n >> s;
    vi a(n);
    rep(i, n) cin >> a[i];

    vector<vi> dp(n + 1, vi(s + 1));
    dp[0][0] = 1;
    rep(i, n) {
        rep(j, s + 1) {
            if (!dp[i][j])
                continue;
            int t = j + a[i];
            if (t <= s) {
                dp[i + 1][t] = 1;
            }
            dp[i + 1][j] = 1;
        }
    }

    cout << (dp[n][s] ? "Yes" : "No") << endl;
    return 0;
}
#endif

int main() {
    int n, s;
    cin >> n >> s;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi dp(s + 1);
    dp[0] = 1;
    rep(i, n) {
        for (int j = s - a[i]; j >= 0; j--) {
            dp[j + a[i]] += dp[j];
        }
    }

    cout << (dp[s] ? "Yes" : "No") << endl;
    return 0;
}
