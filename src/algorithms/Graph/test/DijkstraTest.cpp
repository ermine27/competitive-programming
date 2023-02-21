/*
単一始点最短経路　（ダイクストラ法）

参考ページ
https://algo-logic.info/dijkstra/
参考コード
https://github.com/ei1333/library/blob/master/graph/graph-template.hpp
問題例 GRL_1_A Single Source Shortest Path
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
*/

#include "../../header.cpp"
#include "../Dijkstra.hpp"

int main() {
    int v, e, r;
    in(v, e, r);

    Graph g(v);
    g.read(e, 0, true, true);

    g.debug();

    vi dis, prev;
    dijkstra(g, r, dis, prev);

#define OUT1

#ifdef OUT1
    rep(i, v) {
        if (dis[i] == INT_MAX)
            cout << "INF" << endl;
        else
            cout << dis[i] << endl;
    }
#endif
#ifdef OUT2
    rep(i, v) {
        cout << '[' << i << "] ";
        if (dis[i] == INT_MAX)
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
