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
    ll n, m, b, asum = 0, csum = 0, ans = 0;
    cin >> n >> m >> b;
    rep(i, n) {
        int a;
        cin >> a;
        asum += a;
    }
    rep(i, m) {
        int c;
        cin >> c;
        csum += c;
    }

    ans = asum * m + b * n * m + csum * n;
    cout << ans << endl;
    return 0;
}
