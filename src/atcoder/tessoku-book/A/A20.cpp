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
    string s, t;
    cin >> s >> t;
    int slen = s.length(), tlen = t.length();

    vector<vi> dp(slen + 1, vi(tlen + 1));
    rep(i, slen) {
        rep(j, tlen) {
            if (s[i] == t[j]) {
                chmax(dp[i + 1][j + 1], dp[i][j] + 1);
            }
            chmax(dp[i + 1][j + 1], dp[i + 1][j]);
            chmax(dp[i + 1][j + 1], dp[i][j + 1]);
        }
    }

    cout << dp[slen][tlen] << endl;
    return 0;
}
