#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repe(i, n) for (int i = 1; i <= (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int n, k;
    cin >> n >> k;
    vi a(n), b(n), c(n), d(n), ab, cd;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    rep(i, n) cin >> d[i];
    rep(i, n) {
        rep(j, n) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }
    sort(cd.begin(), cd.end());
    rep(i, n * n) {
        if (binary_search(cd.begin(), cd.end(), k - ab[i]) == true) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
