/*
H<=10, W<=100なので、Hでビット全探索を行う。
この時、「K-塗り替えを行った行数の数」が塗り替えができる列数になり、
行の塗り替えを行った後の状態を使って塗り替えをするのに最適な列を見つける。
なお、列の塗り替えについては実際に1個ずつ行わなくても、列ごとの黒の数の配列を使えば塗り替わった個数は分かる。
この2段階の処理を行うことで答えが求められる。
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

int countIsBlack(int h, int w, vector<vector<int>>& c) {
    int res = 0;
    rep(i, h) {
        rep(j, w) { res += c[i][j]; }
    }
    return res;
}

int main() {
    int h, w, k, ans = 0;
    cin >> h >> w >> k;
    vector<vector<int>> c(h, vector<int>(w));
    rep(i, h) {
        rep(j, w) {
            char x;
            cin >> x;
            c[i][j] = (x == '#' ? 1 : 0);
        }
    }

    rep(i, 1 << h) {
        bitset<10> bs(i);
        int remain = k - bs.count();
        if (remain < 0)
            continue;

        vector<vector<int>> c2 = c;

        rep(j, h) {
            if (bs[j]) {
                rep(k, w) { c2[j][k] = 1; }
            }
        }

        vector<int> rowsum(w);
        int ternrow = 0;
        rep(j, w) {
            rep(k, h) { rowsum[j] += c2[k][j]; }
        }
        sort(rowsum.begin(), rowsum.end());
        rep(j, remain) { ternrow += h - rowsum[j]; }

        int cnt = countIsBlack(h, w, c2) + ternrow;
        chmax(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}

/*
以下のコードは列の処理は行わず、行だけで塗り替えを行っているがこれでもACする。
ただし、次のようなテストケースだと正しい答えが得られない？

5 10 2
###..#####
###..#####
###....###
###..#####
###..#####
*/
int main2() {
    int h, w, k, ans = 0;
    cin >> h >> w >> k;
    vector<vector<int>> c(h, vector<int>(w));
    rep(i, h) {
        rep(j, w) {
            char x;
            cin >> x;
            c[i][j] = (x == '#' ? 1 : 0);
        }
    }

    rep(i, 1 << h) {
        bitset<10> bs(i);
        if ((int)bs.count() > k)
            continue;

        vector<vector<int>> c2 = c;

        rep(j, h) {
            if (bs[j]) {
                rep(k, w) { c2[j][k] = 1; }
            }
        }
        int cnt = countIsBlack(h, w, c2);
        chmax(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
