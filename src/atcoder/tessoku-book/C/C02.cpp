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
    vi a(n);
    rep(i, n) { cin >> a[i]; }
    sort(a.begin(), a.end(), greater<int>());

    cout << a[0] + a[1] << endl;
    return 0;
}
