/*
最小全域木(MST)　（プリム法）

問題例 ALDS_1_12_A Minimum Spanning Tree
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A
*/

#include "../../header.cpp"
#include "../Prim.hpp"

int main() {
    int n;
    cin >> n;
    Graph<int> g(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x >= 0) {
                g.addDirectedEdge(i, j, x);
            }
        }

    g.debug();

    vi prev;
    cout << prim(g, prev) << endl;

    return 0;
}
