#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repe(i, n) for (int i = 1; i <= (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int h, w, q;
    cin >> h >> w;
    // int x[h][w], s[h+1][w+1];
    // memset(x, 0, sizeof(x));
    // memset(s, 0, sizeof(s));
    vector<vi> x(h, vi(w)), s(h + 1, vi(w + 1));
    rep(i, h) rep(j, w) cin >> x[i][j];

    rep(i, h) rep(j, w) { s[i + 1][j + 1] = s[i + 1][j] + x[i][j]; }
    rep(j, w) rep(i, h) { s[i + 1][j + 1] += s[i][j + 1]; }

    cin >> q;
    rep(i, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << s[c][d] - s[a - 1][d] - s[c][b - 1] + s[a - 1][b - 1] << endl;
    }
    return 0;
}
