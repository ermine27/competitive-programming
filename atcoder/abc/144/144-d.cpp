#include <bits/stdc++.h>
using namespace std;

template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
#define deg2rad(x) (x*M_PI/180.0)
#define rad2deg(x) (x*180.0/M_PI)

int main() {
    double a, b, x, h, d;
    in(a, b, x);

    // 3d --> 2d
    x /= a;

    h = a * b / 2;

    // Angle is greater than 45 degrees.
    if (x < h) {
        d = atan(pow(b, 2) / (2 * x));

    // Angle is 45 degrees or less than.
    } else {
        d = atan(2 * (a * b - x) / pow(a, 2));
    }

    d = rad2deg(d);

    cout << fixed << setprecision(10);
    out(d);
    return 0;
}
