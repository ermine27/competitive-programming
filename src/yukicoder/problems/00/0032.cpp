#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, m, n;
    cin >> l >> m >> n;

    m += n / 25;
    n %= 25;
    l += m / 4;
    m %= 4;
    l %= 10;

    cout << l + m + n << endl;
    return 0;
}
