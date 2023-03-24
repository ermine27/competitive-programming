#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, int c, int d) {
    if (a == c && b == d)
        return 0;
    if (a + b == c + d || a - b == c - d || abs(a - c) + abs(b - d) <= 3)
        return 1;
    if (abs(a - c) + abs(b - d) <= 6 || (a + b) % 2 == (c + d) % 2 || abs((a + b) - (c + d)) <= 3 ||
        abs((a - b) - (c - d)) <= 3)
        return 2;
    return 3;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << solve(a, b, c, d) << endl;
    return 0;
}
