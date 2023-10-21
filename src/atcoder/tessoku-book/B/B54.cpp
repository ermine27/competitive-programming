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
    int n, a;
    cin >> n;
    ll ans = 0;
    map<int, ll> m;
    rep(i, n) {
        cin >> a;
        m[a]++;
    }
    for (auto [key, val] : m) {
        ans += max(0LL, val * (val - 1) / 2);
    }
    cout << ans << endl;
    return 0;
}
