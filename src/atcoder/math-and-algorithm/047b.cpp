/*
UnionFindを使って二部グラフの判定をする
参考
https://noshi91.hatenablog.com/entry/2018/04/17/183132
https://ei1333.github.io/algorithm/union-find.html
*/

#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> _parent, _size;
    UnionFind(int n) {
        _parent.resize(n);
        _size.resize(n, 1);
        for (int i = 0; i < n; i++) _parent[i] = i;
    }
    int find(int x) {
        if (_parent[x] == x)
            return x;
        return _parent[x] = find(_parent[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (_size[x] < _size[y])
            swap(x, y);
        _parent[y] = x;
        _size[x] += _size[y];
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return _size[find(x)]; }
};

int main() {
    int n, m, a, b;
    cin >> n >> m;
    UnionFind uf(n * 2);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a, b + n);
        uf.unite(a + n, b);
    }

    for (int i = 0; i < n; i++) {
        if (uf.find(i) == uf.find(i + n)) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
