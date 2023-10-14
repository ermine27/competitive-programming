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
    int n, q, x;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    cin >> q;
    rep(i, q) {
        cin >> x;
        cout << lower_bound(a.begin(), a.end(), x) - a.begin() << endl;
    }

    return 0;
}
