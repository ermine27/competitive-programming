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
    vi a(n);
    rep(i, n) cin >> a[i];

    vi dp(n);
    dp[0] = a[0];
    int len = 1;
    rep(i, n) {
        if (dp[len - 1] < a[i]) {
            dp[len++] = a[i];
        } else {
            int idx = lower_bound(dp.begin(), dp.begin() + len, a[i]) - dp.begin();
            dp[idx] = a[i];
        }
    }

    cout << len << endl;
    return 0;
}
