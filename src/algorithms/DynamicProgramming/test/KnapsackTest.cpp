/*
ナップザック問題

問題例 DPL_1_C Knapsack Problem
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C
*/

#include "../../header.cpp"
#include "../Knapsack.hpp"

int main() {
    int n, m;
    in(n, m);
    vi v(n), w(n);
    rep(i, n) in(v[i], w[i]);
    vvi dp;
    cout << Knapsack(v, w, dp, m) << endl;
    return 0;
}
