// ★６問題
// レーベンシュタイン距離

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
    for (int i = 1; i <= slen; i++) dp[i][0] = i;
    for (int j = 1; j <= tlen; j++) dp[0][j] = j;
    for (int i = 1; i <= slen; i++) {
        for (int j = 1; j <= tlen; j++) {
            int cost = 1;
            if (s[i - 1] == t[j - 1])
                cost = 0;

            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost});
        }
    }

    cout << dp[slen][tlen] << endl;
    return 0;
}
