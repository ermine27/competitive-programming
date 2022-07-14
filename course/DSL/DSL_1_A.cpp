/*
互いに素な結合

UnionFindを使う
併合する時には、低い方の木を高い方の木に併合して木の高さが高くならなようにする

参考にしたサイト
https://algo-logic.info/union-find-tree/
*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(v) v.begin(), v.end()
using vi = vector<int>;

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

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind u = UnionFind(n);

    int com, x, y;
    rep(i, q) {
        cin >> com >> x >> y;

        if (com == 0) {
            u.unite(x, y);
        } else {
            cout << (u.same(x, y) ? 1 : 0) << endl;
        }
    }

    return 0;
}
