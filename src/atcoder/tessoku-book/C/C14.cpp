/*
重みつきの単一始点最短経路問題なのでダイクストラ法で解く。

通る可能性のある交差点の数の求め方だが、経路保持する方法ではTLEする。
交差点1と交差点Nの2点でダイクストラ法を行い、両端の交差点から各交差点までの最短経路を求めておく。
交差点i,jの最短経路をdist(i,j)とすると、dist(1,k) + dist(k,N) がdist(1,N)と同じであれば
交差点kは通る可能性のある交差点と判断できる。

*/
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

void dijkstra(vector<vector<pair<int, int>>>& g, vl& dist, int start) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    dist[start] = 0LL;
    que.push({0LL, start});
    while (!que.empty()) {
        int cur = que.top().second;
        que.pop();
        rep(i, g[cur].size()) {
            int nto = g[cur][i].first;
            ll ndist = dist[cur] + g[cur][i].second;
            if (ndist < dist[nto]) {
                dist[nto] = ndist;
                que.push({ndist, nto});
            }
        }
    }
}

int main() {
    const ll NEVER = LONG_MAX;
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    rep(i, m) {
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    vl distS(n, NEVER), distE(n, NEVER);
    dijkstra(g, distS, 0);
    dijkstra(g, distE, n - 1);

    int ans = 0;
    rep(i, n) {
        if (distS[i] + distE[i] == distE[0])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
