/*
連結成分分解

各QごとにDFSやBFSで探索すると制限時間内に処理が完了しない。
予めグラフの連結成分を求めておく。
未訪問の頂点を始点として探索をして、全ての頂点をグループ化し、
Qごとに指定された2つの点が同じグループに属するかだけを判定することで高速に実行できる。
*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define fore(x, a) for (auto& x : a)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using vvi = vector<vi>;

vvi g;
vi v;
vi color;

void dfs(int x, int c) {
    v[x] = 1;
    color[x] = c;

    fore(t, g[x]) {
        if (!v[t]) {
            dfs(t, c);
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m;
    g.resize(n);
    v.resize(n, 0);
    color.resize(n);

    int x, y;
    rep(i, m) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // グループ化
    int cc = 1;
    rep(i, n) {
        if (v[i]) continue;
        dfs(i, cc);
        ++cc;
    }

    // グループ化したテーブルを使って判定
    cin >> q;
    rep(i, q) {
        cin >> x >> y;
        cout << (color[x] == color[y] ? "yes" : "no") << endl;
    }

    return 0;
}
