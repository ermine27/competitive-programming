/*
「難易度×気温」の総和を最小値にするには、
難易度を昇順にソート、気温を降順にソートして、それを順番にAi*Biを足していけば求められる。
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
    int n, ans = 0;
    cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>{});
    rep(i, n) { ans += a[i] * b[i]; }

    cout << ans << endl;
    return 0;
}
