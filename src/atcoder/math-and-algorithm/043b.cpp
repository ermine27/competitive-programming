/**
 * ラムダ式を使って再帰処理を書く
 * functionを使ったラムダ式はC++11向けで、書き方が面倒
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    set<int> v;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    function<void(int)> dfs = [&](int x) {
        v.insert(x);
        for (int t : g[x]) {
            if (v.count(t) > 0)
                continue;
            dfs(t);
        }
        return;
    };

    dfs(0);

    if ((int)v.size() == n)
        cout << "The graph is connected." << endl;
    else
        cout << "The graph is not connected." << endl;

    return 0;
}
