/**
 * @brief UnionFind構造体 (union by size)
 *
 * @struct UnionFind UnionFind構造体
 * @param n 頂点の数
 * @note インスタンス生成時に、各要素の親は自身を指定、各要素のサイズには1を指定しておく
 *
 * @fn UnionFind.find 頂点xを含む根（代表）を探す
 * @param x 頂点の番号
 * @return 頂点の代表番号
 * @note 経路圧縮を使って高速化させている（根を直接の親に再設定する）
 *
 * @fn Graph.unite 頂点x,yを含む木を併合する
 * @param x 結合したい頂点
 * @param y 結合したい頂点
 * @retval true 結合に成功
 * @retval false 結合に失敗（すでに結合されている）
 * @note union by size で高速化させている
 *    （サイズの大きい木の根を親、サイズの小さい木の根を子として辺を追加する）
 *     ソース上のswap処理の個所で行っている
 *
 * @fn Graph.same 頂点x,yが同じ木（集合）に属するかを判定する
 * @param x 1つ目の頂点
 * @param y 2つ目の頂点
 * @retval true 同一
 * @retval false 同一ではない
 * 
 * @fn Graph.size 頂点xが属する木の要素数を取得する
 * @return 頂点xが属する木の要素数
 * 
 * 
 * 参考ソース
 * https://github.com/ei1333/library/blob/master/graph/graph-template.hpp
 * 
 * 参考記事
 * https://qiita.com/saka_pon/items/2f18c84f1b6834e4fe4a
 * https://37zigen.com/union-find-complexity-1/
 * https://qiita.com/drken/items/cce6fc5c579051e64fab
 * https://noshi91.hatenablog.com/entry/2018/05/30/191943
 */

struct UnionFind {
    vector<int> _parent, _size;

    UnionFind(int n) {
        _parent.resize(n);
        _size.resize(n, 1);
        for(int i=0; i<n; i++) _parent[i] = i;
    }

    int find(int x) {
        if (_parent[x] == x) return x;
        return _parent[x] = find(_parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return false;
        if (_size[x] < _size[y]) swap(x, y);
        _parent[y] = x;
        _size[x] += _size[y];

        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return _size[find(x)]; }
};
