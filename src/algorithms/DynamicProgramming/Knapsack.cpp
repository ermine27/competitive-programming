/**
 * @brief 0-1ナップザック
 * 
 * @remark 計算量：O(n*wmax)
 * 
 * 参考ページ
 * https://qiita.com/drken/items/dc53c683d6de8aeacf5a
 * 問題例 Educational DP Contest - D Knapsack 1
 * https://atcoder.jp/contests/dp/tasks/dp_d
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    // n:品物の個数、wmax:重さの最大値
    int n, wmax;
    cin >> n >> wmax;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    vector<vector<long long>> dp(n + 1, vector<long long>(wmax + 1));

#if 1
    // 貰うDP
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= wmax; j++) {
            // i番目の品物を選ぶ場合
            if (j >= w[i]) {
                dp[i + 1][j] = max(dp[i][j - w[i]] + v[i], dp[i][j]);
            // i番目の品物を選ばない場合
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }
#else
    // 配るDP
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= wmax; j++) {
            // i番目の品物を選ばない場合
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            // i番目の品物を選ぶ場合
            if (j + w[i] <= wmax) {
                dp[i + 1][j + w[i]] = max(dp[i][j + w[i]], dp[i][j] + v[i]);
            }
        }
    }

#endif

    cout << dp[n][wmax] << endl;
}
