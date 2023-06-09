#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repe(i, n) for (int i = 1; i <= (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    vi a(n + 1);
    rep(i, n) cin >> a[i];
    a[n] = 2e9;
    rep(i, n - 1) {
        auto f = a.begin() + i;
        auto t = upper_bound(f, a.end(), a[i] + k);
        ans += t - f - 1;
    }

    cout << ans << endl;
    return 0;
}
