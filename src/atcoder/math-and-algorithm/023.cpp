#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b, r, bs = 0, rs = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b >> r;
        bs += b;
        rs += r;
    }

    cout << setprecision(10) << (double)bs / n + (double)rs / n << endl;
    return 0;
}
