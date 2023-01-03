/**
 * DFS（深さ優先探索）　ラムダ式版
 *
 * 問題例
 * ALDS1_11_B　Depth First Search
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        u--;
        g[u].resize(k);
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            g[u][j] = v - 1;
        }
    }

    vector<int> d(n), f(n);
    int step = 0;

    // ジェネリックラムダ式を使って再帰処理を書く
    // C++14以上
    auto dfs = [&](auto self, int x) -> void {
        
        // ベースケース
        if(d[x]) return;

        // 再帰ステップ
        step++;
        d[x] = step;
        for (int t : g[x]) {
            // if(d[t]) continue;
            self(self, t);
        }

        step++;
        f[x] = step;

        return;
    };


    int checked = 0;
    while (checked < n) {
        dfs(dfs, checked);
        while (checked < n && d[checked] > 0) checked++;
    }

    for (int i = 0; i < n; i++) cout << i + 1 << ' ' << d[i] << ' ' << f[i] << endl;

    return 0;
}
