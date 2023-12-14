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
    int n, k = 1;
    cin >> n;
    vi h(n + 1), r = {n};
    rep(i, n) cin >> h[i];

    vi dp(n + 1, 2e9);
    dp[0] = 0;
    rep(i, n - 1) {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
    }

    int i = n - 1;
    while (i > 0) {
        if (dp[i - 2] + abs(h[i] - h[i - 2]) == dp[i]) {
            i--;
        }
        i--;
        r.push_back(i + 1);
        k++;
    }

    cout << k << endl;
    reverse(r.begin(), r.end());
    rep(i, k) { cout << r[i] << ' '; }
    cout << endl;
    return 0;
}
