/*
0-1ナップザック

問題例 DPL_1_B 0-1 Knapsack Problem
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B
*/

#include "../../header.cpp"
#include "../Knapsack01.hpp"

int main() {
    int n, m;
    in(n, m);
    vi v(n), w(n);
    rep(i, n) in(v[i], w[i]);
    vvi dp;
    cout << Knapsack01(v, w, dp, m) << endl;
    dbg(dp);
    return 0;
}
