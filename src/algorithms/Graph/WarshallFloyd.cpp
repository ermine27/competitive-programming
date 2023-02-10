/*
全点始点最短経路　（ワーシャルフロイド法）

参考ページ
https://algo-logic.info/warshall-floyd/
参考コード
https://github.com/ei1333/library/blob/master/graph/shortest-path/bellman-ford.hpp
問題例 GRL_1_C All Pairs Shortest Path
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
*/

/**
 * @fn warshallFloyd
 * @brief ワーシャルフロイド法を使って全点始点最短経路を求める
 * @param dist グラフの隣接行列
 * @retval 負の閉路の有無 (true:あり、false:なし)
 * @remark 計算量：O(|V|^3)
 */

#include "../header.cpp"

// const ll INF = 2e9;

template <typename Matrix>
bool warshallFloyd(Matrix &dist) {
    int v = dist.size();

    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][k] == INFLL || dist[k][j] == INFLL)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // ある頂点viからviへの最短距離が負である　→　負の閉路が存在する
    for (int i = 0; i < v; i++) {
        if (dist[i][i] < 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int v, e;
    in(v, e);
    vvls(dp, v, v, INFLL);
    rep(i, v) dp[i][i] = 0;
    rep(i, e) {
        int s, t, d;
        in(s, t, d);
        dp[s][t] = d;
    }

    if (warshallFloyd(dp)) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    rep(i, v) {
        rep(j, v) {
            if (j > 0)
                cout << ' ';
            if (dp[i][j] >= INFLL) {
                cout << "INF";
            } else {
                cout << dp[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
