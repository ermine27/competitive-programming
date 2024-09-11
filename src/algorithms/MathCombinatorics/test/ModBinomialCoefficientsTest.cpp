/*
二項係数の素数剰余

問題例 ABC 034-C 経路
https://atcoder.jp/contests/abc034/tasks/abc034_c
*/

#include <bits/stdc++.h>
using namespace std;

#include "../ModBinomialCoefficients.hpp"

int main() {
    int w, h, s;
    cin >> w >> h;
    --w;
    --h;
    s = w + h;

    ModBinomialCoefficients<1000000007> nck(s);
    cout << nck.com(s, h) << endl;
    return 0;
}
