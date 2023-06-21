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
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c[i];

    vector<vl> dp(h, vl(w));
    dp[0][0] = 1;

    rep(i, h) {
        rep(j, w) {
            if (c[i][j] == '#')
                continue;
            if (j < w - 1 && c[i][j + 1] == '.')
                dp[i][j + 1] += dp[i][j];
            if (i < h - 1 && c[i + 1][j] == '.')
                dp[i + 1][j] += dp[i][j];
        }
    }

    cout << dp[h - 1][w - 1] << endl;
    return 0;
}
