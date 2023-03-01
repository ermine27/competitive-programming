/*
最小全域木　（クラスカル法）

参考ページ
https://algo-logic.info/kruskal-mst/
参考コード
https://github.com/ei1333/library/blob/master/graph/mst/kruskal.hpp
問題例 GRL_2_A Minimum Spanning Tree
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
*/

/**
 * @fn Kruskal
 * @brief クラスカル法を使って最小全域木を求める
 * @param edges 辺のデータ
 * @param v 頂点の数
 * @return 最小全域木の辺の重みの総和
 * @remark 計算量：O(|E|log|V|)
 *
 */

#include "../DataStructure/UnionFind.hpp"
#include "GraphTemplate.hpp"

template <typename T>
T Kruskal(Edges<T> &edges, int v) {
    UnionFind uf(v);
    T res = 0;
    sort(edges.begin(), edges.end());

    for (auto e : edges) {
        if (uf.unite(e.from, e.to)) {
            res += e.cost;
        }
    }
    return res;
};

// MSTのパス情報がほしい場合は以下のように拡張する
#if 0
template <typename T>
T Kruskal(Edges<T> &edges, int v, Edges<T> &mst) {
    UnionFind uf(v);
    T res = 0;
    sort(edges.begin(), edges.end());

    for (auto e : edges) {
        if (uf.unite(e.from, e.to)){
            res += e.cost;
            mst.emplace_back(e);
        }
    }
    return res;
};
#endif
