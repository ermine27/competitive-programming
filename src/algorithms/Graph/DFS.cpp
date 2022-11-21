/**
 * DFS（深さ優先探索）
 *
 * 問題例
 * ALDS1_11_B　Depth First Search
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B
 */

#include "../header.cpp"

// グラフ（隣接リスト）
vvi g;
// 探索済のノードか（有効グラフかつ閉路がない場合は不要）
set<int> used;

// 以下のグローバル変数は問題内容に応じて適宜用いる

// d:その頂点の発見時刻、f:その頂点の完了時刻（隣接リストを調べ終えた時刻）
vi d, f;
// 経過時間
int timer = 0;

void dfs(int x) {
    used.insert(x);

    // ベースケース

    if (d[x])
        return;

    // 再帰ステップ

    ++timer;
    d[x] = timer;

    fore(v, g[x]) {
        if (!used.count(v)) {
            used.insert(v);
            dfs(v);
            used.erase(v);
        }
    }

    ++timer;
    f[x] = timer;
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    d.resize(n);
    f.resize(n);

    rep(i, n) {
        int u, k, v;
        cin >> u >> k;

        rep(j, k) {
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

    rep(i, n) cout << i + 1 << ' ' << d[i] << ' ' << f[i] << endl;

    return 0;
}
