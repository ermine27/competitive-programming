#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, d, x, y, rad;
    cin >> a >> b >> d;

    rad = d * M_PI / 180;
    x = a * cos(rad) - b * sin(rad);
    y = a * sin(rad) + b * cos(rad);

    cout << fixed << setprecision(10);
    cout << x << ' ' << y;
    return 0;
}
