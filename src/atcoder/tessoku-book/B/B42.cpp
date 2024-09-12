/*
[スコア]=[選んだカードにおける表の総和の絶対値]
       +[選んだカードにおける裏の総和の絶対値]

なので、表の総和と裏の総和について別々に考える。
また、絶対値の和なので、正の場合と負の場合の両方を考える。
この２つをかけわせた4つのパターンについて、i=1...Nの順にみて、それぞれのパターンごとにカードを選ぶかを決めればよい。
・表の総和（正）＋表の総和（正）の最大値
・表の総和（正）＋表の総和（負）の最大値
・表の総和（負）＋裏の総和（正）の最大値
・表の総和（負）＋裏の総和（負）の最大値
最終的にこの４つの最大値の中で、一番大きいものが求めるべき答えになる。

計算量はO(N)
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
    int n, a, b;
    cin >> n;
    ll pp = 0LL, pn = 0LL, np = 0LL, nn = 0LL;

    rep(i, n) {
        cin >> a >> b;
        chmax(pp, pp + a + b);
        chmax(pn, pn + a - b);
        chmax(np, np - a + b);
        chmax(nn, nn - a - b);
    }

    cout << max({pp, pn, np, nn}) << endl;
    return 0;
}
