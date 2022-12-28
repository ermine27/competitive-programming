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

// 内積
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
// 外積
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

// 射影
Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}

// 円と直線の交点
// wip
// ・交点がある前提になっているので、円と直線が接しない場合は-nanを返す。
// ・交点が1つの場合は同じ座標を2回返す。
pair<Point, Point> getCrossPoints(Circle c, Line l) {
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
    double base = sqrt(c.r * c.r - norm(pr - c.c));
    return make_pair(pr + e * base, pr - e * base);
}

int main() {
    Point p;
    double r;
    cin >> p.x >> p.y >> r;
    Circle c(p, r);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        Point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        Line l(p1, p2);
        tie(p1, p2) = getCrossPoints(c, l);
        if (p2 < p1)
            swap(p1, p2);
        printf("%.7f %.7f %.7f %.7f\n", p1.x, p1.y, p2.x, p2.y);
    }

    return 0;
}
