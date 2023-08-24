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

struct Doubling {
    int bitWitdh;

    vector<vector<int>> table;

    Doubling(int n, int maxval, vector<int>& a) {
        bitWitdh = 1;
        while ((1 << bitWitdh) <= maxval) bitWitdh++;

        table.resize(bitWitdh, vector<int>(n));
        for (int i = 0; i < n; i++) {
            table[0][i] = a[i];
        }
        for (int k = 0; k < bitWitdh - 1; k++) {
            for (int i = 0; i < n; i++) {
                table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int query(int pos, int cnt) {
        for (int k = 0; cnt > 0; k++) {
            if (cnt & 1)
                pos = table[k][pos];
            cnt = cnt >> 1;
        }

        return pos;
    }
};

int main() {
    int n, q, x, y;
    cin >> n >> q;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }

    Doubling db(n, 1e9, a);

    // 実行
    rep(i, q) {
        cin >> x >> y;
        x--;
        cout << db.query(x, y) + 1 << endl;
    }

    return 0;
}

// 書き方２：mainの中に全部処理を書く場合
int main2() {
    int n, q, x, y;
    cin >> n >> q;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }

    // ダブリングの前処理
    int logK = 1;
    while ((1 << logK) <= 1e9) logK++;

    vector<vector<int>> doubling(logK, vector<int>(n));
    rep(i, n) { doubling[0][i] = a[i]; }
    rep(k, logK - 1) {
        rep(i, n) { doubling[k + 1][i] = doubling[k][doubling[k][i]]; }
    }

    // 実行
    rep(i, q) {
        cin >> x >> y;
        x--;
        for (int t = 0; y > 0; t++) {
            if (y & 1)
                x = doubling[t][x];
            y = y >> 1;
        }
        cout << x + 1 << endl;
    }

    return 0;
}
