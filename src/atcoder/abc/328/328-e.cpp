#ifdef INCLUDE_MAIN

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
    int from, to;
    ll cost;
    Edge() {}
    Edge(int from, int to, ll cost) : from(from), to(to), cost(cost) {}
};

int main() {
    int n, m;
    ll k;
    in(n, m, k);

    vector<Edge> e;
    rep(i, m) {
        int u, v;
        ll w;
        in(u, v, w);
        u--;
        v--;
        e.emplace_back(u, v, w);
    }
    vi use(m);
    rep(i, n - 1) use[i] = 1;
    reverse(all(use));

    ll ans = INFLL;
    do {
        UnionFind uf(n);
        ll cost = 0;
        bool ok = true;
        rep(i, m) {
            if (!use[i])
                continue;
            if (uf.same(e[i].from, e[i].to)) {
                ok = false;
                break;
            }
            uf.unite(e[i].from, e[i].to);
            cost += e[i].cost;
        }

        if (ok)
            chmin(ans, cost % k);
    } while (next_permutation(all(use)));

    out(ans);
    return 0;
}

// O(2^m)なので遅いがACはできる
int main2() {
    int n, m;
    ll k;
    in(n, m, k);

    vector<Edge> e;
    rep(i, m) {
        int u, v;
        ll w;
        in(u, v, w);
        u--;
        v--;
        e.emplace_back(u, v, w);
    }

    ll p = 1;
    rep(i, m) p *= 2;

    ll ans = INFLL;
    rep(i, p) {
        bitset<28> bs(i);
        if ((int)bs.count() != n - 1)
            continue;

        vi use;
        rep(j, 28) {
            if (bs[j])
                use.push_back(j);
        }

        UnionFind uf(n);
        ll cost = 0;
        bool ok = true;
        rep(j, n - 1) {
            if (uf.same(e[use[j]].from, e[use[j]].to)) {
                ok = false;
                break;
            }
            uf.unite(e[use[j]].from, e[use[j]].to);
            cost += e[use[j]].cost;
        }
        if (ok)
            chmin(ans, cost % k);
    }

    out(ans);
    return 0;
}

#else

#include <bits/stdc++.h>
using namespace std;

// clang-format off
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
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using mii = map<int,int>;
using mll = map<ll,ll>;
template<typename T> using priority_queue_asc = priority_queue<T, vector<T>, greater<T>>;
#define deg2rad(x) (x*M_PI/180.0)
#define rad2deg(x) (x*180.0/M_PI)
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void invec(T &x){ rep(i, sz(x)) cin >> x[i]; }
template<typename T> void invec2(T &x){ rep(i, sz(x)) invec(x[i]); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<typename T> void outvec(const vector<T>& v, char d = '\n'){ rep(i,sz(v)) cout << v[i] << (i == sz(v)-1 ? '\n' : d);}
#define yesno(x) cout << ((x) ? "Yes" : "No") << endl;
#define yes(x) if(x){ cout << "Yes" << endl; exit(0); }
#define no(x) if(x){ cout << "No" << endl; exit(0); }
const int INF = 1.1e9;
const ll INFLL = 4.4e18;
const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

#ifdef LOCAL
#include "debug_print.hpp"
#define dbg(...) cerr << '(' << __LINE__ << ')' << endl; debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) (static_cast<void>(0))
#endif
// clang-format on

#define INCLUDE_MAIN
#include __FILE__

#endif
