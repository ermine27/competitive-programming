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
    int N, W;
    cin >> N >> W;
    vi w(N), v(N);
    rep(i, N) cin >> w[i] >> v[i];

    const int INF = 2e9;
    const int VMAX = N * 1000 + 1;
    vector<vi> dp(N + 1, vi(VMAX + 1, INF));
    dp[0][0] = 0;
    rep(i, N) {
        rep(j, VMAX + 1) {
            if (dp[i][j] == INF)
                continue;
            chmin(dp[i + 1][j], dp[i][j]);
            int nxt = dp[i][j] + w[i];
            if (nxt <= W) {
                chmin(dp[i + 1][j + v[i]], nxt);
            }
        }
    }

    int ans = 0;
    rep(i, VMAX + 1) {
        if (dp[N][i] <= W)
            ans = i;
    }
    cout << ans << endl;
    return 0;
}
