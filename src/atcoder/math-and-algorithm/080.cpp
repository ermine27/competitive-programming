#include <bits/stdc++.h>
using namespace std;

using Pi = pair<int, int>;

int dijkstra(vector<vector<Pi>>& g, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
    dist[0] = 0;
    pq.emplace(0, dist[0]);
    while (!pq.empty()) {
        int from = pq.top().first;
        pq.pop();
        for (auto& [to, cost] : g[from]) {
            if (dist[to] <= dist[from] + cost)
                continue;
            dist[to] = dist[from] + cost;
            pq.emplace(to, dist[to]);
        }
    }

    return (dist[n - 1] == INT_MAX ? -1 : dist[n - 1]);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Pi>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    cout << dijkstra(g, n) << endl;
    return 0;
}
