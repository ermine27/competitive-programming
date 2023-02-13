/**
 * 素因数分解
 *
 * @fn primeFactorize, primeFactorizeMap
 * @brief 素因数分解をする
 * @param x 2以上、10^18以下の整数
 * @retval 入力値を素因数分解した結果
 * @remark 引数に1以下の値を入れた場合は正しい答えが返ってこない
 * @remark 計算量：O(√N)
 * @note primeFactorize はpair<int,int> 型の値を返し、primeFactorizeMap は map<int,int> 型の値を返す
 */

#include <bits/stdc++.h>
using namespace std;

// 素因数分解（pair版）
vector<pair<int, int>> primeFactorize(long long x) {
    vector<pair<int, int>> res;

    for (long long i = 2; i * i <= x; ++i) {
        int k = 0;
        while (x % i == 0) {
            x /= i;
            ++k;
        }
        if (k > 0) {
            res.push_back(make_pair(i, k));
        }
    }
    if (x != 1)
        res.push_back(make_pair(x, 1));

    return res;
}

// 素因数分解（map版）
map<int, int> primeFactorizeMap(long long x) {
    map<int, int> res;

    for (long long i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            x /= i;
            ++res[i];
        }
    }
    if (x != 1)
        res[x] = 1;

    return res;
}

int main() {
    long long n;
    cin >> n;

    auto ansPair = primeFactorize(n);

    puts("Pair");
    for (auto [k, v] : ansPair) printf("%d x %d\n", k, v);
    // fore(k, v, ansPair) printf("%d x %d\n", k, v);
    printf("\n");

    auto ansMap = primeFactorizeMap(n);

    puts("Map");
    for (auto [k, v] : ansMap) printf("%d x %d\n", k, v);
    // fore(k, v, ansMap) printf("%d x %d\n", k, v);
    printf("\n");

    return 0;
}
