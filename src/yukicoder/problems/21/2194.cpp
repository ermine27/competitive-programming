#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    bool ok = false;

    for (long long i = 1; i <= 200000; i++) {
        long long d = i * a;
        if (d > b)
            d -= b;
        if (d == c) {
            cout << i << endl;
            ok = true;
        }
    }

    if (!ok) {
        cout << -1 << endl;
    }

    return 0;
}
