#include <bits/stdc++.h>
using namespace std;

// clang-format off
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

string lcs(string s, string t) {
    int slen = s.length();
    int tlen = t.length();
    vector<vector<int>> dp(slen + 1, vector<int>(tlen + 1));

    for (int i = 0; i < slen; i++) {
        for (int j = 0; j < tlen; j++) {
            if (s[i] == t[j])
                chmax(dp[i + 1][j + 1], dp[i][j] + 1);
            chmax(dp[i + 1][j + 1], dp[i + 1][j]);
            chmax(dp[i + 1][j + 1], dp[i][j + 1]);
        }
    }

    // 経路復元
    string ans = "";
    int i = slen;
    int j = tlen;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else if (dp[i][j] == dp[i][j - 1])
            j--;
        else {
            ans = s[i - 1] + ans;
            i--;
            j--;
        }
    }

    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t) << endl;
}
