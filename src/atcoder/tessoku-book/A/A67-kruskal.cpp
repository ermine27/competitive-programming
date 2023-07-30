#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

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

struct Edge {
    int from, to, cost;
    Edge() = default;
    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
    inline bool operator<(const Edge& e) const { return cost < e.cost; }
};

int Kruskal(vector<Edge>& edges, int v) {
    UnionFind uf(v);
    int res = 0;
    sort(edges.begin(), edges.end());

    for (auto e : edges) {
        if (uf.unite(e.from, e.to)) {
            res += e.cost;
        }
    }
    return res;
};

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    vector<Edge> e;

    rep(i, m) {
        cin >> a >> b >> c;
        a--;
        b--;
        e.emplace_back(a, b, c);
    }

    cout << Kruskal(e, n) << endl;
    return 0;
}
