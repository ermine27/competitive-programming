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
    string s;
    cin >> n >> s;

    bool ok = false;
    rep(i, n - 2) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
            ok = true;
    }

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
