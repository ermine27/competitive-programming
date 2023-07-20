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
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);

    rep(i, n) {
        int l, r;
        cin >> l >> r;
        p[i] = {r, l};
    }
    sort(p.begin(), p.end());
    int t = 0;
    int ans = 0;
    for (auto it = p.begin(); it != p.end(); it++) {
        if (it->second >= t) {
            t = it->first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
