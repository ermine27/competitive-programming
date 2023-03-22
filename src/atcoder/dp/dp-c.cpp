#include <bits/stdc++.h>
using namespace std;

#if 0
int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> dp(n + 1, vector<int>(3));
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = max(dp[i][1], dp[i][2]) + a[i];
        dp[i + 1][1] = max(dp[i][0], dp[i][2]) + b[i];
        dp[i + 1][2] = max(dp[i][0], dp[i][1]) + c[i];
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    return 0;
}
#endif

// 活動のパターンが3種類しかないので3つのパターンをそれぞれ記述してもいいが、
// 下のように書くことでDPの計算を1回にまとめられる。
int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) cin >> a[i][j];
    vector<vector<int>> dp(n + 1, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k)
                    dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + a[i][k]);
            }
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    return 0;
}
