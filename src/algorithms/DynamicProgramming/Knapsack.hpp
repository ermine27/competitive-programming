/**
 * @brief ナップザック問題
 * 
 * @fn Knapsack01
 * @brief ナップザック問題
 * @param v Value（価値）のデータ
 * @param w Weight（重さ）のデータ
 * @param dp 
 * @param wmax 重さの上限
 * @remark 重みに負の数がある場合は計算ができないのでベルマンフォード法を使う
 * @remark 計算量：O(|E|log|V|)
 * 
 * 参考ページ
 * https://algo-logic.info/dijkstra/
 * 参考コード
 * https://github.com/ei1333/library/blob/master/graph/graph-template.hpp
 * 問題例 GRL_1_A Single Source Shortest Path
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
 */


template<typename T>
T Knapsack(const vector<T> &v, const vector<int> &w, vector<vector<T>> &dp, const T wmax){
    int n = v.size();
    dp.resize(n+1, vector<T>(wmax+1));

    for(int i=0; i<n; i++){
        for(int j=0; j<=wmax; j++){
            if(j>=w[i]){
                dp[i+1][j] = max(dp[i+1][j-w[i]]+v[i], dp[i][j]);
            } else {
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    return dp[n][wmax];
}
