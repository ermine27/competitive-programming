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
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m) {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vi dist(n, -1);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        rep(i, g[cur].size()) {
            if (dist[g[cur][i]] != -1)
                continue;
            int nxt = g[cur][i];
            que.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }

    rep(i, n) cout << dist[i] << endl;

    return 0;
}
