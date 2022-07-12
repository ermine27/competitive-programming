/*
深さ優先探索(DFS)
*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
using vi = vector<int>;
using vvi = vector<vi>;

vvi g;
vi k, d, f;
int timer = 0;

void dfs(int x) {
    if (d[x]) return;

    ++timer;
    d[x] = timer;

    rep(j, k[x]) {
        dfs(g[x][j]);
    }

    ++timer;
    f[x] = timer;
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    k.resize(n);
    d.resize(n);
    f.resize(n);

    rep(i, n) {
        int u, ki, v;
        cin >> u >> ki;
        k[i] = ki;

        rep(j, ki) {
            cin >> v;
            g[i].push_back(v - 1);
        }
    }

    int a = 0;
    while (a >= 0) {
        dfs(a);
        a = -1;
        rep(i, n) {
            if (d[i] == 0) {
                a = i;
                break;
            }
        }
    }

    rep(i, n) {
        cout << i + 1 << ' ' << d[i] << ' ' << f[i] << endl;
    }

    return 0;
}
