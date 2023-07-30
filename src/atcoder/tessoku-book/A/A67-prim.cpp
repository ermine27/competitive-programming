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
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<bool> used(n);

    rep(i, m) {
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vi dist(n, 2e9);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, 0});
    int ans = 0;
    while (!que.empty()) {
        int wght = que.top().first;
        int cur = que.top().second;
        que.pop();

        if (used[cur])
            continue;
        used[cur] = true;
        ans += wght;

        rep(i, g[cur].size()) {
            int nxt = g[cur][i].first;
            int weight = g[cur][i].second;
            if (used[nxt])
                continue;
            if (chmin(dist[nxt], weight)) {
                que.push({dist[nxt], nxt});
            }
        }
    }

    cout << ans << endl;
    return 0;
}
