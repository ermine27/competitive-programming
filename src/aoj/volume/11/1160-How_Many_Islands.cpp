#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvl = vector<vl>;

const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

vvi c;
vvi v;
int w, h;
int ans;

void dfs(int x, int y) {
    rep(k, 8) {
        int ii = x + dx[k];
        int jj = y + dy[k];
        if (ii < 0 || ii >= h || jj < 0 || jj >= w || !c[ii][jj] || v[ii][jj])
            continue;
        v[ii][jj] = 1;

        dfs(ii, jj);
    }
}

int main() {
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        c.clear();
        v.clear();
        c.resize(h, vi(w));
        v.resize(h, vi(w));
        ans = 0;
        rep(i, h) rep(j, w) {
            cin >> c[i][j];
            v[i][j] = 0;
        }

        rep(i, h) rep(j, w) {
            if (c[i][j] && !v[i][j]) {
                dfs(i, j);
                ++ans;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
