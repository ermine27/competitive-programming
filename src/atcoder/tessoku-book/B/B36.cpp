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
    int n, k, c = 0;
    string s;
    cin >> n >> k >> s;

    rep(i, n) {
        if (s[i] == '1')
            c++;
    }

    cout << (c % 2 == k % 2 ? "Yes" : "No") << endl;
    return 0;
}
