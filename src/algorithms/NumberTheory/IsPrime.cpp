/**
 * 素数判定
 *
 * @fn isPrime
 * @brief 素数かどうかを判定する
 * @param x 2以上、10^18以下の整数
 * @retval true 素数
 * @retval false 素数ではない（合成数）
 * @remark 引数に1以下の値を入れた場合はfalseを返す
 * @remark 計算量：O(√N)
 */

#include "../header.cpp"

bool isPrime(ll x) {
    if (x < 2)
        return false;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    ll n;
    in(n);
    cout << (isPrime(n) ? "Yes" : "No") << endl;
    return 0;
}
