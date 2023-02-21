/**
 * @brief ダイクストラ法（単一始点最短経路）
 *
 * @fn dijkstra
 * @brief ダイクストラ法を使って単一始点最短経路を求める
 * @param g グラフのデータ
 * @param s 始点番号
 * @param dis 各点の最短距離
 * @param prev 1つ前に通った点の情報
 * @remark 重みに負の数がある場合は計算ができないのでベルマンフォード法を使う
 * @remark 計算量：O(|E|log|V|)
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
 * 問題例 GRL_1_A Single Source Shortest Path
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
 */

#include "GraphTemplate.hpp"

template <typename T>
void dijkstra(const Graph<T> &g, const int s, vector<T> &dis, vector<T> &prev) {
    int n = g.size();
    dis.assign(n, numeric_limits<T>::max());
    prev.assign(n, -1);
    using Pi = pair<int, T>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
    dis[s] = 0;
    pq.emplace(s, dis[s]);
    while (!pq.empty()) {
        int pTo = pq.top().first;
        pq.pop();
        for (auto &e : g[pTo]) {
            if (dis[e.to] <= dis[pTo] + e.cost)
                continue;
            dis[e.to] = dis[pTo] + e.cost;
            pq.emplace(e.to, dis[e.to]);
            prev[e.to] = pTo;
        }
    }
}

template <typename T = vector<int>>
T getPath(const T &prev, int t) {
    T path;
    for (int cur = t; cur != -1; cur = prev[cur]) {
        path.emplace_back(cur);
    }
    reverse(all(path));
    return path;
}
