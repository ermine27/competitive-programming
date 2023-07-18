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
    vi p(300001, 1);

    for (int i = 2; i * i <= 300000; i++) {
        for (int j = i * 2; j <= 300000; j += i) {
            p[j] = 0;
        }
    }

    int q, x;
    cin >> q;
    rep(i, q) {
        cin >> x;
        cout << (p[x] ? "Yes" : "No") << endl;
    }
    return 0;
}
