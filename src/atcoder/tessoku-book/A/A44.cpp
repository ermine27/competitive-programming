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
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) a[i] = i + 1;
    bool flag = false;

    rep(i, q) {
        int cmd, x, y;
        cin >> cmd;
        if (cmd == 1) {
            cin >> x >> y;
            if (flag)
                x = n - x + 1;
            a[x - 1] = y;
        }
        if (cmd == 2) {
            flag = !flag;
        }
        if (cmd == 3) {
            cin >> y;
            if (flag)
                y = n - y + 1;
            cout << a[y - 1] << endl;
        }
    }

    return 0;
}
