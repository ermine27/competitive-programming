/**
 * BFS（幅優先探索）
 *
 * 問題例
 * ALDS1_11_C　Breadth First Search
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
 */

#include "../header.cpp"

// グラフ（隣接リスト）
vvi g;
// 探索済のノードか → d[i]=-1 を未探索とすることでフラグは不要
// set<int> used;

// 以下のグローバル変数は問題内容に応じて適宜用いる

// 頂点1からの距離
vi d;

void bfs(int x) {
    d[x] = 0;
    queue<int> q;
    q.push(x);

    while (q.empty() == false) {
        int cur = q.front();
        q.pop();

        fore(x, g[cur]) {
            if (d[x] == -1) {
                d[x] = d[cur] + 1;
                q.push(x);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    g.resize(n);
    d.resize(n, -1);

    rep(i, n) {
        int u, k, v;
        cin >> u >> k;

        rep(j, k) {
            cin >> v;
            g[i].push_back(v - 1);
        }
    }

    bfs(0);

    rep(i, n) cout << i + 1 << ' ' << d[i] << endl;

    return 0;
}
