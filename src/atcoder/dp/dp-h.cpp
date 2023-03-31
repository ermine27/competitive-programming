#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));
    vector<vector<int>> dp(h, vector<int>(w));
    dp[0][0] = 1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i < h - 1 && g[i + 1][j] == '.') {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            }
            if (j < w - 1 && g[i][j + 1] == '.') {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }
        }
    }

    cout << dp[h - 1][w - 1] << endl;

    return 0;
}
