#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point &p) { return Point(x - p.x, y - p.y); }
    Point operator*(double k) { return Point(x * k, y * k); }
    Point operator/(double k) { return Point(x / k, y / k); }
    double abs() { return sqrt(norm()); }
    double norm() { return x * x + y * y; }
    void print() { printf("%.10f %.10f\n", x, y); }
};

struct Circle {
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};

int circleIntersect(Circle c1, Circle c2) {
    double d = (c1.c - c2.c).abs();

    if (d < abs(c1.r - c2.r))
        return 0;
    if (d == abs(c1.r - c2.r))
        return 1;
    if (d > c1.r + c2.r)
        return 4;
    if (d == c1.r + c2.r)
        return 3;
    return 2;
}

int main() {
    Point p1, p2;
    double r1, r2;
    cin >> p1.x >> p1.y >> r1 >> p2.x >> p2.y >> r2;
    Circle c1(p1, r1), c2(p2, r2);
    cout << circleIntersect(c1, c2) + 1 << endl;
    return 0;
}
