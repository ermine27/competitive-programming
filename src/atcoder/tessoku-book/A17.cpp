#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
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
    dp[1] = a[0];
    vi ans;
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + a[i - 1], dp[i - 2] + b[i - 2]);
    }

    vi route = {n};
    int p = n;
    while (p > 0) {
        if (p > 1 && dp[p] - dp[p - 2] == b[p - 2]) {
            route.push_back(p - 1);
            p--;
        } else {
            if (dp[p] - dp[p - 1] == a[p - 1]) {
                route.push_back(p);
            }
        }
        p--;
    }
    reverse(route.begin(), route.end());
    int sz = route.size();
    cout << sz << endl;
    rep(i, sz) { cout << route[i] << ' '; }
    cout << endl;
    return 0;
}
