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
    int n;
    ll a, k, ans = 0;
    cin >> n >> k;
    vl c(n + 1);
    rep(i, n) {
        cin >> a;
        c[i + 1] = c[i] + a;
    }

    int r = 0;
    rep(l, n) {
        while (c[r] - c[l] <= k && r <= n) {
            r++;
        }
        ans += (r - l - 1);
    }

    cout << ans << endl;
    return 0;
}
