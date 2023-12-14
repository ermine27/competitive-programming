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
    vi h(n + 1);
    rep(i, n) cin >> h[i];

    vi dp(n + 1, 2e9);
    dp[0] = 0;
    rep(i, n - 1) {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
    }

    cout << dp[n - 1] << endl;
    return 0;
}
