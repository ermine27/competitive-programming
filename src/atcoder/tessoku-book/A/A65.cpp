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
    int n, a;
    cin >> n;
    vector<vector<int>> g(n);
    vi ans(n);
    for (int i = 1; i < n; i++) {
        cin >> a;
        a--;
        g[a].push_back(i);
    }

    auto dfs = [&](auto self, int cur, int cnt) -> int {
        rep(i, g[cur].size()) cnt += self(self, g[cur][i], 0);
        ans[cur] = cnt;
        return cnt + 1;
    };

    dfs(dfs, 0, 0);

    rep(i, n) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}
