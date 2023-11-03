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
    int n, h, w, a, b, grundy = 0;
    cin >> n >> h >> w;
    rep(i, n) {
        cin >> a >> b;
        grundy ^= (a - 1) ^ (b - 1);
    }
    cout << (grundy ? "First" : "Second") << endl;
    return 0;
}
