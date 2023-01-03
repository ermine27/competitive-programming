/**
 * UnionFindを使って解く
 *
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
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a, b);
    }

    bool ok = true;
    int root = uf.find(0);
    for (int i = 0; i < n; i++) {
        if (uf.find(i) != root)
            ok = false;
    }

    if (ok)
        cout << "The graph is connected." << endl;
    else
        cout << "The graph is not connected." << endl;

    return 0;
}
