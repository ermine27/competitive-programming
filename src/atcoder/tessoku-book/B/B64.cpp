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

struct Edge {
    int to;
    ll cost;
    Edge(int to, ll cost) : to(to), cost(cost) {}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    vl dist(n, 1e18);
    vi prev(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        rep(i, g[now].size()) {
            int to = g[now][i].to;
            if (chmin(dist[to], dist[now] + g[now][i].cost)) {
                prev[to] = now;
                q.push(to);
            }
        }
    }

    vi ans;
    int now = n - 1;
    while (now != 0) {
        ans.push_back(now);
        now = prev[now];
    }
    ans.push_back(0);
    reverse(ans.begin(), ans.end());
    rep(i, ans.size()) { cout << ans[i] + 1 << " "; }
    cout << endl;

    return 0;
}
