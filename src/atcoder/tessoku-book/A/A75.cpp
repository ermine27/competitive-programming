/*
設問を締切の昇順にソートしてからDPで解く。
DP[i][j] = j分経過した時点でi問目までのうち何問解いたか
*/
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
    const int DMAX = 1441;
    int n, ans = 0;
    cin >> n;

    vector<pair<int, int>> dt(n);
    rep(i, n) {
        int ti, di;
        cin >> ti >> di;
        dt[i] = {di, ti};
    }
    sort(dt.begin(), dt.end());

    vector<vector<int>> dp(n + 1, vector<int>(DMAX, -1));
    dp[0][0] = 0;
    rep(i, n) {
        rep(j, DMAX) {
            chmax(dp[i + 1][j], dp[i][j]);
            if (j + dt[i].second <= dt[i].first) {
                chmax(dp[i + 1][j + dt[i].second], dp[i][j] + 1);
            }
        }
    }

    rep(j, DMAX) { chmax(ans, dp[n][j]); }

    cout << ans << endl;
    return 0;
}
