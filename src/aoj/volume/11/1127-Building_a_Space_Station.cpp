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
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename T> T square (T x) { return x * x; }
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

    int findRoot(int x){
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

    bool same(int x, int y){
        return findRoot(x) == findRoot(y);
    }
};

struct Edge{
    int from,to;
    double cost;
    Edge(int f, int t, double c) : from(f), to(t), cost(c) {}
    bool operator < (const Edge &e) const { return cost < e.cost; }
};

struct Kruskal {
    UnionFind uf;
    double weight;
    vector<Edge> edges;
    Kruskal(int v, vector<Edge> &edges) : uf(v), weight(0) {
        fore(e, edges) {
            if (uf.same(e.from, e.to)) continue;
            uf.unite(e.from, e.to);
            weight += e.cost;
        }
    }
};

int main() {
    while (true) {
        int n;
        in(n);
        if (n == 0) break;

        vector<double> x(n), y(n), z(n), r(n);
        rep(i, n) in(x[i], y[i], z[i], r[i]);

        vector<Edge> cor;
        rep(i, n - 1) {
            rep(j, i + 1, n) {
                double d = max(0.0, sqrt(square(x[i] - x[j]) + square(y[i] - y[j]) + square(z[i] - z[j])) - r[i] - r[j]);
                cor.emplace_back(i, j, d);
            }
        }

        sort(all(cor));
        Kruskal mst(n, cor);
        printf("%.3f\n", round(mst.weight * 1000) / 1000);
    }

    return 0;
}
