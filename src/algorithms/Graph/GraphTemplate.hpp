/**
 * @brief グラフ用テンプレート
 *
 * @struct Edge 辺データ
 * @param from 始点
 * @param to 終点
 * @param cost コスト
 *
 *
 * @struct Graph グラフデータ
 * @param n 頂点の数
 *
 * @fn Graph.size 頂点の数を取得する
 * @return 頂点の数
 *
 * @fn Graph.addDirectedEdge 有向辺を追加する
 * @param from 始点
 * @param to 終点
 * @param cost コスト デフォルト値は1
 *
 * @fn Graph.addEdge 無向辺を追加する
 * @param from 始点
 * @param to 終点
 * @param cost コスト デフォルト値は1
 *
 * @fn Graph.read
 * @param m 辺の数
 * @param padding 頂点・辺の入力値をいくつずらすか デフォルト値は-1
 * @param directed true:有向, false:無向 デフォルト値はfalse
 * @param weighted true:重みあり, false:重みなし デフォルト値はfalse
 * @note paddingは0-originの場合は-1、1-originの場合は0を指定する
 *
 * @fn Graph.debug デバッグ出力
 * @remark 使用する場合は debug_print.hpp を読み込んでおくこと
 *
 *
 * 参考ソース
 * https://github.com/ei1333/library/blob/master/graph/graph-template.hpp
 */

#pragma once

template <typename T = int>
struct Edge {
    int from, to;
    T cost;
    Edge() = default;
    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
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
