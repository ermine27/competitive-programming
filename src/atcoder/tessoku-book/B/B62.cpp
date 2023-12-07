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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    vi ans = {0}, used(n);
    used[0] = 1;
    auto dfs = [&](auto self, int x) -> bool {
        if (x == n - 1) {
            return true;
        }

        for (int t : g[x]) {
            if (used[t])
                continue;

            used[t] = 1;
            ans.push_back(t);
            if (self(self, t))
                return true;
            used[t] = 0;
            ans.pop_back();
        }

        return false;
    };

    dfs(dfs, 0);
    rep(i, ans.size()) { cout << ans[i] + 1 << ' '; }
    cout << endl;
    return 0;
}
