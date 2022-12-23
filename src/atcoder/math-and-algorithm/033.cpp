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
};

struct Segment {
    Point p1, p2;
    Segment();
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};
using Line = Segment;

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

double getDistanceLP(Line l, Point p) {
    Point s = l.p2 - l.p1;
    return abs(cross(l.p2 - l.p1, p - l.p1) / s.abs());
}
double getDistanceSP(Segment s, Point p) {
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0)
        return (p - s.p1).abs();
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0)
        return (p - s.p2).abs();
    return getDistanceLP(s, p);
}

int main() {
    vector<Point> p(3);
    for (int i = 0; i < 3; i++) cin >> p[i].x >> p[i].y;
    Segment s(p[1], p[2]);
    printf("%.10f\n", getDistanceSP(s, p[0]));
    return 0;
}
