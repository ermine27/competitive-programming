#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(double k) { return Point(x * k, y * k); }
    Point operator/(double k) { return Point(x / k, y / k); }
    bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
};

inline double norm(Point p) { return p.x * p.x + p.y * p.y; }
inline double abs(Point p) { return sqrt(norm(p)); }

// 線分
struct Segment {
    Point p1, p2;
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};

// 直線
using Line = Segment;

struct Circle {
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};

// ベクトル
using Vector = Point;

double arg(Vector p) { return atan2(p.y, p.x); }
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) * a); }

// ２つの円の交点
// wip
// ・交点がある前提になっているので、円と直線が接しない場合は-nanを返す。
// ・交点が1つの場合は同じ座標を2回返す。
pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
    double d = abs(c1.c - c2.c);
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

int main() {
    double c1x, c1y, c1r, c2x, c2y, c2r;
    cin >> c1x >> c1y >> c1r >> c2x >> c2y >> c2r;
    Circle c1(Point(c1x, c1y), c1r), c2(Point(c2x, c2y), c2r);
    Point p1, p2;
    tie(p1, p2) = getCrossPoints(c1, c2);
    if (p2 < p1)
        swap(p1, p2);
    printf("%.7f %.7f %.7f %.7f\n", p1.x, p1.y, p2.x, p2.y);
    return 0;
}
