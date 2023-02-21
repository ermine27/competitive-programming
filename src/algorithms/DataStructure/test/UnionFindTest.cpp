/*
Union Find

問題例 DSL_1_A Union Find Tree
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
*/

#include <bits/stdc++.h>
using namespace std;

#include "../UnionFind.hpp"

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind u = UnionFind(n);

    int com, x, y;
    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            u.unite(x, y);
        } else {
            cout << (u.same(x, y) ? 1 : 0) << endl;
        }
    }

    return 0;
}
