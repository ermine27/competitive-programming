/*
隣接リストを隣接行列に変換する
*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    vvi g(n, vi(n));

    rep(i, n) {
        int u, k, v;
        cin >> u >> k;

        rep(j, k) {
            cin >> v;
            g[u - 1][v - 1] = 1;
        }
    }

    rep(i, n) {
        rep(j, n) {
            if (j) cout << ' ';
            cout << g[i][j];
        }
        cout << endl;
    }

    return 0;
}
