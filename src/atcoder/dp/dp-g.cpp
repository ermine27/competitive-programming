#include <bits/stdc++.h>
using namespace std;

// clang-format off
template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
// clang-format on

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        deg[y]++;
    }

    queue<int> que;
    for (int i = 0; i < n; i++)
        if (deg[i] == 0) {
            que.push(i);
        }

    vector<int> dp(n), ans;
    while (!que.empty()) {
        int c = que.front();
        que.pop();
        ans.push_back(c);

        for (auto e : g[c]) {
            deg[e]--;
            if (deg[e] == 0) {
                que.push(e);
                chmax(dp[e], dp[c] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
