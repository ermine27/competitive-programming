/*
ドント式

N: 政党の数 (2<N<100,000)
A1, ..., An: 各政党への投票数 (1 <= Ai)
K: 議席数 (1 <= K <= 1e9)

A1+A2+...+An <= 1e9
ボーダーとなる「票数÷議席数」の値は 1 を超え 10^9 未満である
入力はすべて整数

　↓

方針
ボーダー数を2分探索する

二分探索の終了条件は、
ボーダーとなる「票数÷議席数」と次点の「票数÷議席数」の相対誤差は 10^−6 を超えた時

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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    double ok = 0.0;
    double ng = 1e9;

    // ボーダーをX票以上としたとき、その条件に当てはまる人数が議席数以上いるか
    auto check = [&](double x) -> int {
        int cnt = 0;  // 当選者数
        rep(i, n) { cnt += a[i] / x; }
        return cnt;
    };

    while (abs(ok - ng) > 1e-6) {
        double mid = (ok + ng) / 2;
        if (check(mid) >= k) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    rep(i, n) { cout << (int)(a[i] / ok) << ' '; }
    cout << endl;
    return 0;
}
