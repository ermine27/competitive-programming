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
    int q, cmd, x;
    cin >> q;
    set<int> s;

    rep(i, q) {
        cin >> cmd >> x;
        if (cmd == 1) {
            s.insert(x);
        }
        if (cmd == 2) {
            s.erase(x);
        }
        if (cmd == 3) {
            auto it = s.lower_bound(x);
            int ans = *it;
            if (it == s.end()) {
                ans = -1;
            }
            cout << ans << endl;
        }
    }

    return 0;
}
