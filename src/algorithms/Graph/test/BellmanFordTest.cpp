/**
 * ベルマンフォード法（単一始点最短経路）
 * 参考ページ
 * https://algo-logic.info/bellman-ford/
 * 参考コード
 * https://github.com/ei1333/library/blob/master/graph/shortest-path/bellman-ford.hpp
 * 問題例 GRL_1_B Single Source Shortest Path (Negative Edges)
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
 */

#include "../../header.cpp"
#include "../BellmanFord.hpp"

int main() {
    int v, e, r;
    in(v, e, r);
    Edges<int> es;
    rep(i, e) {
        int a, b, c;
        in(a, b, c);
        es.emplace_back(a, b, c);
    }

    vi dis;
    if (bellmanFord(es, v, r, dis)) {
        cout << "NEGATIVE CYCLE" << endl;
    }

    fore(dist, dis) {
        if (dist == INT_MAX)
            cout << "INF" << endl;
        else
            cout << dist << endl;
    }
}
