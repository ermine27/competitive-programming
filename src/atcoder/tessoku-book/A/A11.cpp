#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repe(i, n) for (int i = 1; i <= (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    rep(i, n) cin >> a[i];
    int ans = upper_bound(a.begin(), a.end(), x) - a.begin();
    cout << ans << endl;
    return 0;
}
