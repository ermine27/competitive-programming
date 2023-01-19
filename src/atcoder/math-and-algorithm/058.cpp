#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, d;
    cin >> n >> x >> y;
    d = abs(x) + abs(y);
    cout << (n >= d && (n - d) % 2 == 0 ? "Yes" : "No") << endl;
    return 0;
}
