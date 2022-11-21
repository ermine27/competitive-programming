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

#include "../header.cpp"

vl divisor(ll x) {
    vl ans;
    for (ll i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            ans.push_back(i);
            if (i * i != x) {
                ans.push_back(x / i);
            }
        }
    }

    sort(all(ans));
    return ans;
}

int main() {
    ll n;
    in(n);
    vl d = divisor(n);

    fore(a, d) cout << ' ' << a;
    cout << endl;

    return 0;
}
