/*
二次元いもす法＋二次元累積和

参考：二次元いもす法
https://imoz.jp/algorithms/imos_method.html
https://zenn.dev/reputeless/articles/article-2d-imos
*/
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<vi> imos(h + 1, vi(w + 1));
    rep(i, n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        imos[a][b]++;
        imos[a][d]--;
        imos[c][b]--;
        imos[c][d]++;
    }

    // 二次元累積和
    rep(i, h) {
        rep(j, w) { imos[i][j + 1] += imos[i][j]; }
    }
    rep(j, w) {
        rep(i, h) { imos[i + 1][j] += imos[i][j]; }
    }

    rep(i, h) {
        rep(j, w) { cout << imos[i][j] << ' '; }
        cout << endl;
    }
    return 0;
}
