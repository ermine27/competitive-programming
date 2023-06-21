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
    const int NA = 999;
    int n, m;
    cin >> n >> m;
    vector<bitset<10>> a(m);
    rep(i, m) {
        bitset<10> b = 0;
        rep(j, n) {
            int a;
            cin >> a;
            if (a == 1)
                b.set(j);
        }
        a[i] = b;
    }

    int bm = pow(2, n);
    vector<vi> dp(m + 1, vi(bm, NA));
    dp[0][0] = 0;

    rep(i, m) {
        rep(j, bm) {
            int g = (int)a[i].to_ulong();
            chmin(dp[i + 1][j | g], dp[i][j] + 1);
            chmin(dp[i + 1][j], dp[i][j]);
        }
    }

    int ans = dp[m][bm - 1];
    if (ans == NA)
        ans = -1;
    cout << ans << endl;
    return 0;
}
