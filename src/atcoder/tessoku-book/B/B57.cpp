/*
A57の応用問題。
1からNまでの各値について1回操作を行った結果を求め、それを使ってダブリングを行う
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
    int n, k;
    cin >> n >> k;

    vi a(n + 1);
    rep(i, n) {
        int t2 = i + 1, s = 0;
        while (t2 > 0) {
            s += t2 % 10;
            t2 /= 10;
        }
        a[i + 1] = i + 1 - s;
    }

    Doubling db(n + 1, 1e9, a);

    rep(i, n) { cout << db.query(i + 1, k) << endl; }

    return 0;
}
