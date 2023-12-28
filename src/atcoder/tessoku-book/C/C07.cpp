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
    int n, q, x;
    cin >> n;
    vi c(n), b(n + 1);
    rep(i, n) { cin >> c[i]; }
    sort(c.begin(), c.end());
    rep(i, n) { b[i + 1] = b[i] + c[i]; }
    cin >> q;
    rep(i, q) {
        cin >> x;
        int ans = upper_bound(b.begin(), b.end(), x) - b.begin() - 1;
        cout << ans << endl;
    }

    return 0;
}
