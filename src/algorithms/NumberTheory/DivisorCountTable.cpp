/**
 * Nまでの約数の個数を調べる
 *
 * @fn divisorCountTable
 * @brief 約数の個数のテーブルを作成する
 * @param x 2以上、10^7以下の整数
 * @retval 1からxまでの値についての約数の個数の配列
 * @remark 計算量：O(NlogN)
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> divisorCountTable(int x) {
    vector<int> primes(x + 1, 1);

    for (int i = 2; i <= x; ++i) {
        for (int j = i; j <= x; j += i) {
            primes[j]++;
        }
    }

    return primes;
}

int main() {
    int x;
    cin >> x;
    vector<int> d = divisorCountTable(x);

    for (int i = 1; i <= x; i++) {
        printf("%i = %d\n", i, d[i]);
    }

    return 0;
}
