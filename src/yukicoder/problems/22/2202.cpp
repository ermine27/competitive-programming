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
    int n, m;
    cin >> n >> m;
    UnionFind uf(n * 2);

    vector<vector<int>> g1, g2;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a, b + n);
        uf.unite(a + n, b);
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (!uf.same(i, i + n))
            ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
}
