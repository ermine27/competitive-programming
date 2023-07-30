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
    vector<vector<int>> g(n + 1);

    rep(i, m) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
        cout << i << ": {";
        rep(j, g[i].size()) {
            if (j > 0)
                cout << ", ";
            cout << g[i][j];
        }
        cout << "}" << endl;
    }

    return 0;
}
