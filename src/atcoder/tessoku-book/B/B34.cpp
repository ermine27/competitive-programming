/*
B34 - Game 7

A34 Game 3 の類題。
Ai <= 10^18 と大きいのでA34と同様に Ai=1,2,... と順番に求めることができない。
(X,Y) = (2,3) で固定されているのでGrundy数は、
 [ 0 0 1 1 2 0 0 1 1 2 0 0 1 1 2 ....]
の周期性がある。modを使うことでTLEしない計算量で求められるようになる。
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
    vl a(n);
    vi g(n);
    rep(i, n) cin >> a[i];

    rep(i, n) { g[i] = (a[i] % 5) / 2; }

    rep(i, n) { ans ^= g[i]; }
    cout << (ans == 0 ? "Second" : "First") << endl;
    return 0;
}
