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
    int n, t;
    cin >> n >> t;
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vi rank(n, -1);
    vi used(n);

    auto dfs = [&](auto self, int u) -> void {
        used[u] = 1;
        int sz = g[u].size();
        if (sz == 0) {
            rank[u] = 0;
            return;
        };

        int mx = 0;
        rep(i, sz) {
            int v = g[u][i];
            if (used[v])
                continue;
            self(self, v);
            chmax(mx, rank[v] + 1);
        }
        rank[u] = mx;
    };

    dfs(dfs, t - 1);

    rep(i, n) { cout << rank[i] << ' '; }
    cout << endl;
    return 0;
}
