#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repe(i, n) for (int i = 1; i <= (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int h, w, n, ans = 0;
    cin >> h >> w >> n;
    vector<vi> imos(h + 1, vi(w + 1));
    rep(i, n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = a; j <= c; j++) {
            imos[j - 1][b - 1]++;
            imos[j - 1][d]--;
        }
    }
    rep(i, h) {
        ans = 0;
        rep(j, w) {
            ans += imos[i][j];
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0;
}
