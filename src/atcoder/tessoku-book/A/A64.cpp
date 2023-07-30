#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

int main() {
    const int NEVER = 2e9;
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);

    rep(i, m) {
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vi dist(n, NEVER);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, 0});
    while (!que.empty()) {
        int cur = que.top().second;
        que.pop();
        rep(i, g[cur].size()) {
            int nxt = g[cur][i].first;
            int weight = g[cur][i].second;
            if (chmin(dist[nxt], dist[cur] + weight)) {
                que.push({dist[nxt], nxt});
            }
        }
    }

    rep(i, n) {
        if (dist[i] == NEVER)
            dist[i] = -1;
        cout << dist[i] << endl;
    }

    return 0;
}
