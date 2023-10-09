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
    const int DMAX = 1500;
    int n, q, x, y, a, b, c, d;
    vector<vector<int>> p(DMAX + 2, vector<int>(DMAX + 2));
    vector<vector<int>> s(DMAX + 2, vector<int>(DMAX + 2));
    cin >> n;
    rep(i, n) {
        cin >> x >> y;
        p[x][y]++;
    }
    rep(i, DMAX + 1) {
        rep(j, DMAX + 1) { s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + p[i][j]; }
    }
    cin >> q;
    rep(i, q) {
        cin >> a >> b >> c >> d;
        c++;
        d++;
        cout << s[c][d] - s[a][d] - s[c][b] + s[a][b] << endl;
    }
    return 0;
}
