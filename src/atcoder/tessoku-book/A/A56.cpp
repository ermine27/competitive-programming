/*
文字列の比較を以下のようにsubstrを使って行うとTLEする。

if(s.substr(a-1,b-a+1) == s.substr(c-1,d-c+1)){
    cout << "Yes" << endl;
} else {
    cout << "No" << endl;

ローリングハッシュを使って解く

ハッシュ値を以下のように計算
hash(m) = A_1 * b^(m-1) + A_2 * b^(m-2) + ... + A_m * b^0
        = b * hash(m-1) + A_m
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

// 書き方１：クラスに分ける

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
    string s;
    cin >> n >> q >> s;

    RH hash(s);

    rep(i, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (hash.get(a, b) == hash.get(c, d))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}

// 書き方２：mainの中に全部処理を書く場合
int main2() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    vl hash(n + 1), pows(n + 1);
    pows[0] = 1;
    ll mod = 1000000007;
    ll base = 27;  // alphabet + 1

    // ハッシュテーブルを作成
    rep(i, n) {
        pows[i + 1] = (pows[i] * base) % mod;
        // 上：a=96のまま、下：a=1として扱う。どちらでも問題ない。
        hash[i + 1] = (hash[i] * base + s[i]) % mod;
        // hash[i+1] = (hash[i] * base + (s[i] - '`')) % mod;  // `:96 a:97 b:98
    }

    // クエリごとに判定
    rep(i, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ll hash1 = hash[b] - (hash[a - 1] * pows[b - a + 1]) % mod;
        ll hash2 = hash[d] - (hash[c - 1] * pows[d - c + 1]) % mod;
        if (hash1 < 0)
            hash1 += mod;
        if (hash2 < 0)
            hash2 += mod;
        // hash1 = (hash1 + mod) % mod;
        // hash2 = (hash2 + mod) % mod;
        if (hash1 == hash2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
