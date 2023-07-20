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
    vi a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    int ans = 0;
    rep(i, 100) {
        rep(j, 100) {
            int cnt = 0;
            rep(t, n) {
                if (a[t] >= i && a[t] <= i + k && b[t] >= j && b[t] <= j + k)
                    cnt++;
            }
            chmax(ans, cnt);
        }
    }

    cout << ans << endl;
    return 0;
}
