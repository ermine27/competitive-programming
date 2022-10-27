/*
この問題はスタート位置が決まっていないので、最大値となるようにするための開始点を探す必要がある。
開始点を探すためにDFSでの探索をm×n回行う必要がある。
そのため、探索済かを別の二次元配列に持たせるとかなり遅くなってしまう。（ACはできる）

高速化のためには、広場のデータを持つ二次元配列の中に移動済みかの情報を持たせるようにする。
移動済ははじめから薄氷がない状態と同じ扱いにしてもよく、
DFSの中で、一度移動済にして必要な処理が終わった後に移動済から元に戻すようにすれば、元の広場の情報は保持される。
また、DFSを関数に分けた場合、広場の情報を引数で受け渡すようにする場合は参照渡しで渡すようにしないと
呼び出しの度に配列が生成されるので速度は大幅に低下する。

*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
using vi = vector<int>;
using vvi = vector<vi>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int m, n;

int dfs(vvi &area, int x, int y, int c) {
    ++c;
    area[x][y] = 0;

    int mm = c;
    rep(k, 4) {
        int ii = x + dx[k];
        int jj = y + dy[k];
        if (ii < 0 || ii >= n || jj < 0 || jj >= m || !area[ii][jj]) continue;
        chmax(mm, dfs(area, ii, jj, c));
    }

    area[x][y] = 1;
    return mm;
}

int main() {
    cin >> m >> n;
    vvi area(n, vi(m));
    rep(i, n) rep(j, m) cin >> area[i][j];

    int ans = 0;
    rep(i, n) rep(j, m) {
        if (area[i][j]) {
            chmax(ans, dfs(area, i, j, 0));
        }
    }

    cout << ans << endl;
    return 0;
}
