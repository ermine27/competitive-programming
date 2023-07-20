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
    int d, n;
    cin >> d >> n;
    vi t(d, 24);
    rep(i, n) {
        int l, r, h;
        cin >> l >> r >> h;
        l--;
        r--;
        for (int j = l; j <= r; j++) chmin(t[j], h);
    }

    int ans = 0;
    rep(i, d) ans += t[i];
    cout << ans << endl;

    return 0;
}
