/*
単一始点最短経路　（ベルマンフォード法）

参考ページ
https://algo-logic.info/bellman-ford/
参考コード
https://github.com/ei1333/library/blob/master/graph/shortest-path/bellman-ford.hpp
問題例 GRL_1_B Single Source Shortest Path (Negative Edges)
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
*/

/**
 * @fn bellmanFord
 * @brief ベルマンフォード法を使って単一始点最短経路を求める
 * @param edges 辺のデータ
 * @param vertex_num 頂点の数
 * @param s 始点番号
 * @param dis 各点の最短距離
 * @retval 負の閉路の有無 (true:あり、false:なし)
 * @remark 計算量：O(|E|×|V|)
 */

#include "../header.cpp"
#include "GraphStruct.hpp"

bool bellmanFord(const vector<Edge> &edges, const int vertex_num, const int s, vl &dis) {
    int edge_num = edges.size();
    dis.assign(vertex_num, LLONG_MAX);
    dis[s] = 0;

    for (int i = 0; i < edge_num; i++) {
        for (auto e : edges) {
            if (dis[e.from] != LLONG_MAX && dis[e.to] > dis[e.from] + e.cost) {
                dis[e.to] = dis[e.from] + e.cost;
                if (i == vertex_num - 1) {
                    dis = {};
                    return true;
                }
            }
        }
    }
    return false;
}

// 使用例
int main() {
    int v, e, r;
    in(v, e, r);
    Edges es;
    rep(i, e) {
        int a, b, c;
        in(a, b, c);
        es.emplace_back(a, b, c);
    }

    vl dis;
    if (bellmanFord(es, v, r, dis)) {
        cout << "NEGATIVE CYCLE" << endl;
    }

    fore(dist, dis) {
        if (dist == LLONG_MAX)
            cout << "INF" << endl;
        else
            cout << dist << endl;
    }
}
