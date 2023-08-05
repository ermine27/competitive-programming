/*
A32 - Game 1

石の数がN個の場合の勝敗は、N-Aの勝敗とN-Bの勝敗によって決まる。

両者が最善を尽くすという条件下では、N個の場合に先手が勝つのであれば、その1個前の状態であるN-A個とN-B個の場合は後手が勝つ。
先手が勝つ場合をF, 後手が勝つ場合をSと表現すると、DPを使って、
dp[i] =
  F {(i>=A and dp[i-A] = T) and (i>=B and dp[i-B] = T)}
  T (上記以外)
で求められる。
公式の解説では以下のように書いている。
dp[i] =
  T (i>=A and dp[i-A] = F) or (i>=B and dp[i-B] = F)
  F (上記以外)
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
    cin >> n >> a >> b;
    vector<int> dp(n + 1);  // 1: First, 0: Second

    for (int i = a; i <= n; i++) {
        if ((i - a >= 0 && dp[i - a]) && (i - b >= 0 && dp[i - b]))
            dp[i] = 0;
        else
            dp[i] = 1;
    }

    cout << (dp[n] ? "First" : "Second") << endl;
    return 0;
}
