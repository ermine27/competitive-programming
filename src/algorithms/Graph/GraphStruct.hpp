/**
 *
 * @fn Graph::Graph
 * @brief グラフのデータを入力から取得する
 * @param n 頂点の数
 * @param m 辺の数
 * @param origin 頂点・辺の先頭番号 [1 or 0]
 * @param directed true:有向, false:無向
 * @param weighted 重みの有無
 *
 */

#include "../header.cpp"

struct Edge {
    int from;
    int to;
    long long cost;
    Edge() = default;
    Edge(int to, long long cost) : to(to), cost(cost) {}
    Edge(int from, int to, long long cost) : from(from), to(to), cost(cost) {}
};

using Edges = vector<Edge>;

struct Graph {
    vector<vector<Edge>> g;

    Graph(int n, int m, int origin = 1, bool directed = false, bool weighted = false) {
        g.resize(n);
        while (m--) {
            int u, v;
            long long w = 1;
            cin >> u >> v;
            if (origin) {
                u--;
                v--;
            }
            if (weighted)
                in(w);
            g[u].emplace_back(u, v, w);
            if (!directed)
                g[v].emplace_back(v, u, w);
        }
    }

    size_t size() const { return g.size(); }

    void debug() {
        vector<vector<long long>> v;
        int c = 0;

        for (size_t i = 0; i < this->size(); i++) {
            for (auto &e : g[i]) {
                vector<long long> v2;
                v2.emplace_back(++c);
                v2.emplace_back(e.from);
                v2.emplace_back(e.to);
                v2.emplace_back(e.cost);
                v.emplace_back(v2);
            }
        }
        dbg(v);
    }

    inline vector<Edge> &operator[](const int &k) { return g[k]; }
    inline const vector<Edge> &operator[](const int &k) const { return g[k]; }
};
