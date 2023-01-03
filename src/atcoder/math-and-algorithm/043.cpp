#include <bits/stdc++.h>
using namespace std;

set<int> v;

void dfs(vector<vector<int>> &g, int x) {
    v.insert(x);
    for (int t : g[x]) {
        if (v.count(t) > 0)
            continue;
        dfs(g, t);
    }
    return;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    dfs(g, 0);

    if ((int)v.size() == n)
        cout << "The graph is connected." << endl;
    else
        cout << "The graph is not connected." << endl;

    return 0;
}
