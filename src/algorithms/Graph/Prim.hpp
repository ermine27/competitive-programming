/**
 * @brief プリム法（最小全域木(MST)）
 *
 * @fn prim
 * @brief プリム法を使って最小全域木を求める
 * @param g グラフのデータ
 * @param prev 1つ前に通った点の情報
 * @return 最小全域木の辺の重みの総和
 * @remark 計算量：O(|E|log|V|)
 *
 *
 * 参考ページ
 * https://algo-logic.info/prim-mst/
 * 参考コード
 * https://github.com/ei1333/library/blob/master/graph/mst/prim.hpp
 * 問題例 ALDS_1_12_A Minimum Spanning Tree
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A
 */

#include "GraphTemplate.hpp"

template <typename T>
T prim(const Graph<T> &g, vector<T> &prev) {
    int n = g.size();
    T total = T(0);
    vector<T> dis(n, numeric_limits<T>::max());
    dis[0] = 0;
    prev.assign(n, -1);
    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
    pq.emplace(dis[0], 0);
    vector<bool> used(n);
    while (!pq.empty()) {
        int pCost = pq.top().first;
        int pTo = pq.top().second;
        pq.pop();

        if (used[pTo])
            continue;
        used[pTo] = true;
        total += pCost;

        for (auto &e : g[pTo]) {
            if (dis[e.to] <= e.cost || used[e.to])
                continue;
            dis[e.to] = e.cost;

            pq.emplace(dis[e.to], e.to);
            prev[e.to] = pTo;
        }
    }

    return total;
}
