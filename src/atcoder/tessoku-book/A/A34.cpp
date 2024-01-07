/*
A34 - Game 3

A33 Game 2 の応用問題。
これも不偏ゲームであるのでGrundy数を使う。
本問では1回の操作で取れる石の数がXかYのどちらかという制約があるので、
・各山においてのGrumdy数
・最終的なGrumdy数
の2段階で求める。

各山のGrundy数（Mex）はメモ化再帰で求める。
例：ex.1の場合
    Mex({0}) = 0
    Mex({1}) = 0
    Mex({2}) = 1
    Mex({3}) = Mex({0,1}) = 1
    Mex({4}) = Mex({1,2}) = 2
    Mex({5}) = Mex({2,3}) = 0
    Mex({6}) = Mex{(3,4)} = 0
    Mex({7}) = Mex({4,5}) = 1
    Mex({8}) = Mex({5,6}) = 1

参考：ゲーム理論・Grundy数
https://algo-logic.info/combinatorial-games/
参考：Grundy数（Nim数, Nimber）の理論
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
    int n, x, y, ans = 0;
    cin >> n >> x >> y;
    vi a(n);
    rep(i, n) cin >> a[i];

    int maxval = *max_element(a.begin(), a.end()) + 1;
    vi grundy(maxval, -1);

    // 各山のGrumdy数を求める
    auto solveGrumdy = [&](auto self, int v) -> int {
        if (v == 0)
            return 0;
        if (grundy[v] != -1)
            return grundy[v];

        // 要素がX,Yの2つなのでGrundy数の取り得る範囲は0～2になる
        set<int> res = {0, 1, 2};
        if (v >= x) {
            res.erase(self(self, v - x));
        }
        if (v >= y) {
            res.erase(self(self, v - y));
        }
        return *res.begin();
    };
    rep(i, maxval) { grundy[i] = solveGrumdy(solveGrumdy, i); }

    // 全体のGrundy数を求める
    rep(i, n) { ans ^= grundy[a[i]]; }

    cout << (ans == 0 ? "Second" : "First") << endl;
    return 0;
}
