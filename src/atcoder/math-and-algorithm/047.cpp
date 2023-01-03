#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> v;

bool dfs(int x) {
    for (int t : g[x]) {
        if (v[t] == -1) {
            v[t] = 1 - v[x];
            if (!dfs(t))
                return false;
        } else {
            if (v[t] == v[x])
                return false;
        }
    }
    return true;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    g.resize(n);
    v.assign(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++) {
        if (v[i] != -1)
            continue;

        v[i] = 0;
        if (!dfs(i)) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
