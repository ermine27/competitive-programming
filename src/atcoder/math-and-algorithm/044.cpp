#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> s(n, -1);
    s[0] = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (int t : g[k]) {
            if (s[t] == -1) {
                q.push(t);
                s[t] = s[k] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << s[i] << endl;
    return 0;
}