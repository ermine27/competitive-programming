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
    vi vst(n);

    rep(i, m) {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto dfs = [&](auto self, int cur) -> void {
        vst[cur] = 1;
        rep(i, g[cur].size()) {
            if (vst[g[cur][i]])
                continue;
            self(self, g[cur][i]);
        }
        return;
    };

    dfs(dfs, 0);
    bool ok = true;
    rep(i, n) {
        if (!vst[i])
            ok = false;
    }

    if (ok)
        cout << "The graph is connected." << endl;
    else
        cout << "The graph is not connected." << endl;

    return 0;
}
