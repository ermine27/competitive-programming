/**
 * @brief ベルマンフォード法（単一始点最短経路）
 *
 * @fn bellmanFord
 * @brief ベルマンフォード法を使って単一始点最短経路を求める
 * @param edges 辺のデータ
 * @param vertex_num 頂点の数
 * @param s 探索開始位置
 * @param dis 各点までの最短距離
 * @retval true 負の閉路あり
 * @retval false 負の閉路なし
 * @remark 計算量：O(|E|×|V|)
 *
 *
 * 参考ページ
 * https://algo-logic.info/bellman-ford/
 * 参考コード
 * https://github.com/ei1333/library/blob/master/graph/shortest-path/bellman-ford.hpp
 * 問題例 GRL_1_B Single Source Shortest Path (Negative Edges)
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
 */

#include "../header.cpp"
#include "GraphTemplate.hpp"

template <typename T>
bool bellmanFord(const Edges<T> &edges, const int vertex_num, const int s, vector<T> &dis) {
    const auto INF = numeric_limits<T>::max();
    int edge_num = edges.size();

    dis.assign(vertex_num, INF);
    dis[s] = 0;

    for (int i = 0; i < edge_num; i++) {
        for (auto e : edges) {
            if (dis[e.from] != INF && dis[e.to] > dis[e.from] + e.cost) {
                dis[e.to] = dis[e.from] + e.cost;
                if (i == vertex_num - 1) {
                    dis = {};
                    return true;
                }
            }
        }
    }
    return false;
};
