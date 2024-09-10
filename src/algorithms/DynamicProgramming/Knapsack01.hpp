/**
 * @brief 0-1ナップザック
 * 
 * @fn Knapsack01
 * @brief 0-1ナップザック
 * @param v Value（価値）のデータ
 * @param w Weight（重さ）のデータ
 * @param dp 
 * @param wmax 重さの上限
 * @remark 計算量：O(N * wmax)
 * 
 * 問題例 DPL_1_B 0-1 Knapsack Problem
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B
 */


template<typename T>
T Knapsack01(const vector<T> &v, const vector<int> &w, vector<vector<T>> &dp, const T wmax){
    int n = v.size();
    dp.resize(n+1, vector<T>(wmax+1));

    for(int i=0; i<n; i++){
        for(int j=0; j<=wmax; j++){
            if(j>=w[i]){
                dp[i+1][j] = max(dp[i][j-w[i]]+v[i], dp[i][j]);
            } else {
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    return dp[n][wmax];
}
