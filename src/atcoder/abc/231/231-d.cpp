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
using mii = map<int,int>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }


struct UnionFind {
    vi _parent, _size;

    UnionFind(int n) {
        _parent.resize(n);
        _size.resize(n, 1);
        rep(i, n) _parent[i] = i;
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

int main() {
    int n, m, ai, bi;
    cin >> n >> m;
    vi r(n);
    UnionFind u = UnionFind(n);
    bool ok = true;

    rep(i, m) {
        in(ai, bi);
        --ai;
        --bi;
        r[ai]++;
        r[bi]++;

        if (u.same(ai, bi)) {
            ok = false;
            break;
        }
        u.unite(ai, bi);
    }

    if (*max_element(all(r)) > 2) ok = false;

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
