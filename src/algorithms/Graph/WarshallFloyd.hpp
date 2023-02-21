/**
 * ワーシャルフロイド法　（全点始点最短経路）
 *
 * @fn warshallFloyd
 * @brief ワーシャルフロイド法を使って全点始点最短経路を求める
 * @param dist グラフの隣接行列
 * @retval true 負の閉路あり
 * @retval false 負の閉路なし
 * @remark 計算量：O(|V|^3)
 *
 * 参考ページ
 * https://algo-logic.info/warshall-floyd/
 * 参考コード
 * https://github.com/ei1333/library/blob/master/graph/shortest-path/bellman-ford.hpp
 * 問題例 GRL_1_C All Pairs Shortest Path
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
 */

template <typename Matrix, typename T>
bool warshallFloyd(Matrix &dist, T INF) {
    int v = dist.size();

    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // ある頂点ViからVjへの最短距離が負である　→　負の閉路が存在する
    for (int i = 0; i < v; i++) {
        if (dist[i][i] < 0) {
            return true;
        }
    }
    return false;
}
