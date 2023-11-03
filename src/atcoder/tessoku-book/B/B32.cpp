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

// dp[i] =
//   T (i>=A and dp[i-A] = F) or (i>=B and dp[i-B] = F)
//   F (上記以外)

int main() {
    int n, k;
    cin >> n >> k;
    vi a(k);
    rep(i, k) cin >> a[i];

    vi dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        rep(j, k) {
            if (i >= a[j] && !dp[i - a[j]])
                ok = false;
        }
        dp[i] = (ok ? 0 : 1);
    }

    cout << (dp[n] ? "First" : "Second") << endl;
    return 0;
}
