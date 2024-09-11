/**
 * @brief 二項係数を素数で割った剰余
 *
 * @struct ModBinomialCoefficients 二項係数　構造体
 * @param MOD 素数
 * @param n n
 * @note コンストラクタで前処理を行っている
 *
 * @fn ModBinomialCoefficients.com  nCk % MOD を返す
 * @param n, k nCkのnとk
 * @retval nCk % MOD の値

 * @remark 計算量：O(N）
 *
 * 参考コード
 * https://github.com/unonao/algorithms/blob/master/math_combinatorics/mod_binomial_coefficient.cpp
 *
 * 問題例  ABC034-C
 * https://atcoder.jp/contests/abc034/tasks/abc034_c
 */

template <int MOD>
struct ModBinomialCoefficients {
    int n;
    vector<long long> fact, factinv, inv;

    constexpr ModBinomialCoefficients(int n) noexcept : n(n) {
        fact.resize(n + 1);
        factinv.resize(n + 1);
        inv.resize(n + 1);

        fact[0] = fact[1] = 1;
        factinv[0] = factinv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            factinv[i] = factinv[i - 1] * inv[i] % MOD;
        }
    }

    // constexpr long long nCk(int k){
    constexpr long long com(int n, int k) {
        return fact[n] * (factinv[k] * factinv[n - k] % MOD) % MOD;
    }
};
