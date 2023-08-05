/*
A33 - Game 2

この問題はNimという代表的な不偏ゲームである。
ゲーム理論のGrundy数を使う。
全ての要素のGrundy数のXORが0でなければ先手の勝ち、0の場合は後手の勝ちになる。

Nimの勝敗はニム和（全ての要素のXOR）が0でなければ先手の勝ち、0の場合は後手の勝ちになる。

参考：ゲーム理論・Grundy数
https://algo-logic.info/combinatorial-games/
https://www.creativ.xyz/grundy-number-1065/
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

int main() {
    int n, a, xor_sum = 0;
    cin >> n;
    rep(i, n) {
        cin >> a;
        xor_sum ^= a;
    }
    cout << (xor_sum == 0 ? "Second" : "First") << endl;
    return 0;
}
