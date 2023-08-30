/*
重みつきの単一始点最短経路問題なのでダイクストラ法で解く。
但し、この問題では重みが距離と木の有無の2軸あるのでその考慮が必要。
方法としては、今回の回答のようにその点までの最短距離を更新するかの判定のところに、
距離が同じなら通ってきた木の数も合わせてチェックするようにする方法がある。
もしくは、この２つの重みには優劣が決まっているので、
最短経路＝道路の長さ×10000 + 木の数
とすることで一軸で判定させることもできる。
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

struct Edge {
    int to, dist, tree;
    Edge(int to, int dist, int tree) : to(to), dist(dist), tree(tree) {}
};

int main() {
    const int NEVER = 2e9;
    int n, m, a, b, c, d;
    cin >> n >> m;
    vector<vector<Edge>> g(n);

    rep(i, m) {
        cin >> a >> b >> c >> d;
        a--;
        b--;
        g[a].emplace_back(b, c, d);
        g[b].emplace_back(a, c, d);
    }

    vi dist(n, NEVER), trees(n);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, 0});
    while (!que.empty()) {
        int cur = que.top().second;
        que.pop();
        rep(i, g[cur].size()) {
            int nto = g[cur][i].to;
            int ndist = dist[cur] + g[cur][i].dist;
            int ntree = trees[cur] + g[cur][i].tree;
            if (ndist < dist[nto] || (ndist == dist[nto] && ntree > trees[nto])) {
                dist[nto] = ndist;
                trees[nto] = ntree;
                que.push({dist[nto], nto});
            }
        }
    }

    cout << dist[n - 1] << ' ' << trees[n - 1] << endl;
    return 0;
}
