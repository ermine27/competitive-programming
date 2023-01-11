#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

using Matrix = vector<vector<long long>>;

// 行列の掛け算
Matrix matrixMultiple(Matrix a, Matrix b) {
    int r = a.size(), m = b.size(), c = b.at(0).size();
    Matrix res(r, vector<long long>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < m; ++k) {
                (res[i][j] += a[i][k] * b[k][j]) %= mod;
            }
        }
    }
    return res;
}

// 行列の累乗
Matrix matrixModpow(Matrix a, long long n) {
    int r = a.size(), c = a.at(0).size();
    Matrix res(r, vector<long long>(c));

    // 単位行列で初期化する
    for (int i = 0; i < r; i++) res[i][i] = 1;

    // 繰り返し二乗法で累乗を計算
    while (n > 0) {
        if (n & 1) {
            res = matrixMultiple(res, a);
        }
        a = matrixMultiple(a, a);
        n >>= 1;
    }
    return res;
}

int main() {
    long long n;
    cin >> n;

    Matrix as = {{2, 1}, {1, 0}};
    Matrix a = matrixModpow(as, n - 1);
    Matrix ans = matrixMultiple(a, {{1}, {1}});

    cout << ans[1][0] << endl;
    return 0;
}
