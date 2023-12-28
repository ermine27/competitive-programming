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
    int d;
    cin >> d;
    vi c(d);
    cin >> c[0];
    rep(i, d - 1) {
        int a;
        cin >> a;
        c[i + 1] = c[i] + a;
    }

    int q;
    cin >> q;
    rep(i, q) {
        int s, t;
        cin >> s >> t;
        if (c[s - 1] == c[t - 1]) {
            cout << "Same" << endl;
        }
        if (c[s - 1] > c[t - 1]) {
            cout << s << endl;
        }
        if (c[s - 1] < c[t - 1]) {
            cout << t << endl;
        }
    }
    return 0;
}
