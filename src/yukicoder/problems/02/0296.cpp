#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h, m, t;
    cin >> n >> h >> m >> t;
    long long d = (n - 1LL) * t % 1440;
    m += d;
    if (m >= 60) {
        h = (h + m / 60) % 24;
        m %= 60;
    }
    cout << h << endl << m << endl;
    return 0;
}
