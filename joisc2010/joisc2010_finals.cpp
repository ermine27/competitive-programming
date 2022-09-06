/*
クラスカル法で解く

最小全域木(MST)の場合は「辺の数＝頂点の数－１」になる。
本問では木の数が開催都市の個数になり、この場合は「辺の数＝頂点の数－開催都市の個数」になる。
通行料金を昇順でソートしたデータを使ってクラスカル法でMSTを作っていき、同時に追加した辺の数を数えておき、
頂点の数－開催都市の個数　回、辺を追加した時点の合計が求める答えになる。

*/

#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define _repe1(i,n) for(int i = 1; i <= (int)(n); ++i)
#define _repe2(i,s,n) for(int i = (int)(s); i <= (int)(n); ++i)
#define repe(...) _overload3(__VA_ARGS__, _repe2, _repe1)(__VA_ARGS__)
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

struct UnionFind {
    vi rank, parent;

    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        repe(i, n) parent[i] = i;
    }

    int findRoot(int x) {
        if (parent[x] == x) return x;
        return findRoot(parent[x]);
    }

    void unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);

        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            if (rank[x] == rank[y]) ++rank[y];
        }
    }

    bool same(int x, int y) {
        return findRoot(x) == findRoot(y);
    }
};

struct Edge {
    int from, to, cost;
    Edge(int f, int t, int c) : from(f), to(t), cost(c) {}
    bool operator<(const Edge& e) const { return cost < e.cost; }
};

struct Kruskal {
    UnionFind uf;
    int lines;
    ll weight;
    vector<Edge> edges;
    Kruskal(int v, int lines, vector<Edge>& edges) : uf(v), lines(lines), weight(0) {
        sort(all(edges));
        fore(e, edges) {
            if (uf.same(e.from, e.to)) continue;

            --lines;
            if (lines < 0) break;
            
            uf.unite(e.from, e.to);
            weight += e.cost;
        }
    }
};

int main() {
    int n, m, k;
    in(n, m, k);
    vector<Edge> edges;

    int a, b, c;
    rep(i, m) {
        in(a, b, c);
        edges.emplace_back(a, b, c);
        // edges.push_back(a,b,c);
    }

    Kruskal mst(n, n - k, edges);
    out(mst.weight);
    return 0;
}
