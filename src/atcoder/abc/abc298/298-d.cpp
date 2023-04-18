#ifdef INCLUDE_MAIN

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

using mint = ModInt<998244353>;

int main() {
    mint ans = 1;

    int q, cmd;
    in(q);
    queue<int> que;
    que.push(1);

    rep(i, q) {
        in(cmd);
        if (cmd == 1) {
            int x;
            in(x);
            que.push(x);
            ans = ans * 10 + x;
        }
        if (cmd == 2) {
            ans -= mint(10).pow(que.size() - 1) * que.front();
            que.pop();
        }
        if (cmd == 3) {
            out(ans);
        }
    }

    return 0;
}
#else

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define _repe1(i,n) for(int i = 1; i <= (int)(n); ++i)
#define _repe2(i,s,n) for(int i = (int)(s); i <= (int)(n); ++i)
#define repe(...) _overload3(__VA_ARGS__, _repe2, _repe1)(__VA_ARGS__)
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using mii = map<int,int>;
using mll = map<ll,ll>;
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))
#define deg2rad(x) (x*M_PI/180.0)
#define rad2deg(x) (x*180.0/M_PI)
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void invec(T &x){ rep(i, sz(x)) cin >> x[i]; }
template<typename T> void invec2(T &x){ rep(i, sz(x)) invec(x[i]); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<typename T> void outvec(const vector<T>& v, char d = '\n'){ rep(i,sz(v)) cout << v[i] << (i == sz(v)-1 ? '\n' : d);}
#define yesno(x) cout << ((x) ? "Yes" : "No") << endl;
#define yes(x) if(x){ cout << "Yes" << endl; exit(0); }
#define no(x) if(x){ cout << "No" << endl; exit(0); }
const int INF = 1.1e9;
const ll INFLL = 4.4e18;
const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

#ifdef LOCAL
#include "debug_print.hpp"
#define dbg(...) cerr << '(' << __LINE__ << ')' << endl; debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) (static_cast<void>(0))
#endif
// clang-format on

#define INCLUDE_MAIN
#include __FILE__

#endif
