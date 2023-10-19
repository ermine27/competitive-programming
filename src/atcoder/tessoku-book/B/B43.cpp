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
    cin >> n >> m;
    vi w(n, m);
    rep(i, m) {
        int a;
        cin >> a;
        w[a - 1]--;
    }
    rep(i, n) cout << w[i] << endl;
    return 0;
}
