/*
A56の応用問題。
ローリングハッシュを使って回文かどうかを判定するには、
SとSを反転した2つの文字列のハッシュ値で比較すればよい。
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
struct RollingHash {
    vector<long long> _hash, _power;

    RollingHash(string& s, int base = 27) {
        int len = s.length();
        _hash.assign(len + 1, 0);
        _power.assign(len + 1, 0);
        _power[0] = 1;

        for (int i = 0; i < len; i++) {
            _power[i + 1] = (_power[i] * base) % MOD;
            _hash[i + 1] = (_hash[i] * base + s[i]) % MOD;
        }
    }

    long long get(int l, int r) {
        long long res = _hash[r] - (_hash[l - 1] * _power[r - l + 1]) % MOD;
        if (res < 0)
            res += MOD;
        return res;
    }
};

using RH = RollingHash<1000000007>;

int main() {
    int n, q;
    string s, s2;
    cin >> n >> q >> s;
    s2 = s;
    reverse(s2.begin(), s2.end());

    RH hash(s), hash2(s2);

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        if (hash.get(l, r) == hash2.get(n - r + 1, n - l + 1))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
