// クラスカル法
#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
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
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

struct UnionFind {
    vi rank, parent;

    // コンストラクタ
    // 各要素の親は自身にしておく
    // 各要素のランクは最初は0
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        rep(i, n) parent[i] = i;
    }

    // xを含む根（代表）を探す
    int findRoot(int x){
        if (parent[x] == x) return x;
        return findRoot(parent[x]);
    }

    // x,yを含む木を併合する
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

    // x,,が同じ木（集合）にあるかを判定する
    bool same(int x, int y){
        return findRoot(x) == findRoot(y);
    }
};

struct Edge{
    int from,to,cost;
    Edge(int f, int t, int c) : from(f), to(t), cost(c) {}
    // 次の行と下のコメント３つはどの書き方でも結果は変わらない
    bool operator < (const Edge &e) const { return cost < e.cost; }
    // friend bool operator < (const Edge &e1, const Edge &e2){ return e1.cost < e2.cost; }
};
// bool operator < (const Edge &e1, const Edge &e2){ return e1.cost < e2.cost; }
// これを使う場合はsortの第3引数に comp_e をつける
// bool comp_e(const Edge &e1, const Edge &e2){ return e1.cost < e2.cost; }

struct Kruskal {
    UnionFind uf;
    ll weight;
    vector<Edge> edges;

    Kruskal(int v, vector<Edge> &edges) : uf(v), weight(0) {
        // 重みの昇順でソートする
        sort(all(edges));
        fore(e,edges){
            if(uf.same(e.from,e.to)) continue;
            uf.unite(e.from, e.to);
            weight += e.cost;
        }
    }
};

int main(){
    int v,e;
    in(v,e);
    vector<Edge> edges;
    
    int s,t,w;
    rep(i,e){
        in(s,t,w);
        edges.emplace_back(s,t,w);
    }

    Kruskal mst(v,edges);
    out(mst.weight);
    return 0;
}
