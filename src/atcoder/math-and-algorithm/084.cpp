#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1.0e-14;

int main() {
    long double a, b, c;
    cin >> a >> b >> c;
    cout << (sqrt(a) + sqrt(b) < sqrt(c) - EPS ? "Yes" : "No") << endl;
    return 0;
}

// 別解：整数のまま比較する
// 二乗してルートを外したものを式変形すると2つの不等式に変形できる（公式解説参照）
int main2() {
    long long a, b, c, d;
    cin >> a >> b >> c;
    d = c - a - b;
    cout << (d > 0 && d * d > 4 * a * b ? "Yes" : "No") << endl;
    return 0;
}