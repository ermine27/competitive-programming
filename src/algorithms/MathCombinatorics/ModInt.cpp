#include <bits/stdc++.h>
using namespace std;

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
