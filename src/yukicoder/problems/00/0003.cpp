#include <bits/stdc++.h>
using namespace std;

// BFS
#if 1

int main() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1, -1);
    cnt[1] = 1;

    map<int, int> bits;
    for (int i = 1; i <= n; i++) {
        bitset<32> bs(i);
        bits[i] = bs.count();
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == n)
            break;

        int prev = x - bits[x];
        if (prev >= 1 && cnt[prev] == -1) {
            cnt[prev] = cnt[x] + 1;
            q.push(prev);
        }

        int next = x + bits[x];
        if (next <= n && cnt[next] == -1) {
            cnt[next] = cnt[x] + 1;
            q.push(x + bits[x]);
        }
    }

    cout << cnt[n] << endl;
    return 0;
}
#endif

// DP（＋メモ化）
#if 0

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[0][1] = 1;

    map<int, int> bits;
    for (int i = 1; i <= n; i++) {
        bitset<32> bs(i);
        bits[i] = bs.count();
    }

    vector<int> ans(n + 1, -1);
    ans[1] = 1;

    dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            if (!dp[i - 1][j])
                continue;

            if (bits[j] < j && ans[j - bits[j]] == -1) {
                dp[i][j - bits[j]] = dp[i - 1][j] + 1;
                ans[j - bits[j]] = i + 1;
            }
            if (j + bits[j] <= n && ans[j + bits[j]] == -1) {
                dp[i][j + bits[j]] = dp[i - 1][j] + 1;
                ans[j + bits[j]] = i + 1;
            }
        }
    }

    cout << ans[n] << endl;
    return 0;
}
#endif
