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
    int n, s;
    cin >> n >> s;
    vi a(n);
    rep(i, n) cin >> a[i];
    vector<vi> dp(n + 1, vi(s + 1, 0));
    dp[0][0] = 1;

    rep(i, n) {
        rep(j, s + 1) {
            chmax(dp[i + 1][j], dp[i][j]);
            int nxt = j + a[i];
            if (nxt <= s) {
                chmax(dp[i + 1][nxt], dp[i][j]);
            }
        }
    }

    if (!dp[n][s]) {
        cout << -1 << endl;
        return 0;
    }

    int cur = s;
    vi ans;
    for (int i = n - 1; i >= 0; i--) {
        int pre = cur - a[i];
        if (pre >= 0 && dp[i][pre]) {
            cur = pre;
            ans.push_back(i + 1);
        }
    }

    sort(ans.begin(), ans.end());
    int size = ans.size();
    cout << size << endl;
    rep(i, size) { cout << ans[i] << ' '; }
    cout << endl;
    return 0;
}
