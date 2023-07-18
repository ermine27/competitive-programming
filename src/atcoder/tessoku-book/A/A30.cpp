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

int main() {
    const ll mod = 1000000007;

    int n, r;
    cin >> n >> r;

    vl fact(n + 1), factinv(n + 1), inv(n + 1);
    fact[0] = fact[1] = 1;
    factinv[0] = factinv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        factinv[i] = factinv[i - 1] * inv[i] % mod;
    }

    ll ans = fact[n] * (factinv[r] * factinv[n - r] % mod) % mod;
    cout << ans << endl;
    return 0;
}
