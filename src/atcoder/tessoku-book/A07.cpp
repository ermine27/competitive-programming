#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repe(i, n) for (int i = 1; i <= (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int d, n, ans = 0;
    cin >> d >> n;
    vi imos(d + 1);

    rep(i, n) {
        int l, r;
        cin >> l >> r;
        imos[l - 1]++;
        imos[r]--;
    }
    rep(i, d) {
        ans += imos[i];
        cout << ans << endl;
    }
    return 0;
}
