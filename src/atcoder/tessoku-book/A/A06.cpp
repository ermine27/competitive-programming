#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repe(i, n) for (int i = 1; i <= (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int n, q;
    cin >> n >> q;
    vi a(n), c(n + 1);
    rep(i, n) {
        cin >> a[i];
        c[i + 1] = c[i] + a[i];
    }

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        cout << c[r] - c[l - 1] << endl;
    }

    return 0;
}
