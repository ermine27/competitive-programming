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
    int n, m;
    cin >> n;
    vector<vi> a(n, vi(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    vi ord(n);
    rep(i, n) ord[i] = i;
    cin >> m;
    rep(i, m) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        x--;
        y--;
        if (cmd == 1) {
            swap(ord[x], ord[y]);
        } else {
            cout << a[ord[x]][y] << endl;
        }
    }
    return 0;
}
