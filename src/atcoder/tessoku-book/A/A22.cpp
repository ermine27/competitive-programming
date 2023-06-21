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
    vi a(n + 1), b(n + 1), dp(n + 1, -1e6);
    dp[0] = 0;
    rep(i, n - 1) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, n - 1) {
        cin >> b[i];
        b[i]--;
    }
    for (int i = 0; i < n - 1; i++) {
        chmax(dp[a[i]], dp[i] + 100);
        chmax(dp[b[i]], dp[i] + 150);
    }

    cout << dp[n - 1] << endl;
    return 0;
}
