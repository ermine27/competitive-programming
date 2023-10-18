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
    const int MOD = 1e9 + 7;
    int n, a1 = 1, a2 = 1, a3 = 1;
    cin >> n;
    rep(i, n - 2) {
        a3 = (a1 + a2) % MOD;
        a1 = a2;
        a2 = a3;
    }

    cout << a3 << endl;
    return 0;
}
