/*
UnionFind (union by size)

参考記事
https://qiita.com/saka_pon/items/2f18c84f1b6834e4fe4a
https://37zigen.com/union-find-complexity-1/
https://qiita.com/drken/items/cce6fc5c579051e64fab
https://noshi91.hatenablog.com/entry/2018/05/30/191943
*/

#include <bits/stdc++.h>
using namespace std;

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

// コメントあり
struct UnionFindWithComment {
    vector<int> _parent, _size;

    // コンストラクタ
    // 各要素の親は自身にしておく
    // 各要素のサイズの初期値は1
    UnionFindWithComment(int n) {
        _parent.resize(n);
        _size.resize(n, 1);
        for(int i=0; i<n; i++) _parent[i] = i;
    }

    // xを含む根（代表）を探す
    int find(int x) {
        if (_parent[x] == x) return x;
        // 経路圧縮で高速化（根を直接の親に再設定する）
        return _parent[x] = find(_parent[x]);
    }

    // xが属する木の要素数を取得する
    int size(int x) { return _size[find(x)]; }

    // x,yを含む木を併合するsh
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return false;
        // union by size で高速化（サイズの大きい木の根を親、サイズの小さい木の根を子として辺を追加する）
        if (_size[x] < _size[y]) swap(x, y);
        _parent[y] = x;
        _size[x] += _size[y];

        return true;
    }

    // x,yが同じ木（集合）にあるかを判定する
    bool same(int x, int y) { return find(x) == find(y); }

};

// 使用例
int main() {
    int n;
    cin >> n;
    UnionFind u = UnionFind(n);

    int com, x, y;
    for(int i=0; i<n; i++){
        cin >> com >> x >> y;

        if (com == 0) {
            u.unite(x, y);
        } else {
            cout << (u.same(x, y) ? 1 : 0) << endl;
        }
    }

    return 0;
}
