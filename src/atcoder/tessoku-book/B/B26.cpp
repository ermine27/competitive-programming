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

    vi a(n + 1, 1);
    a[0] = a[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        for (int j = i * 2; j <= n; j += i) {
            a[j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[i])
            cout << i << endl;
    }
    return 0;
}
