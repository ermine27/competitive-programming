/*
1列目 4*3 = 12通り
2列目
　1列目を固定した時の組み合わせは 2+2+3 = 7通り
　よって、12 * 7 = 84通り
3列目は？
　→2列目の組み合わせに依存する
　なので12*7*7通り
W列目は？
　W-1列目の組み合わせだけに依存する

よって、求める答えは 12 * 7^(N-1) 通りである。
*/
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

template <int MOD>
struct ModInt {
    long long val;
    constexpr int getmod() { return MOD; }
    constexpr ModInt(long long x = 0) noexcept : val(x % MOD) {
        if (val < 0)
            val += MOD;
    }
    constexpr ModInt operator-() const noexcept { return ModInt(-val); }
    constexpr bool operator==(const ModInt &rhs) const noexcept { return val == rhs.val; }
    constexpr bool operator!=(const ModInt &rhs) const noexcept { return val != rhs.val; }
    constexpr ModInt operator+(const ModInt &rhs) const noexcept { return ModInt(*this) += rhs; }
    constexpr ModInt operator-(const ModInt &rhs) const noexcept { return ModInt(*this) -= rhs; }
    constexpr ModInt operator*(const ModInt &rhs) const noexcept { return ModInt(*this) *= rhs; }
    constexpr ModInt operator/(const ModInt &rhs) const noexcept { return ModInt(*this) /= rhs; }
    constexpr ModInt &operator+=(const ModInt &rhs) noexcept {
        val += rhs.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs) noexcept {
        val -= rhs.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &rhs) noexcept {
        val = val * rhs.val % MOD;
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &rhs) noexcept {
        long long a = rhs.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr ModInt pow(long long n) noexcept {
        ModInt a = *this, res = 1;
        while (n > 0) {
            if (n & 1)
                res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }
    constexpr ModInt inv() noexcept { return pow(MOD - 2); }
    constexpr ModInt operator~() noexcept { return inv(); }
    friend constexpr ostream &operator<<(ostream &os, const ModInt &m) noexcept {
        os << m.val;
        return os;
    }
    friend constexpr istream &operator>>(istream &is, ModInt &m) noexcept {
        long long t;
        is >> t;
        m = ModInt<MOD>(t);
        return is;
    }
};

int main() {
    using mint = ModInt<1000000007>;
    ll w;
    cin >> w;
    cout << mint(12) * mint(7).pow(w - 1) << endl;
    return 0;
}
