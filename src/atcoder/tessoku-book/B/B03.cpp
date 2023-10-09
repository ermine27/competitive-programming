#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
// clang-format on

int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    rep(i, n) {
        rep(j, n) {
            rep(k, n) {
                if (i != j && j != k && k != i && a[i] + a[j] + a[k] == 1000) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
