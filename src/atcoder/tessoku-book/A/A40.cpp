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
    vi a(100);
    rep(i, n) {
        int ai;
        cin >> ai;
        a[ai - 1]++;
    }

    ll ans = 0;
    rep(i, 100) {
        // 分岐がなくても正しい答えは得られる
        // if(a[i] >= 3){
        ans += 1LL * a[i] * (a[i] - 1) * (a[i] - 2) / 6;
        // }
    }

    cout << ans << endl;
    return 0;
}
