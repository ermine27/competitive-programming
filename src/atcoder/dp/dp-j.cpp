/*

dp[i][j][k] : 1個の枚数がi枚、2個の枚数がj枚、3個の枚数がk枚ある時の期待値

dp[i][j][k]
  = dp[i-1][j][k] * (i/N)   ・・・1枚の皿が選ばれる確率
  + dp[i+1][j-1][k] * (j/N)　・・・2枚の皿が選ばれる確立
  + dp[i][j+1][k-1] * (k/N)　・・・3枚の皿が選ばれる確立
  + dp[i][j][k] * (N-i-j-k)/N ・・・0枚の皿が選ばれる確率
  + 1

dp[i][j][k](i+j+k)/N
  = dp[i-1][j][k] * (i/N)
  + dp[i+1][j-1][k] * (j/N)
  + dp[i][j+1][k-1] * (k/N)
  + 1

dp[i][j][k]
  = 1/(i+j+k) * (
      dp[i-1][j][k] * i
    + dp[i+1][j-1][k] * j
    + dp[i][j+1][k-1] * k
    + N
  )

*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<vector<double>>> dp(301, vector<vector<double>>(301, vector<double>(301, -1)));

double dfs(int i, int j, int k) {
    if (dp[i][j][k] >= 0)
        return dp[i][j][k];

    double res = 0.0;
    if (i > 0)
        res += dfs(i - 1, j, k) * i;
    if (j > 0)
        res += dfs(i + 1, j - 1, k) * j;
    if (k > 0)
        res += dfs(i, j + 1, k - 1) * k;
    return dp[i][j][k] = (res + n) / (i + j + k);
}

int main() {
    cin >> n;
    vector<int> d(3);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        d[a - 1]++;
    }

    dp[0][0][0] = 0;
    cout << setprecision(10) << dfs(d[0], d[1], d[2]) << endl;
    return 0;
}
