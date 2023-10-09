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
    int n, q, a, l, r;
    cin >> n;
    vi s(n + 1);
    rep(i, n) {
        cin >> a;
        s[i + 1] = s[i] + a;
    }
    cin >> q;
    rep(i, q) {
        cin >> l >> r;
        int win = s[r] - s[l - 1], lose = r + 1 - l - win;
        if (win > lose)
            cout << "win" << endl;
        else if (win < lose)
            cout << "lose" << endl;
        else
            cout << "draw" << endl;
    }
    return 0;
}
