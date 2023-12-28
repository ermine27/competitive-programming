#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

int main() {
    int n;
    cin >> n;
    vl a(n), dp(n + 2);
    rep(i, n) { cin >> a[i]; }
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = max(a[0] + a[2], a[1]);
    for (int i = 3; i < n; i++) {
        dp[i] = max(dp[i - 1], max(dp[i - 2], dp[i - 3]) + a[i]);
    }
    cout << dp[n - 1] << endl;

    return 0;
}
