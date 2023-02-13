/**
 * 約数列挙
 *
 * @fn divisor
 * @brief 約数を列挙する
 * @param x 1以上、10^9以下の整数
 * @retval xの全ての約数
 * @remark 計算量：O(√N)
 * @remark xが10^15くらいまでなら高速に処理ができるが、それ以上の値だと1秒以内には処理が終わらない
 */

#include <bits/stdc++.h>
using namespace std;

vector<long long> divisor(long long x) {
    vector<long long> ans;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            ans.push_back(i);
            if (i * i != x) {
                ans.push_back(x / i);
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> d = divisor(n);

    for (auto a : d) cout << ' ' << a;
    // fore(a, d) cout << ' ' << a;
    cout << endl;

    return 0;
}
