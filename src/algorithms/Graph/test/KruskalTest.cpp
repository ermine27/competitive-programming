/*
最小全域木　（クラスカル法）

問題例 GRL_2_A Minimum Spanning Tree
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
*/

#include <bits/stdc++.h>
using namespace std;

#include "../Kruskal.hpp"

int main() {
    int v, e;
    cin >> v >> e;
    Edges<int> es;

    int s, t, w;
    for (int i = 0; i < e; i++) {
        cin >> s >> t >> w;
        es.emplace_back(s, t, w);
    }

    cout << Kruskal(es, v) << endl;
    return 0;
}
