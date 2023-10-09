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
    const int DMAX = 1501;
    int n, a, b, c, d, ans = 0;
    vector<vector<int>> imos(DMAX + 1, vector<int>(DMAX + 1));
    cin >> n;
    rep(i, n) {
        cin >> a >> b >> c >> d;
        imos[a][b]++;
        imos[a][d]--;
        imos[c][b]--;
        imos[c][d]++;
    }

    rep(i, DMAX) rep(j, DMAX) imos[i][j + 1] += imos[i][j];
    rep(j, DMAX) rep(i, DMAX) imos[i + 1][j] += imos[i][j];
    rep(i, DMAX + 1) {
        rep(j, DMAX + 1) {
            if (imos[i][j] > 0)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
