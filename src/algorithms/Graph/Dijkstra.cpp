/*
単一始点最短経路　（ダイクストラ法）

参考ページ
https://algo-logic.info/dijkstra/
参考コード
https://github.com/ei1333/library/blob/master/graph/graph-template.hpp
問題例 GRL_1_A Single Source Shortest Path
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
*/

/**
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
 * @param prev 1つ前に通った点の情報
 * @param t 終点番号
 * @retval 経路情報
 */

#include "../header.cpp"
#include "GraphStruct.hpp"

void dijkstra(const Graph &g, const int s, vl &dis, vi &prev) {
    int n = g.size();
    dis.assign(n, LLONG_MAX);
    prev.assign(n, -1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dis[s] = 0;
    pq.emplace(s, dis[s]);
    while (!pq.empty()) {
        int pTo = pq.top().first;
        pq.pop();
        for (auto &e : g[pTo]) {
            if (chmin(dis[e.to], dis[pTo] + e.cost)) {
                pq.emplace(e.to, dis[e.to]);
                prev[e.to] = pTo;
            }
        }
    }
}

vi getPath(const vi &prev, int t) {
    vi path;
    for (int cur = t; cur != -1; cur = prev[cur]) {
        path.emplace_back(cur);
    }
    reverse(all(path));
    return path;
}

// 使用例
int main() {
    int v, e, r;
    in(v, e, r);

    Graph g(v, e, 0, true, true);

    g.debug();

    vl dis(v);
    vi prev(v);
    dijkstra(g, r, dis, prev);

#define OUT1

#ifdef OUT1
    rep(i, v) {
        if (dis[i] == LLONG_MAX)
            cout << "INF" << endl;
        else
            cout << dis[i] << endl;
    }
#endif
#ifdef OUT2
    rep(i, v) {
        cout << '[' << i << "] ";
        if (dis[i] == LLONG_MAX)
            cout << "INF" << endl;
        else {
            cout << dis[i] << endl;
            vi path = getPath(prev, i);
            fore(x, path) cout << ' ' << x;
            cout << endl;
        }
    }
#endif
    return 0;
}
