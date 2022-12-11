#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    bool ok = true;
    if (n < 2)
        ok = false;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0)
            ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
