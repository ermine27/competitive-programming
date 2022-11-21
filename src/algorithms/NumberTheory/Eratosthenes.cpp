/**
 * 素数列挙
 *
 * @fn eratosthenes
 * @brief 素数列挙（エラトステネスの篩）
 * @param x 2以上、10^6以下の整数
 * @retval 素数の集合
 *
 * @fn eratosthenesTable
 * @brief 素数判定のテーブルを作成する（エラトステネスの篩）
 * @param x 2以上、10^6以下の整数
 * @retval xまでの値について素数かどうかの配列
 * @remark 出力される配列の値は素数なら1、素数でないなら0が入る
 */

#include "../header.cpp"

set<int> eratosthenes(int x) {
    set<int> primes;
    for (int i = 2; i <= x; ++i) primes.insert(i);

    for (int i = 2; i * i < x; ++i) {
        if (primes.count(i)) {
            for (int j = i * 2; j <= x; j += i) {
                primes.erase(j);
            }
        }
    }

    return primes;
}

vector<bool> eratosthenesTable(int x) {
    vector<bool> primes(x + 1, 1);
    primes[0] = primes[1] = false;
    vi res;

    for (int i = 2; i * i < x; ++i) {
        if (!primes[i])
            continue;
        res.push_back(i);

        for (int j = i * 2; j <= x; j += i) {
            primes[j] = false;
        }
    }

    return primes;
}

int main() {
    int x;
    in(x);

    set<int> ans = eratosthenes(x);

    cout << "[set]" << endl;
    fore(v, ans) cout << ' ' << v;
    cout << endl;

    vector<bool> ans2 = eratosthenesTable(x);

    cout << "[vector(table)]" << endl;
    rep(i, x) cout << ' ' << ans2[i];
    cout << endl;

    return 0;
}