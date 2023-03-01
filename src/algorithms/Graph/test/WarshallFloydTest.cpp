/*
全点始点最短経路　（ワーシャルフロイド法）

参考ページ
https://algo-logic.info/warshall-floyd/
参考コード
https://github.com/ei1333/library/blob/master/graph/shortest-path/bellman-ford.hpp
問題例 GRL_1_C All Pairs Shortest Path
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
*/

#include "../../header.cpp"
#include "../WarshallFloyd.hpp"

int main() {
    int v, e;
    in(v, e);
    vvls(dp, v, v, LLONG_MAX);
    rep(i, v) dp[i][i] = 0;
    rep(i, e) {
        int s, t, d;
        in(s, t, d);
        dp[s][t] = d;
    }

    if (warshallFloyd(dp, LLONG_MAX)) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    rep(i, v) {
        rep(j, v) {
            if (j > 0)
                cout << ' ';
            if (dp[i][j] == LLONG_MAX) {
                cout << "INF";
            } else {
                cout << dp[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
