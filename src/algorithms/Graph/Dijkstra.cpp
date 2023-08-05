/**
 * @brief ダイクストラ法（単一始点最短経路）
 *
 * @fn dijkstra
 * @brief ダイクストラ法を使って単一始点最短経路を求める
 * @param g グラフのデータ
 * @param s 始点番号
 * @param dist 各点の最短距離
 * @remark 重みに負の数がある場合は計算ができないのでベルマンフォード法を使う
 * @remark 計算量：O(|E|log|V|)
 *
 * @fn dijkstraWithPath
 * @brief ダイクストラ法を使って単一始点最短経路を求める＋経路情報を記録する
 * 引数はdijkstraから以下が追加される
 * @param prev 1つ前に通った点の情報
 * 
 * @fn getPath
 * @brief 最短経路の経路情報を取得する
 * @param prev 1つ前に通った点の情報
 * @param t 終点番号
 * @retval 経路情報
 *
 *
 * 参考ページ
 * https://algo-logic.info/dijkstra/
 * 参考コード
 * https://github.com/ei1333/library/blob/master/graph/graph-template.hpp
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

#ifdef LOCAL
#include "debug_print.hpp"
#define dbg(...) cerr << '(' << __LINE__ << ')' << endl; debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) (static_cast<void>(0))
#endif
// clang-format on

template <typename T = int>
struct Edge {
    int from, to;
    T cost;
    Edge() = default;
    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    inline bool operator<(const Edge &e) const { return cost < e.cost; }
};

template <typename T = int>
using Edges = vector<Edge<T>>;

template <typename T = int>
struct Graph {
    vector<vector<Edge<T>>> g;
    Graph() = default;
    explicit Graph(int n) : g(n) {}

    size_t size() const { return g.size(); }

    void addDirectedEdge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost); }
    void addEdge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost);
        g[to].emplace_back(to, from, cost);
    }

    void read(const int m, const int padding = -1, const bool directed = false,
              const bool weighted = false) {
        for (int i = 0; i < m; i++) {
            int u, v;
            T w = T(1);
            cin >> u >> v;
            u += padding;
            v += padding;
            if (weighted)
                cin >> w;
            if (directed)
                addDirectedEdge(u, v, w);
            else
                addEdge(u, v, w);
        }
    }

    void debug() {
        vector<vector<T>> v;
        int c = 0;

        for (size_t i = 0; i < this->size(); i++) {
            for (auto &e : g[i]) {
                vector<T> v2;
                v2.emplace_back(++c);
                v2.emplace_back(e.from);
                v2.emplace_back(e.to);
                v2.emplace_back(e.cost);
                v.emplace_back(v2);
            }
        }
        dbg(v);
    }

    inline vector<Edge<T>> &operator[](const int &k) { return g[k]; }
    inline const vector<Edge<T>> &operator[](const int &k) const { return g[k]; }
};

template <typename T>
void dijkstra(const Graph<T> &g, const int s, vector<T> &dist) {
    int n = g.size();
    dist.assign(n, numeric_limits<T>::max());
    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        for (auto &e : g[cur]) {
            if (dist[e.to] <= dist[cur] + e.cost)
                continue;
            dist[e.to] = dist[cur] + e.cost;
            pq.emplace(dist[e.to], e.to);
        }
    }
}


template <typename T>
void dijkstraWithPath(const Graph<T> &g, const int s, vector<T> &dist, vector<T> &prev) {
    int n = g.size();
    dist.assign(n, numeric_limits<T>::max());
    prev.assign(n, -1);
    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        for (auto &e : g[cur]) {
            if (dist[e.to] <= dist[cur] + e.cost)
                continue;
            dist[e.to] = dist[cur] + e.cost;
            pq.emplace(dist[e.to], e.to);
            prev[e.to] = cur;
        }
    }
}

template <typename T = vector<int>>
T getPath(const T &prev, int t) {
    T path;
    for (int cur = t; cur != -1; cur = prev[cur]) {
        path.emplace_back(cur);
    }
    reverse(path.begin(), path.end());
    return path;
}

/*
 * 問題例 GRL_1_A Single Source Shortest Path
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
*/
void test1A() {
    int v, e, r;
    cin >> v >> e >> r;

    Graph g(v);
    g.read(e, 0, true, true);

    g.debug();

#define OUT1

#ifdef OUT1
    vi dist;
    dijkstra(g, r, dist);

    rep(i, v) {
        if (dist[i] == INT_MAX)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }
#endif
// 経路情報が欲しい場合はこっちを使う
#ifdef OUT2
    vi dist, prev;
    dijkstraWithPath(g, r, dist, prev);

    rep(i, v) {
        cout << '[' << i << "] ";
        if (dist[i] == INT_MAX)
            cout << "INF" << endl;
        else {
            cout << dist[i] << endl;
            vi path = getPath(prev, i);
            for(auto x : path) cout << ' ' << x;
            // for(auto x : path) cout << ' ' << x + 1;
            cout << endl;
        }
    }
#endif

}

/*
 * 問題例 競技プログラミングの鉄則　演習問題集　A64 - Shortest Path 2
 * https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bl
*/
void test2() {
    int v, e;
    cin >> v >> e;
    Graph g(v);
    g.read(e, -1, false, true);

    g.debug();

    vi dist;
    dijkstra(g, 0, dist);
    // dijkstraWithPath(g, 0, dist, prev);

    rep(i, v) {
        if (dist[i] == INT_MAX) dist[i] = -1;
        cout << dist[i] << endl;
    }
}

int main() {
    test1A();
    // test2();
    return 0;
}
